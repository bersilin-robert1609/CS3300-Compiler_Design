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
   //
	
	String destReg;
	int inArgs, outArgs;
	boolean printLabel;
	
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

   class SimpleExpReturn
   {
      public String type;
      public String label;
      public String reg;
      public int intVal;
   }

   class ExpReturn
   {
      public String type;
      public String op;
      public String reg1;
      public String simpleExpType;
      public String simpleExpReg;
      public int simpleExpIntVal;
      public String simpleExpLabel;
   }

   class ProcedureProperties
   {
      public String name;
      public int argCount;
      public int stackAlloc;
      public int maxArgsInCall;
   }

   LinkedHashMap<String, ProcedureProperties> procProps = new LinkedHashMap<String, ProcedureProperties>();
   boolean debug = false;

   public int printInit(String name, int argCount, int stackAlloc, int maxArgsInCall)
   {
      System.out.print(".text" + "\n" + ".globl " + name + "\n" + name + ":" + "\n");
      System.out.println("sw $fp, -8($sp)");
      
      int stackMovement = stackAlloc * 4;
      stackMovement += 8;
      stackMovement += ((maxArgsInCall - 4) * 4) > 0 ? ((maxArgsInCall - 4) * 4) : 0;

      System.out.println("move $fp, $sp");
      System.out.println("subu $sp, $sp, " + stackMovement);
      System.out.println("sw $ra, -4($fp)");
      return stackMovement;
   }

   public void putProcprops(String name, int argCount, int stackAlloc, int maxArgsInCall)
   {
      ProcedureProperties props = new ProcedureProperties();
      props.name = name;
      props.argCount = argCount;
      props.stackAlloc = stackAlloc;
      props.maxArgsInCall = maxArgsInCall;
      procProps.put(name, props);
   }

   public void printEnd(String name, int stackMovement)
   {
      System.out.println("lw $ra, -4($fp)");
      System.out.println("lw $fp, -8($fp)");
      System.out.println("addu $sp, $sp, " + stackMovement);
      System.out.println("j $ra");
      return;
   }

   public void printFuncs()
   {
      System.out.println(".text");
      System.out.println(".globl _halloc");
      System.out.println("_halloc:");
      System.out.println("li $v0, 9");
      System.out.println("syscall");
      System.out.println("j $ra");

      System.out.println(".text");
      System.out.println(".globl _print");
      System.out.println("_print:");
      System.out.println("li $v0, 1");
      System.out.println("syscall");
      System.out.println("la $a0, newl");
      System.out.println("li $v0, 4");
      System.out.println("syscall");
      System.out.println("j $ra");

      System.out.println(".data");
      System.out.println(".align   0");
      System.out.println("newl:    .asciiz \"\\n\"");
      System.out.println(".data");
      System.out.println(".align   0");
      System.out.println("str_er:  .asciiz \" ERROR: abnormal termination\\n\"");
   }
   //
   // User-generated visitor methods below
   //

   /**
    * f0 -> "MAIN"
    * f1 -> "["
    * f2 -> IntegerLiteral()
    * f3 -> "]"
    * f4 -> "["
    * f5 -> IntegerLiteral()
    * f6 -> "]"
    * f7 -> "["
    * f8 -> IntegerLiteral()
    * f9 -> "]"
    * f10 -> StmtList()
    * f11 -> "END"
    * f12 -> ( SpillInfo() )?
    * f13 -> ( Procedure() )*
    * f14 -> <EOF>
    */
   public R visit(Goal n, A argu) 
   {
      int argCount = Integer.parseInt(n.f2.accept(this, argu).toString());
      int stackAlloc = Integer.parseInt(n.f5.accept(this, argu).toString());
      int maxArgsInCall = Integer.parseInt(n.f8.accept(this, argu).toString());

      putProcprops("main", argCount, stackAlloc, maxArgsInCall);
      int stackMovement = printInit("main", argCount, stackAlloc, maxArgsInCall);
      
      String scope = "main";
      n.f10.accept(this, (A)scope);
      printEnd("main", stackMovement);
      n.f13.accept(this, argu);

      printFuncs();
      return null;
   }

   /**
    * f0 -> ( ( Label() )? Stmt() )*
    */
   public R visit(StmtList n, A argu) {
      R _ret=null;
      printLabel = true;
      n.f0.accept(this, argu);
      printLabel = false;
      return _ret;
   }

   /**
    * f0 -> Label()
    * f1 -> "["
    * f2 -> IntegerLiteral()
    * f3 -> "]"
    * f4 -> "["
    * f5 -> IntegerLiteral()
    * f6 -> "]"
    * f7 -> "["
    * f8 -> IntegerLiteral()
    * f9 -> "]"
    * f10 -> StmtList()
    * f11 -> "END"
    * f12 -> ( SpillInfo() )?
    */
   public R visit(Procedure n, A argu) 
   {
      String scope = n.f0.accept(this, argu).toString();
      int argCount = Integer.parseInt(n.f2.accept(this, argu).toString());
      int stackAlloc = Integer.parseInt(n.f5.accept(this, argu).toString());
      int maxArgsInCall = Integer.parseInt(n.f8.accept(this, argu).toString());
      
      putProcprops(scope, argCount, stackAlloc, maxArgsInCall);
      int stackMovement = printInit(scope, argCount, stackAlloc, maxArgsInCall);

      n.f10.accept(this, (A)scope);
      printEnd(scope, stackMovement);
      return null;
   }

   /**
    * f0 -> NoOpStmt()
    *       | ErrorStmt()
    *       | CJumpStmt()
    *       | JumpStmt()
    *       | HStoreStmt()
    *       | HLoadStmt()
    *       | MoveStmt()
    *       | PrintStmt()
    *       | ALoadStmt()
    *       | AStoreStmt()
    *       | PassArgStmt()
    *       | CallStmt()
    */
   public R visit(Stmt n, A argu) {
      R _ret=null;
      printLabel = false;
      n.f0.accept(this, argu);
      printLabel = true;
      return _ret;
   }

   /**
    * f0 -> "NOOP"
    */
   public R visit(NoOpStmt n, A argu) 
   {
      System.out.println("nop");
      return null;
   }

   /**
    * f0 -> "ERROR"
    */
   public R visit(ErrorStmt n, A argu) 
   {
      System.out.println("li $v0, 4");
      System.out.println("la $a0, str_er");
      System.out.println("syscall");
      System.out.println("li $v0, 10");
      System.out.println("syscall");
      return null;
   }

   /**
    * f0 -> "CJUMP"
    * f1 -> Reg()
    * f2 -> Label()
    */
   public R visit(CJumpStmt n, A argu) 
   {
      String reg = n.f1.accept(this, argu).toString();
      String label = n.f2.accept(this, argu).toString();
      System.out.println("beqz " + reg + ", " + label);
      return null;
   }

   /**
    * f0 -> "JUMP"
    * f1 -> Label()
    */
   public R visit(JumpStmt n, A argu) 
   {
      String label = n.f1.accept(this, argu).toString();
      System.out.println("b " + label);
      return null;
   }

   /**
    * f0 -> "HSTORE"
    * f1 -> Reg()
    * f2 -> IntegerLiteral()
    * f3 -> Reg()
    */
   public R visit(HStoreStmt n, A argu) 
   {
      String reg1 = n.f1.accept(this, argu).toString();
      String reg2 = n.f3.accept(this, argu).toString();
      int offset = Integer.parseInt(n.f2.accept(this, argu).toString());

      System.out.println("sw " + reg2 + ", " + offset + "(" + reg1 + ")");
      return null;
   }

   /**
    * f0 -> "HLOAD"
    * f1 -> Reg()
    * f2 -> Reg()
    * f3 -> IntegerLiteral()
    */
   public R visit(HLoadStmt n, A argu) 
   {
      String reg1 = n.f1.accept(this, argu).toString();
      String reg2 = n.f2.accept(this, argu).toString();
      int offset = Integer.parseInt(n.f3.accept(this, argu).toString());

      System.out.println("lw " + reg1 + ", " + offset + "(" + reg2 + ")");
      return null;
   }

   /**
    * f0 -> "MOVE"
    * f1 -> Reg()
    * f2 -> Exp()
    */
   public R visit(MoveStmt n, A argu) 
   {
      String reg = n.f1.accept(this, argu).toString();
      ExpReturn exp = (ExpReturn)n.f2.accept(this, argu);

      if(exp.type.equals("HALLOCATE")) System.out.println("move " + reg + ", $v0");
      else if(exp.type.equals("BINOP"))
      {
         String op = exp.op;
         String reg1 = exp.reg1;
         String val2;
         if(exp.simpleExpType.equals("REG")) val2 = exp.simpleExpReg;
         else if(exp.simpleExpType.equals("INT")) val2 = Integer.toString(exp.simpleExpIntVal);
         else val2 = exp.simpleExpLabel;
         
         if(op.equals("LE")) System.out.println("sle " + reg + ", " + reg1 + ", " + val2);
         else if(op.equals("NE")) System.out.println("sne " + reg + ", " + reg1 + ", " + val2);
         else if(op.equals("PLUS")) System.out.println("add " + reg + ", " + reg1 + ", " + val2);
         else if(op.equals("MINUS")) System.out.println("sub " + reg + ", " + reg1 + ", " + val2);
         else if(op.equals("TIMES")) System.out.println("mul " + reg + ", " + reg1 + ", " + val2);
         else if(op.equals("DIV")) System.out.println("div " + reg + ", " + reg1 + ", " + val2);
      }
      else if(exp.type.equals("SIMPLEEXP"))
      {
         if(exp.simpleExpType.equals("REG")) System.out.println("move " + reg + ", " + exp.simpleExpReg);
         else if(exp.simpleExpType.equals("INT")) System.out.println("li " + reg + ", " + exp.simpleExpIntVal);
         else System.out.println("la " + reg + ", " + exp.simpleExpLabel);
      }
      return null;
   }

   /**
    * f0 -> "PRINT"
    * f1 -> SimpleExp()
    */
   public R visit(PrintStmt n, A argu) 
   {
      SimpleExpReturn exp = (SimpleExpReturn)n.f1.accept(this, argu);

      if(exp.type.equals("REG")) System.out.println("move $a0, " + exp.reg);
      else if(exp.type.equals("INT")) System.out.println("li $a0, " + exp.intVal);
      else if(exp.type.equals("LABEL")) System.out.println("la $a0, " + exp.label);

      System.out.println("jal _print");
      return null;
   }

   /**
    * f0 -> "ALOAD"
    * f1 -> Reg()
    * f2 -> SpilledArg()
    */
   public R visit(ALoadStmt n, A argu) 
   {
      String reg = n.f1.accept(this, argu).toString();
      int offset = Integer.parseInt(n.f2.accept(this, argu).toString());

      int newOffset = 4 * (offset + 3);
      System.out.println("lw " + reg + ", -" + newOffset + "($fp)");      
      return null;
   }

   /**
    * f0 -> "ASTORE"
    * f1 -> SpilledArg()
    * f2 -> Reg()
    */
   public R visit(AStoreStmt n, A argu) 
   {
      int offset = Integer.parseInt(n.f1.accept(this, argu).toString());
      String reg = n.f2.accept(this, argu).toString();

      int newOffset = 4 * (offset + 3);
      System.out.println("sw " + reg + ", -" + newOffset + "($fp)");
      return null;
   }

   /**
    * f0 -> "PASSARG"
    * f1 -> IntegerLiteral()
    * f2 -> Reg()
    */
   public R visit(PassArgStmt n, A argu) 
   {
      int offset = Integer.parseInt(n.f1.accept(this, argu).toString());
      String reg = n.f2.accept(this, argu).toString();

      System.out.println("sw " + reg + ", -" + (offset * 4 + 8) + "($sp)");
      return null;
   }

   /**
    * f0 -> "CALL"
    * f1 -> SimpleExp()
    */
   public R visit(CallStmt n, A argu) 
   {
      SimpleExpReturn exp = (SimpleExpReturn)n.f1.accept(this, argu);

      if(exp.type.equals("REG")) System.out.println("jalr " + exp.reg);
      else if(exp.type.equals("LABEL")) System.out.println("jalr " + exp.label);
      else if(exp.type.equals("INT"))
      {
         System.out.println("li $v0, " + exp.intVal);
         System.out.println("jalr $v0");
      }
      return null;
   }

   /**
    * f0 -> HAllocate()
    *       | BinOp()
    *       | SimpleExp()
    */
   public R visit(Exp n, A argu) 
   {
      if(n.f0.which == 0) return n.f0.accept(this, argu);
      else if(n.f0.which == 1) return n.f0.accept(this, argu);
      else
      {
         SimpleExpReturn exp = (SimpleExpReturn)n.f0.accept(this, argu);
         
         ExpReturn ret = new ExpReturn();
         ret.type = "SIMPLEEXP";
         ret.simpleExpType = exp.type;
         if(exp.type.equals("REG")) ret.simpleExpReg = exp.reg;
         else if(exp.type.equals("INT")) ret.simpleExpIntVal = exp.intVal;
         else if(exp.type.equals("LABEL")) ret.simpleExpLabel = exp.label;
         return (R)ret;
      }
   }

   /**
    * f0 -> "HALLOCATE"
    * f1 -> SimpleExp()
    */
   public R visit(HAllocate n, A argu) 
   {
      SimpleExpReturn exp = (SimpleExpReturn)n.f1.accept(this, argu);

      if(exp.type.equals("REG")) System.out.println("move $a0, " + exp.reg);
      else if(exp.type.equals("INT")) System.out.println("li $a0, " + exp.intVal);
      else if(exp.type.equals("LABEL")) System.out.println("la $a0, " + exp.label);

      System.out.println("jal _halloc");

      ExpReturn ret = new ExpReturn();
      ret.type = "HALLOCATE";
      return (R)ret;
   }

   /**
    * f0 -> Operator()
    * f1 -> Reg()
    * f2 -> SimpleExp()
    */
   public R visit(BinOp n, A argu) 
   {
      String op = n.f0.accept(this, argu).toString();
      String reg = n.f1.accept(this, argu).toString();
      SimpleExpReturn exp = (SimpleExpReturn)n.f2.accept(this, argu);

      ExpReturn ret = new ExpReturn();
      ret.type = "BINOP";
      ret.op = op;
      ret.reg1 = reg;
      ret.simpleExpType = exp.type;
      if(exp.type.equals("REG")) ret.simpleExpReg = exp.reg;
      else if(exp.type.equals("INT")) ret.simpleExpIntVal = exp.intVal;
      else if(exp.type.equals("LABEL")) ret.simpleExpLabel = exp.label;
      return (R)ret;
   }

   /**
    * f0 -> "LE"
    *       | "NE"
    *       | "PLUS"
    *       | "MINUS"
    *       | "TIMES"
    *       | "DIV"
    */
   public R visit(Operator n, A argu) 
   {
      return n.f0.accept(this, argu);
   }

   /**
    * f0 -> "SPILLEDARG"
    * f1 -> IntegerLiteral()
    */
   public R visit(SpilledArg n, A argu) 
   {
      return n.f1.accept(this, argu);
   }

   /**
    * f0 -> Reg()
    *       | IntegerLiteral()
    *       | Label()
    */
   public R visit(SimpleExp n, A argu) 
   {
      R _ret = n.f0.accept(this, argu);

      SimpleExpReturn simpleExpReturn = new SimpleExpReturn();

      if(n.f0.which == 0)
      {
         simpleExpReturn.type = "REG";
         simpleExpReturn.reg = (String)_ret;
      }
      else if(n.f0.which == 1)
      {
         simpleExpReturn.type = "INT";
         simpleExpReturn.intVal = Integer.parseInt(_ret.toString());
      }
      else if(n.f0.which == 2)
      {
         simpleExpReturn.type = "LABEL";
         simpleExpReturn.label = (String)_ret;
      }
      
      return (R)simpleExpReturn;
   }

   /**
    * f0 -> "a0"
    *       | "a1"
    *       | "a2"
    *       | "a3"
    *       | "t0"
    *       | "t1"
    *       | "t2"
    *       | "t3"
    *       | "t4"
    *       | "t5"
    *       | "t6"
    *       | "t7"
    *       | "s0"
    *       | "s1"
    *       | "s2"
    *       | "s3"
    *       | "s4"
    *       | "s5"
    *       | "s6"
    *       | "s7"
    *       | "t8"
    *       | "t9"
    *       | "v0"
    *       | "v1"
    */
   public R visit(Reg n, A argu) 
   {
      String _ret = n.f0.accept(this, argu).toString();
      _ret = "$" + _ret;
      return (R)_ret;
   }

   /**
    * f0 -> <INTEGER_LITERAL>
    */
   public R visit(IntegerLiteral n, A argu) 
   {
      return n.f0.accept(this, argu);
   }

   /**
    * f0 -> <IDENTIFIER>
    */
   public R visit(Label n, A argu) 
   {
      R _ret = n.f0.accept(this, argu);
      if(printLabel) System.out.println(_ret.toString() + ":");
      return _ret;
   }

   /**
    * f0 -> "//"
    * f1 -> SpillStatus()
    */
   public R visit(SpillInfo n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      n.f1.accept(this, argu);
      return _ret;
   }

   /**
    * f0 -> <SPILLED>
    *       | <NOTSPILLED>
    */
   public R visit(SpillStatus n, A argu) {
      R _ret=null;
      n.f0.accept(this, argu);
      return _ret;
   }
}
