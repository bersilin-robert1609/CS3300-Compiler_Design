//
// Generated by JTB 1.3.2
//

package visitor;
import syntaxtree.*;
import java.util.*;

/**
 * Provides default methods which visit each node in the tree in depth-first
 * order.  Your visitors may extend this class.
 */
public class GJDepthFirst<R,A> implements GJVisitor<R,A> {
   //
   // Auto class visitors--probably don't need to be overridden.
  
	 public R visit(NodeList n, A argu) {
      R _ret=null;
      int _count=0;
      for ( Enumeration<Node> e = n.elements(); e.hasMoreElements(); ) {
         e.nextElement().accept(this,argu);
         _count++;
      }
      return _ret;
   }

   public R visit(NodeListOptional n, A argu) {
      if ( n.present() ) {
         R _ret=null;
         int _count=0;
         for ( Enumeration<Node> e = n.elements(); e.hasMoreElements(); ) {
            e.nextElement().accept(this,argu);
            _count++;
         }
         return _ret;
      }
      else
         return null;
   }

   public R visit(NodeOptional n, A argu) {
      if ( n.present() )
         return n.node.accept(this,argu);
      else
         return null;
   }

   public R visit(NodeSequence n, A argu) {
      R _ret=null;
      int _count=0;
      for ( Enumeration<Node> e = n.elements(); e.hasMoreElements(); ) {
         e.nextElement().accept(this,argu);
         _count++;
      }
      return _ret;
   }

   public R visit(NodeToken n, A argu) { return (R)n.tokenImage; }

   //
   // User-generated visitor methods below
   //

   // Hash Map of class Info
   public HashMap<String, ClassData> classMap = new HashMap<String, ClassData>();
   // build variable
   public boolean build = true;
   // debug variable
   public boolean debug = false;
   // free temp number;
   public int tempNumber = 0;
   // temporary arguments tempValue list
   public ArrayList<Integer> argumentsTempValues = new ArrayList<Integer>();
   // free label number
   public int labelNumber = 0;

   public int getNextTemp() {return tempNumber++;}
   public int getNextLabel() {return labelNumber++;}

   public int createObject(int temp, String className)
   {
      ClassData classData = classMap.get(className);
      int methodTableSize = classData.getMethodTableSize();
      int methodTableTemp = getNextTemp();
      System.out.println("MOVE TEMP " + methodTableTemp + " HALLOCATE " + methodTableSize);
      
      for(int i = 0; i<classData.methodList.size(); i++)
      {
         MethodData methodData = classData.methodDataMap.get(classData.methodList.get(i));
         String label = className + "_" + methodData.methodName;
         int labelTemp = getNextTemp();
         System.out.println("MOVE TEMP " + labelTemp + " " + label);
         System.out.println("HSTORE TEMP " + methodTableTemp + " " + i*4 + " TEMP " + labelTemp);
      }

      int classTableSize = classData.getVariableTableSize();
      classTableSize += 4;
      int classTableTemp = getNextTemp();
      System.out.println("MOVE TEMP " + classTableTemp + " HALLOCATE " + classTableSize);
      System.out.println("HSTORE TEMP " + classTableTemp + " 0 TEMP " + methodTableTemp);

      if(classData.parentName != null) 
      {
         int parentTemp = getNextTemp();
         if(debug) System.out.println("\nALLOCATE Parent Class " + classData.parentName + "\n");
         parentTemp = createObject(parentTemp, classData.parentName);
         System.out.println("HSTORE TEMP " + classTableTemp + " 4 TEMP " + parentTemp);
      }
      System.out.println("MOVE TEMP " + temp + " TEMP " + classTableTemp);

      return temp;
   }

   public int findIdentifierValue(int temp, String id, CMI cmi)
   {
      String className = cmi.className;
      String methodName = cmi.methodName;
      ClassData classData = classMap.get(className);
      MethodData methodData = classData.methodDataMap.get(methodName);

      int offset = methodData.getVarTempValue(id);
      if(offset != -1)
      {
         System.out.println("MOVE TEMP " + temp + " TEMP " + offset);
      }
      else if(classData.variableOffset.containsKey(id))
      {
         offset = classData.variableOffset.get(id);
         System.out.println("HLOAD TEMP " + temp + " TEMP 0 " + offset);
      }
      else 
      {
         while(classData.parentName != null)
         {
            classData = classMap.get(classData.parentName);
            int newTemp = getNextTemp();
            System.out.println("HLOAD TEMP " + newTemp + " TEMP 0 4");
            if(classData.variableOffset.containsKey(id))
            {
               offset = classData.variableOffset.get(id);
               System.out.println("HLOAD TEMP " + temp + " TEMP " + newTemp + " " + offset);
               break;
            }
         }
      }
      return temp;
   }

   public int storeIdentifierValue(String id, CMI cmi, int exprTemp)
   {
      String className = cmi.className;
      String methodName = cmi.methodName;
      ClassData classData = classMap.get(className);
      MethodData methodData = classData.methodDataMap.get(methodName);

      int offset = methodData.getVarTempValue(id);
      if(offset != -1)
      {
         System.out.println("MOVE TEMP " + offset + " TEMP " + exprTemp);
         return exprTemp;
      }
      else if(classData.variableOffset.containsKey(id))
      {
         offset = classData.variableOffset.get(id);
         System.out.println("HSTORE TEMP 0 " + offset + " TEMP " + exprTemp);
      }
      else{
         while(classData.parentName != null)
         {
            classData = classMap.get(classData.parentName);
            int newTemp = getNextTemp();
            System.out.println("HLOAD TEMP " + newTemp + " TEMP 0 4");
            if(classData.variableOffset.containsKey(id))
            {
               offset = classData.variableOffset.get(id);
               System.out.println("HSTORE TEMP " + newTemp + " " + offset + " TEMP " + exprTemp);
               break;
            }
         }
      }
      return -1;
   }

   public String findType(String id, CMI cmi)
   {
      String className = cmi.className;
      String methodName = cmi.methodName;
      ClassData classData = classMap.get(className);
      MethodData methodData = classData.methodDataMap.get(methodName);

      if(methodData.variableType.containsKey(id)) return methodData.variableType.get(id);
      else if(methodData.parameterType.containsKey(id)) return methodData.parameterType.get(id);
      else if(classData.variableMap.containsKey(id)) return classData.variableMap.get(id);
      else
      {
         while(classData.parentName != null)
         {
            classData = classMap.get(classData.parentName);
            if(classData.variableMap.containsKey(id)) return classData.variableMap.get(id);
         }
      }
      return null;
   }

   /**
    * f0 -> MainClass()
    * f1 -> ( TypeDeclaration() )*
    * f2 -> <EOF>
    */
   public R visit(Goal n, A argu) 
   {
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      if(debug)
      {
         for(String key : classMap.keySet()) {
            ClassData classData = classMap.get(key);
            classData.printClassData();
         }
      }
      build = false;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return null;
   }

   /**
    * f0 -> "class"
    * f1 -> Identifier()
    * f2 -> "{"
    * f3 -> "public"
    * f4 -> "static"
    * f5 -> "void"
    * f6 -> "main"
    * f7 -> "("
    * f8 -> "String"
    * f9 -> "["
    * f10 -> "]"
    * f11 -> Identifier()
    * f12 -> ")"
    * f13 -> "{"
    * f14 -> PrintStatement()
    * f15 -> "}"
    * f16 -> "}"
    */
   public R visit(MainClass n, A argu) 
   {
      if(!build) System.out.println("MAIN");
      ReturnClass rc = (ReturnClass) n.f1.accept(this, argu);
      String className = rc.identifier;
      String methodName = n.f6.accept(this, argu).toString();
      if(build)
      {
         ClassData classData = new ClassData(className, null);
         classMap.put(className, classData);
         MethodData methodData = new MethodData(methodName, "void");
         classData.addMethod(methodName, methodData);
      }
      if(!build) n.f14.accept(this, argu);
      if(!build) System.out.println("END");
      return null;
   }

   /**
    * f0 -> ClassDeclaration()
    *       | ClassExtendsDeclaration()
    */
   public R visit(TypeDeclaration n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "class"
    * f1 -> Identifier()
    * f2 -> "{"
    * f3 -> ( VarDeclaration() )*
    * f4 -> ( MethodDeclaration() )*
    * f5 -> "}"
    */
   public R visit(ClassDeclaration n, A argu) 
   {
      ReturnClass rc = (ReturnClass)n.f1.accept(this, argu);
      String className = rc.identifier;
      if(build)
      {
         ClassData classData = new ClassData(className, null);
         classMap.put(className, classData);
      }
      CMI cmi = new CMI();
      cmi.className = className;
      cmi.methodName = null;
      cmi.com = 0;

      argu = (A)cmi;
      if(build) n.f3.accept(this, argu);
      n.f4.accept(this, argu);
      return null;
   }

   /**
    * f0 -> "class"
    * f1 -> Identifier()
    * f2 -> "extends"
    * f3 -> Identifier()
    * f4 -> "{"
    * f5 -> ( VarDeclaration() )*
    * f6 -> ( MethodDeclaration() )*
    * f7 -> "}"
    */
   public R visit(ClassExtendsDeclaration n, A argu) 
   {
      ReturnClass rc1 = (ReturnClass)n.f1.accept(this, argu);
      String className = rc1.identifier;
      ReturnClass rc2 = (ReturnClass)n.f3.accept(this, argu);
      String parentName = rc2.identifier;
      if(build)
      {
         ClassData classData = new ClassData(className, parentName);
         classMap.put(className, classData);
      }
      CMI cmi = new CMI();
      cmi.className = className;
      cmi.methodName = null;
      cmi.com = 0;

      argu = (A)cmi;
      if(build) n.f5.accept(this, argu);
      n.f6.accept(this, argu);
      return null;
   }

   /**
    * f0 -> Type()
    * f1 -> Identifier()
    * f2 -> ";"
    */
   public R visit(VarDeclaration n, A argu) 
   {
      ReturnClass rc = (ReturnClass)n.f0.accept(this, argu);
      String type = rc.identifier;
      ReturnClass rc1 = (ReturnClass)n.f1.accept(this, argu);
      String varName = rc1.identifier;
      CMI cmi = (CMI)argu;
      if(cmi.com == 0)
      {
         ClassData classData = classMap.get(cmi.className);
         classData.addVariable(varName, type);
      }
      else
      {
         ClassData classData = classMap.get(cmi.className);
         MethodData methodData = classData.methodDataMap.get(cmi.methodName);
         methodData.addVariable(varName, type);
      }
      return null;
   }

   /**
    * f0 -> "public"
    * f1 -> Type()
    * f2 -> Identifier()
    * f3 -> "("
    * f4 -> ( FormalParameterList() )?
    * f5 -> ")"
    * f6 -> "{"
    * f7 -> ( VarDeclaration() )*
    * f8 -> ( Statement() )*
    * f9 -> "return"
    * f10 -> Expression()
    * f11 -> ";"
    * f12 -> "}"
    */
   public R visit(MethodDeclaration n, A argu) 
   {
      ReturnClass rcreturn = (ReturnClass)n.f1.accept(this, argu);
      String returnType = rcreturn.identifier;
      ReturnClass rc = (ReturnClass)n.f2.accept(this, argu);
      String methodName = rc.identifier;

      CMI cmi = (CMI)argu;
      ClassData classData = classMap.get(cmi.className);
      MethodData methodData;
      if(build)
      {
         methodData = new MethodData(methodName, returnType);
         classData.addMethod(methodName, methodData);
      }
      else methodData = classData.methodDataMap.get(methodName);

      cmi.methodName = methodName;
      cmi.com = 1;

      if(build) n.f4.accept(this, argu);
      String label = cmi.className + "_" + cmi.methodName;
      int parameterCount = methodData.parameterCount;

      if(!build) System.out.println(label + " [" + (parameterCount+1) + "]");
      if(build) n.f7.accept(this, argu);

      tempNumber = methodData.parameterCount + 1 + methodData.variableCount;
      if(!build) System.out.println("BEGIN");

      if(!build) n.f8.accept(this, argu);

      if(!build) 
      {
         ReturnClass rc2 = (ReturnClass)n.f10.accept(this, argu);
         System.out.println("RETURN TEMP " + rc2.tempValue);
      }
      if(!build) System.out.println("END");
      tempNumber = 0;
      return null;
   }

   /**
    * f0 -> FormalParameter()
    * f1 -> ( FormalParameterRest() )*
    */
   public R visit(FormalParameterList n, A argu) {
		/* YOUR CODE HERE */

      R _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Type()
    * f1 -> Identifier()
    */
   public R visit(FormalParameter n, A argu) 
   {
      ReturnClass rc = (ReturnClass)n.f0.accept(this, argu);
      String type = rc.identifier;
      ReturnClass rc1 = (ReturnClass)n.f1.accept(this, argu);
      String parName = rc1.identifier;
      CMI cmi = (CMI)argu;
      ClassData classData = classMap.get(cmi.className);
      MethodData methodData = classData.methodDataMap.get(cmi.methodName);
      methodData.addParameter(parName, type);
      return null;
   }

   /**
    * f0 -> ","
    * f1 -> FormalParameter()
    */
   public R visit(FormalParameterRest n, A argu) {
		/* YOUR CODE HERE */

      R _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ArrayType()
    *       | BooleanType()
    *       | IntegerType()
    *       | Identifier()
    */
   public R visit(Type n, A argu) 
   {
      R _ret = n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "int"
    * f1 -> "["
    * f2 -> "]"
    */
   public R visit(ArrayType n, A argu) 
   {
      ReturnClass rc = new ReturnClass();
      rc.identifier = "int[]";
      return (R)rc;
   }

   /**
    * f0 -> "boolean"
    */
   public R visit(BooleanType n, A argu) 
   {
      ReturnClass rc = new ReturnClass();
      rc.identifier = "boolean";
      return (R)rc;
   }

   /**
    * f0 -> "int"
    */
   public R visit(IntegerType n, A argu) 
   {
      ReturnClass rc = new ReturnClass();
      rc.identifier = "int";
      return (R)rc;
   }

   /**
    * f0 -> Block()
    *       | AssignmentStatement()
    *       | ArrayAssignmentStatement()
    *       | IfStatement()
    *       | WhileStatement()
    *       | PrintStatement()
    */
   public R visit(Statement n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "{"
    * f1 -> ( Statement() )*
    * f2 -> "}"
    */
   public R visit(Block n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      n.f2.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> Identifier()
    * f1 -> "="
    * f2 -> Expression()
    * f3 -> ";"
    */
   public R visit(AssignmentStatement n, A argu) 
   {
      ReturnClass rc = (ReturnClass)n.f0.accept(this, argu);
      String identifier = rc.identifier;
      ReturnClass rce = (ReturnClass)n.f2.accept(this, argu);
      int exprTemp = rce.tempValue;

      int tempAddr = storeIdentifierValue(identifier, (CMI)argu, exprTemp);
      return null;
   }

   /**
    * f0 -> Identifier()
    * f1 -> "["
    * f2 -> Expression()
    * f3 -> "]"
    * f4 -> "="
    * f5 -> Expression()
    * f6 -> ";"
    */
   public R visit(ArrayAssignmentStatement n, A argu) 
   {
      if(debug) System.out.println("\nArrayAssignmentStatement\n");

      ReturnClass rc = (ReturnClass)n.f0.accept(this, argu);
      String identifier = rc.identifier;

      ReturnClass rce1 = (ReturnClass)n.f2.accept(this, argu);
      int accessPoint = rce1.tempValue;

      int oneTemp = getNextTemp();
      System.out.println("MOVE TEMP " + oneTemp + " 1");
      int fourTemp = getNextTemp();
      System.out.println("MOVE TEMP " + fourTemp + " 4");
      int added1Temp = getNextTemp();
      System.out.println("MOVE TEMP " + added1Temp + " PLUS TEMP " + accessPoint + " TEMP " + oneTemp);
      int multTemp = getNextTemp();
      System.out.println("MOVE TEMP " + multTemp + " TIMES TEMP " + added1Temp + " TEMP " + fourTemp);
      
      int arrayAddr = getNextTemp();
      arrayAddr = findIdentifierValue(arrayAddr, identifier, (CMI)argu);

      int actualAddr = getNextTemp();
      System.out.println("MOVE TEMP " + actualAddr + " PLUS TEMP " + arrayAddr + " TEMP " + multTemp);

      ReturnClass rce2 = (ReturnClass)n.f5.accept(this, argu);
      int exprTemp = rce2.tempValue;
      System.out.println("HSTORE TEMP " + actualAddr + " 0" + " TEMP " + exprTemp);

      return null;
   }

   /**
    * f0 -> IfthenElseStatement()
    *       | IfthenStatement()
    */
   public R visit(IfStatement n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> "if"
    * f1 -> "("
    * f2 -> Expression()
    * f3 -> ")"
    * f4 -> Statement()
    */
   public R visit(IfthenStatement n, A argu) 
   {
		if(debug) System.out.println("\nIfthenStatement\n");

      int endLabel = getNextLabel();
      
      ReturnClass rc = (ReturnClass)n.f2.accept(this, argu);
      int exprTemp = rc.tempValue;

      System.out.println("CJUMP TEMP " + exprTemp + " L" + endLabel);
      n.f4.accept(this, argu);
      System.out.println("L" + endLabel);
      System.out.println("NOOP");
      return null;
   }

   /**
    * f0 -> "if"
    * f1 -> "("
    * f2 -> Expression()
    * f3 -> ")"
    * f4 -> Statement()
    * f5 -> "else"
    * f6 -> Statement()
    */
   public R visit(IfthenElseStatement n, A argu) 
   {
      if(debug) System.out.println("\nIfthenElseStatement\n");

      int elseLabel = getNextLabel();
      int endLabel = getNextLabel();
      
      ReturnClass rc = (ReturnClass)n.f2.accept(this, argu);
      int exprTemp = rc.tempValue;

      System.out.println("CJUMP TEMP " + exprTemp + " L" + elseLabel);
      n.f4.accept(this, argu);
      System.out.println("JUMP L" + endLabel);
      System.out.println("L" + elseLabel);
      System.out.println("NOOP");
      n.f6.accept(this, argu);
      System.out.println("L" + endLabel);
      System.out.println("NOOP");
      return null;
   }

   /**
    * f0 -> "while"
    * f1 -> "("
    * f2 -> Expression()
    * f3 -> ")"
    * f4 -> Statement()
    */
   public R visit(WhileStatement n, A argu) 
   {
      if(debug) System.out.println("\nWhileStatement\n");

		int label = getNextLabel();
      int jumpLabel = getNextLabel();
      System.out.println("L" + label);
      System.out.println("NOOP");
      
      ReturnClass rc = (ReturnClass)n.f2.accept(this, argu);
      int exprTemp = rc.tempValue;

      System.out.println("CJUMP TEMP " + exprTemp + " L" + jumpLabel);
      n.f4.accept(this, argu);
      System.out.println("JUMP L" + label);
      System.out.println("L" + jumpLabel);
      System.out.println("NOOP");
      return null;
   }

   /**
    * f0 -> "System.out.println"
    * f1 -> "("
    * f2 -> Expression()
    * f3 -> ")"
    * f4 -> ";"
    */
   public R visit(PrintStatement n, A argu) 
   {
      ReturnClass rc = (ReturnClass)n.f2.accept(this, argu);
      System.out.println("PRINT TEMP " + rc.tempValue);
      return null;
   }

   /**
    * f0 -> OrExpression()
    *       | AndExpression()
    *       | CompareExpression()
    *       | neqExpression()
    *       | PlusExpression()
    *       | MinusExpression()
    *       | TimesExpression()
    *       | DivExpression()
    *       | ArrayLookup()
    *       | ArrayLength()
    *       | MessageSend()
    *       | PrimaryExpression()
    */
   public R visit(Expression n, A argu) 
   {
      return n.f0.accept(this, argu);
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "&&"
    * f2 -> PrimaryExpression()
    */
   public R visit(AndExpression n, A argu) 
   {
      if(debug) System.out.println("\nAndExpression\n");

      ReturnClass rc1 = (ReturnClass)n.f0.accept(this, argu);
      ReturnClass rc2 = (ReturnClass)n.f2.accept(this, argu);
      int newTemp = getNextTemp();
      System.out.println("MOVE TEMP " + newTemp + " TIMES TEMP " + rc1.tempValue + " TEMP " + rc2.tempValue);
      // 0 * 0 = 0, 0 * 1 = 0, 1 * 0 = 0, 1 * 1 = 1

      rc1.tempValue = newTemp;
      return (R)rc1;
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "||"
    * f2 -> PrimaryExpression()
    */
   public R visit(OrExpression n, A argu) 
   {
      if(debug) System.out.println("\nOrExpression\n");

      ReturnClass rc1 = (ReturnClass)n.f0.accept(this, argu);
      ReturnClass rc2 = (ReturnClass)n.f2.accept(this, argu);
      int newTemp = getNextTemp();
      System.out.println("MOVE TEMP " + newTemp + " PLUS TEMP " + rc1.tempValue + " TEMP " + rc2.tempValue);
      int newTemp2 = getNextTemp();
      System.out.println("MOVE TEMP " + newTemp + " TIMES TEMP " + rc1.tempValue + " TEMP " + rc2.tempValue);
      int finalTemp = getNextTemp();
      System.out.println("MOVE TEMP " + finalTemp + " MINUS TEMP " + newTemp + " TEMP " + newTemp2);
      // 0 + 0 = 0, 0 + 1 = 1, 1 + 0 = 1, 1 + 1 = 1 
      // a or b == a + b - a * b

      rc1.tempValue = finalTemp;
      return (R)rc1;
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "<="
    * f2 -> PrimaryExpression()
    */
   public R visit(CompareExpression n, A argu) 
   {
      if(debug) System.out.println("\nLessOrEqualExpression\n");

      ReturnClass rc1 = (ReturnClass)n.f0.accept(this, argu);
      ReturnClass rc2 = (ReturnClass)n.f2.accept(this, argu);
      int newTemp = getNextTemp();
      System.out.println("MOVE TEMP " + newTemp + " LE TEMP " + rc1.tempValue + " TEMP " + rc2.tempValue);

      rc1.tempValue = newTemp;
      return (R)rc1;
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "!="
    * f2 -> PrimaryExpression()
    */
   public R visit(neqExpression n, A argu) 
   {
      if(debug) System.out.println("\nNotEqualExpression\n");

      ReturnClass rc1 = (ReturnClass)n.f0.accept(this, argu);
      ReturnClass rc2 = (ReturnClass)n.f2.accept(this, argu);
      int newTemp = getNextTemp();
      System.out.println("MOVE TEMP " + newTemp + " NE TEMP " + rc1.tempValue + " TEMP " + rc2.tempValue);

      rc1.tempValue = newTemp;
      return (R)rc1;
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "+"
    * f2 -> PrimaryExpression()
    */
   public R visit(PlusExpression n, A argu) 
   {
      if(debug) System.out.println("\nPlusExpression\n");

      ReturnClass rc1 = (ReturnClass)n.f0.accept(this, argu);
      ReturnClass rc2 = (ReturnClass)n.f2.accept(this, argu);
      int newTemp = getNextTemp();
      System.out.println("MOVE TEMP " + newTemp + " PLUS TEMP " + rc1.tempValue + " TEMP " + rc2.tempValue);

      rc1.tempValue = newTemp;
      return (R)rc1;
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "-"
    * f2 -> PrimaryExpression()
    */
   public R visit(MinusExpression n, A argu) 
   {
		if(debug) System.out.println("\nMinusExpression\n");

      ReturnClass rc1 = (ReturnClass)n.f0.accept(this, argu);
      ReturnClass rc2 = (ReturnClass)n.f2.accept(this, argu);
      int newTemp = getNextTemp();
      System.out.println("MOVE TEMP " + newTemp + " MINUS TEMP " + rc1.tempValue + " TEMP " + rc2.tempValue);

      rc1.tempValue = newTemp;
      return (R)rc1;
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "*"
    * f2 -> PrimaryExpression()
    */
   public R visit(TimesExpression n, A argu) 
   {
      if(debug) System.out.println("\nTimesExpression\n");

      ReturnClass rc1 = (ReturnClass)n.f0.accept(this, argu);
      ReturnClass rc2 = (ReturnClass)n.f2.accept(this, argu);
      int newTemp = getNextTemp();
      System.out.println("MOVE TEMP " + newTemp + " TIMES TEMP " + rc1.tempValue + " TEMP " + rc2.tempValue);

      rc1.tempValue = newTemp;
      return (R)rc1;
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "/"
    * f2 -> PrimaryExpression()
    */
   public R visit(DivExpression n, A argu) 
   {
      if(debug) System.out.println("\nDivExpression\n");

      ReturnClass rc1 = (ReturnClass)n.f0.accept(this, argu);
      ReturnClass rc2 = (ReturnClass)n.f2.accept(this, argu);
      int newTemp = getNextTemp();
      System.out.println("MOVE TEMP " + newTemp + " DIV TEMP " + rc1.tempValue + " TEMP " + rc2.tempValue);

      rc1.tempValue = newTemp;
      return (R)rc1;
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "["
    * f2 -> PrimaryExpression()
    * f3 -> "]"
    */
   public R visit(ArrayLookup n, A argu) 
   {
      if(debug) System.out.println("\nArrayLookup\n");

      ReturnClass rc1 = (ReturnClass)n.f0.accept(this, argu);
      int arrayAddrTemp = rc1.tempValue;
      ReturnClass rc2 = (ReturnClass)n.f2.accept(this, argu);
      int accessPoint = rc2.tempValue;
      int oneTemp = getNextTemp();
      System.out.println("MOVE TEMP " + oneTemp + " 1");
      int fourTemp = getNextTemp();
      System.out.println("MOVE TEMP " + fourTemp + " 4");
      int added1Temp = getNextTemp();
      System.out.println("MOVE TEMP " + added1Temp + " PLUS TEMP " + accessPoint + " TEMP " + oneTemp);
      int multTemp = getNextTemp();
      System.out.println("MOVE TEMP " + multTemp + " TIMES TEMP " + added1Temp + " TEMP " + fourTemp);
      int newArrayAddrTemp = getNextTemp();
      System.out.println("MOVE TEMP " + newArrayAddrTemp + " PLUS TEMP " + arrayAddrTemp + " TEMP " + multTemp);
      int newTemp = getNextTemp();
      System.out.println("HLOAD TEMP " + newTemp + " TEMP " + newArrayAddrTemp + " 0");

      ReturnClass rc = new ReturnClass();
      rc.tempValue = newTemp;
      rc.type = "int";
      rc.tempOrIdentifier = 0;
      return (R)rc;
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "."
    * f2 -> "length"
    */
   public R visit(ArrayLength n, A argu) 
   {
      if(debug) System.out.println("\nArrayLength\n");

      ReturnClass rc = (ReturnClass)n.f0.accept(this, argu);
      int arrayAddrTemp = rc.tempValue;
      int newTemp = getNextTemp();
      System.out.println("HLOAD TEMP " + newTemp + " TEMP " + arrayAddrTemp + " 0");
      rc.tempValue = newTemp;
      return (R)rc;
   }

   /**
    * f0 -> PrimaryExpression()
    * f1 -> "."
    * f2 -> Identifier()
    * f3 -> "("
    * f4 -> ( ExpressionList() )?
    * f5 -> ")"
    */
   public R visit(MessageSend n, A argu) 
   {
		ReturnClass rcp = (ReturnClass)n.f0.accept(this, argu);
      String className = rcp.type;
      ReturnClass rci = (ReturnClass)n.f2.accept(this, argu);
      String methodName = rci.identifier;

      ClassData classData = classMap.get(className);

      if(debug) System.out.println("\nMethod Call: " + className + " " + methodName + "\n");

      int newTemp = getNextTemp();
      int newTemp2 = getNextTemp();
      int classTableTemp = rcp.tempValue;
      while(className != null)
      {
         if(classData.methodOffset.containsKey(methodName))
         {
         //    System.out.println("MethodName: " + methodName + " ClassName: " + className);
            System.out.println("HLOAD TEMP " + newTemp + " TEMP " + classTableTemp + " 0");
            System.out.println("HLOAD TEMP " + newTemp2 + " TEMP " + newTemp + " " + classData.methodOffset.get(methodName));
            break;
         }
         int newClassTableTemp = getNextTemp();
         System.out.println("HLOAD TEMP " + newClassTableTemp + " TEMP " + classTableTemp + " 4");
         classTableTemp = newClassTableTemp;
         className = classData.parentName;
         classData = classMap.get(className);
      }

      ArrayList<Integer> tempValues = new ArrayList<Integer>();
      for(int i = 0; i<argumentsTempValues.size(); i++) tempValues.add(argumentsTempValues.get(i));

      argumentsTempValues.clear();
      argumentsTempValues.add(rcp.tempValue);
      n.f4.accept(this, argu);

      int returnTemp = getNextTemp();
      System.out.print("MOVE TEMP " + returnTemp + " CALL TEMP " + newTemp2 + " (");
      for(int i=0; i<argumentsTempValues.size(); i++) System.out.print(" TEMP " + argumentsTempValues.get(i));
      System.out.println(" )");

      argumentsTempValues.clear();
      for(int i = 0; i<tempValues.size(); i++) argumentsTempValues.add(tempValues.get(i));

      ReturnClass rc = new ReturnClass();
      rc.tempValue = returnTemp;
      rc.tempOrIdentifier = 0;
      rc.type = classMap.get(className).methodDataMap.get(methodName).returnType;
      //System.out.println("Type Sent: " + rc.type);
      return (R)rc;
   }

   /**
    * f0 -> Expression()
    * f1 -> ( ExpressionRest() )*
    */
   public R visit(ExpressionList n, A argu) 
   {
      ReturnClass rc = (ReturnClass)n.f0.accept(this, argu);
      argumentsTempValues.add(rc.tempValue);
      n.f1.accept(this, argu);
      return (R)rc;
   }

   /**
    * f0 -> ","
    * f1 -> Expression()
    */
   public R visit(ExpressionRest n, A argu) 
   {
      ReturnClass rc = (ReturnClass)n.f1.accept(this, argu);
      argumentsTempValues.add(rc.tempValue);
      return (R)rc;
   }

   /**
    * f0 -> IntegerLiteral()                 //value in some temp
    *       | TrueLiteral()                  // 1 in some temp
    *       | FalseLiteral()                 // 0 in some temp
    *       | Identifier()
    *       | ThisExpression()               // 0
    *       | ArrayAllocationExpression()    // temp value of newly-created array of (size + 1) elements array[0] = size
    *       | AllocationExpression()         // temp value of newly-created object
    *       | NotExpression()                // 1 - value of expression in a temp
    *       | BracketExpression()            // value of expression in a temp
    */
   public R visit(PrimaryExpression n, A argu) 
   {
      ReturnClass rc = (ReturnClass)n.f0.accept(this, argu);

      if(rc.tempOrIdentifier == 1)
      {
         int newTemp = getNextTemp();
         newTemp = findIdentifierValue(newTemp, rc.identifier, (CMI)argu);
         String type = findType(rc.identifier, (CMI)argu);
         rc.tempValue = newTemp;
         rc.type = type;
      }

      rc.tempOrIdentifier = 0;
      return (R)rc;
   }

   /**
    * f0 -> <INTEGER_LITERAL>
    */
   public R visit(IntegerLiteral n, A argu)
   {
      if(debug) System.out.println("\nIntegerLiteral\n");

      R _ret = n.f0.accept(this, argu);
      String value = _ret.toString();
      int intTemp = getNextTemp();
      System.out.println("MOVE TEMP " + intTemp + " " + value);
      ReturnClass rc = new ReturnClass();
      rc.tempValue = intTemp;
      rc.tempOrIdentifier = 0;
      rc.numberValue = Integer.parseInt(value);
      return (R)rc;
   }

   /**
    * f0 -> "true"
    */
   public R visit(TrueLiteral n, A argu) 
   {
      if(debug) System.out.println("\nTrueLiteral\n");

      int trueTemp = getNextTemp();
      System.out.println("MOVE TEMP " + trueTemp + " 1");
      ReturnClass rc = new ReturnClass();
      rc.tempValue = trueTemp;
      rc.tempOrIdentifier = 0;
      return (R)rc;
   }

   /**
    * f0 -> "false"
    */
   public R visit(FalseLiteral n, A argu) 
   {
      if(debug) System.out.println("\nFalseLiteral\n");

      int falseTemp = getNextTemp();
      System.out.println("MOVE TEMP " + falseTemp + " 0");
      ReturnClass rc = new ReturnClass();
      rc.tempValue = falseTemp;
      rc.tempOrIdentifier = 0;
      return (R)rc;
   }

   /**
    * f0 -> <IDENTIFIER>
    */
   public R visit(Identifier n, A argu) 
   {
      ReturnClass rc = new ReturnClass();
      rc.identifier = n.f0.accept(this, argu).toString();
      rc.tempOrIdentifier = 1;
      return (R)rc;
   }

   /**
    * f0 -> "this"
    */
   public R visit(ThisExpression n, A argu) 
   {
      ReturnClass rc = new ReturnClass();
      rc.tempValue = 0;
      rc.tempOrIdentifier = 0;
      rc.type = ((CMI)argu).className;
      return (R)rc;
   }

   /**
    * f0 -> "new"
    * f1 -> "int"
    * f2 -> "["
    * f3 -> Expression()
    * f4 -> "]"
    */
   public R visit(ArrayAllocationExpression n, A argu) 
   {
      if(debug) System.out.println("\nArrayAllocationExpression\n");

      int oneTemp = getNextTemp();
      System.out.println("MOVE TEMP " + oneTemp + " 1");
      
      ReturnClass rc = (ReturnClass)n.f3.accept(this, argu);
      int exprTemp = rc.tempValue;

      int sizeTempSimple = getNextTemp();
      System.out.println("MOVE TEMP " + sizeTempSimple + " PLUS TEMP " + exprTemp + " TEMP " + oneTemp);
      int fourTemp = getNextTemp();
      System.out.println("MOVE TEMP " + fourTemp + " 4");
      int sizeTempExact = getNextTemp();
      System.out.println("MOVE TEMP " + sizeTempExact + " TIMES TEMP " + sizeTempSimple + " TEMP " + fourTemp);
      int addrTemp = getNextTemp();
      System.out.println("MOVE TEMP " + addrTemp + " HALLOCATE TEMP " + sizeTempExact);
      System.out.println("HSTORE TEMP " + addrTemp + " 0 TEMP " + exprTemp);
      int finalTemp = getNextTemp();
      System.out.println("MOVE TEMP " + finalTemp + " TEMP " + addrTemp);
      
      rc.tempValue = finalTemp;
      rc.type = "int[]";
      return (R)rc;
   }

   /**
    * f0 -> "new"
    * f1 -> Identifier()
    * f2 -> "("
    * f3 -> ")"
    */
   public R visit(AllocationExpression n, A argu) 
   {
      ReturnClass rc = (ReturnClass)n.f1.accept(this, argu);
      String className = rc.identifier;
      int objTemp = getNextTemp();
      if(debug) System.out.println("\nALLOCATE " + className + "\n");
      objTemp = createObject(objTemp, className);
      
      rc.tempValue = objTemp;
      rc.tempOrIdentifier = 2;
      rc.type = className;
      return (R)rc;
   }

   /**
    * f0 -> "!"
    * f1 -> Expression()
    */
   public R visit(NotExpression n, A argu) 
   {
      if(debug) System.out.println("\nNotExpression\n");

      int oneTemp = getNextTemp();
      System.out.println("MOVE TEMP " + oneTemp + " 1");
      
      ReturnClass rc = (ReturnClass)n.f1.accept(this, argu);
      int exprTemp = rc.tempValue;
      int notTemp = getNextTemp();
      System.out.println("MOVE TEMP " + notTemp + " MINUS TEMP " + oneTemp + " TEMP " + exprTemp);

      rc.tempValue = notTemp;
      return (R)rc;
   }

   /**
    * f0 -> "("
    * f1 -> Expression()
    * f2 -> ")"
    */
   public R visit(BracketExpression n, A argu) 
   {
      ReturnClass rc = (ReturnClass)n.f1.accept(this, argu);
      return (R)rc;
   }

      /**
    * f0 -> Identifier()
    * f1 -> ( IdentifierRest() )*
    */
    public R visit(IdentifierList n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> ","
    * f1 -> Identifier()
    */
   public R visit(IdentifierRest n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }
}

class ClassData
{
   public String className;
   public String parentName;
   public int variableCount;
   public int methodCount;
   public HashMap<String, String> variableMap;
   public HashMap<String, Integer> variableOffset;
   public HashMap<String, Integer> methodOffset;
   public HashMap<String, MethodData> methodDataMap;
   public ArrayList<String> methodList;
   public int varOffset;
   public int metOffset;

   public ClassData(String className, String parentName)
   {
      this.className = className;
      this.parentName = parentName;
      variableCount = 0;
      methodCount = 0;
      variableOffset = new HashMap<String, Integer>();
      methodOffset = new HashMap<String, Integer>();
      methodDataMap = new HashMap<String, MethodData>();
      methodList = new ArrayList<String>();
      variableMap = new HashMap<String, String>();
      varOffset = 8;
      metOffset = 0;
   }

   public void addVariable(String variableName, String type)
   {
      variableMap.put(variableName, type);
      variableOffset.put(variableName, varOffset);
      varOffset += 4;
      variableCount++;
   }

   public void addMethod(String methodName, MethodData methodData)
   {
      methodOffset.put(methodName, metOffset);
      methodDataMap.put(methodName, methodData);
      methodList.add(methodName);
      metOffset += 4;
      methodCount++;
   }

   public int getMethodTableSize() 
   {
      return 4*methodCount;
   }

   public int getVariableTableSize() 
   {
      return 4*(variableCount + 1);
   }

   public void printClassData()
   {
      System.out.println("Class Name: " + className);
      System.out.println("Parent Name: " + parentName);
      System.out.println("Class " + className + " Variable Count: " + variableCount);
      System.out.println("Variable Offset: " + variableOffset);
      System.out.println("Class " + className + " Method Count: " + methodCount);
      System.out.println("Method Offset: " + methodOffset);
      for(String methodName : methodDataMap.keySet())
      {
         System.out.println("Method Name: " + methodName);
         methodDataMap.get(methodName).printMethodData();
      }
      System.out.println("Class " + className + " Variable Table Size: " + getVariableTableSize());
      System.out.println("Class " + className + " Method Table Size: " + getMethodTableSize());
   }
}

class MethodData
{
   public String methodName;
   public String returnType;
   public int variableCount;
   public int parameterCount;
   public HashMap<String, String> variableType;
   public HashMap<String, String> parameterType;
   public HashMap<String, Integer> variableOffset;  // This gives the TEMP value directly for the variables
   public HashMap<String, Integer> parameterOffset; // This gives the TEMP value directly for the parameters
   public int varOffset; 
   public int parOffset;

   public MethodData(String methodName, String returnType)
   {
      this.methodName = methodName;
      this.returnType = returnType;
      variableCount = 0;
      parameterCount = 0;
      variableOffset = new HashMap<String, Integer>();
      parameterOffset = new HashMap<String, Integer>();
      variableType = new HashMap<String, String>();
      parameterType = new HashMap<String, String>();
      parOffset = 1;
      varOffset = 1;
   }

   public void addParameter(String parameterName, String type)
   {
      parameterType.put(parameterName, type);
      parameterOffset.put(parameterName, parOffset);
      parOffset++;
      varOffset = parOffset;
      parameterCount++;
   }

   public void addVariable(String variableName, String type)
   {
      variableType.put(variableName, type);
      variableOffset.put(variableName, varOffset);
      varOffset++;
      variableCount++;
   }

   public int getVarTempValue(String variableName)
   {
      if(variableOffset.containsKey(variableName))
         return variableOffset.get(variableName);

      if(parameterOffset.containsKey(variableName))
         return parameterOffset.get(variableName);

      return -1; //this tells us to check in class variables and parent class variables
   }

   public void printMethodData()
   {
      System.out.println("Method "+ methodName + " Parameter Count: " + parameterCount);
      System.out.println("Parameters: " + parameterOffset);
      System.out.println("Parameters: " + parameterType);
      System.out.println("Method "+ methodName + " Variable Count: " + variableCount);
      System.out.println("Variables: " + variableOffset);
      System.out.println("Variables: " + variableType);
   }
}

class CMI
{
   public String className;
   public String methodName;
   public int com;
}

class ReturnClass
{
   public int tempValue;
   public String identifier;
   public String type;
   public int numberValue;
   public int tempOrIdentifier; // 0 for temp, 1 for identifier, 2 for type && temp
}

