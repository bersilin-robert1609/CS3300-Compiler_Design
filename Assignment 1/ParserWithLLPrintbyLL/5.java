
class LinkedList {
public static void main  (String  [] a)  {
System.out.println (new LL () .Start () ) ;

}

}

class Element {
int Age;
int Salary;
boolean Married;
public boolean Init (int v_Age,)  {
Age = v_Age;
Salary = v_Salary;
Married = v_Married;
return true;

}
public int GetAge ()  {
return Age;

}
public int GetSalary ()  {
return Salary;

}
public boolean GetMarried ()  {
return Married;

}
public boolean Equal (Elementother)  {
boolean ret_val;
int aux01;
int aux02;
int nt;
ret_val = true;
aux01 = other.GetAge () ;
if  (!this.Compare (aux01,Age) ) ret_val = false;
else  {
aux02 = other.GetSalary () ;
if  (!this.Compare (aux02,Salary) ) ret_val = false;
else if  (Married) if  (!other.GetMarried () ) ret_val = false;
else nt = 0;
else if  (other.GetMarried () ) ret_val = false;
else nt = 0;

}
return ret_val;

}
public boolean Compare (int num1,)  {
boolean retval;
int aux02;
retval = false;
aux02 = num2 + 1;
if  ( (num1 <= num2)  &&  (num1 != num2) ) retval = false;
else if  (! (num1 <=  (aux02 - 1) ) ) retval = false;
else retval = true;
return retval;

}

}

class List {
Elementelem;
Listnext;
boolean end;
public boolean Init ()  {
end = true;
return true;

}
public boolean InitNew (Elementv_elem,)  {
end = v_end;
elem = v_elem;
next = v_next;
return true;

}
public ListInsert (Elementnew_elem)  {
boolean ret_val;
Listaux03;
Listaux02;
aux03 = this;
aux02 = new List () ;
ret_val = aux02.InitNew (new_elem,aux03,false) ;
return aux02;

}
public boolean SetNext (Listv_next)  {
next = v_next;
return true;

}
public ListDelete (Elemente)  {
Listmy_head;
boolean ret_val;
boolean aux05;
Listaux01;
Listprev;
boolean var_end;
Elementvar_elem;
int aux04;
int nt;
my_head = this;
ret_val = false;
aux04 = 0 - 1;
aux01 = this;
prev = this;
var_end = end;
var_elem = elem;
while  ( (!var_end)  &&  (!ret_val) )  {
if  (e.Equal (var_elem) )  {
ret_val = true;
if  ( (aux04 <= 0)  &&  (aux04 != 0) )  {
my_head = aux01.GetNext () ;

}
else  {
System.out.println (0 - 555) ;
aux05 = prev.SetNext (aux01.GetNext () ) ;
System.out.println (0 - 555) ;

}

}
else nt = 0;
if  (!ret_val)  {
prev = aux01;
aux01 = aux01.GetNext () ;
var_end = aux01.GetEnd () ;
var_elem = aux01.GetElem () ;
aux04 = 1;

}
else nt = 0;

}
return my_head;

}
public int Search (Elemente)  {
int int_ret_val;
Listaux01;
Elementvar_elem;
boolean var_end;
int nt;
int_ret_val = 0;
aux01 = this;
var_end = end;
var_elem = elem;
while  (!var_end)  {
if  (e.Equal (var_elem) )  {
int_ret_val = 1;

}
else nt = 0;
aux01 = aux01.GetNext () ;
var_end = aux01.GetEnd () ;
var_elem = aux01.GetElem () ;

}
return int_ret_val;

}
public boolean GetEnd ()  {
return end;

}
public ElementGetElem ()  {
return elem;

}
public ListGetNext ()  {
return next;

}
public boolean Print ()  {
Listaux01;
boolean var_end;
Elementvar_elem;
aux01 = this;
var_end = end;
var_elem = elem;
while  (!var_end)  {
System.out.println (var_elem.GetAge () ) ;
aux01 = aux01.GetNext () ;
var_end = aux01.GetEnd () ;
var_elem = aux01.GetElem () ;

}
return true;

}

}

class LL {
public int Start ()  {
Listhead;
Listlast_elem;
boolean aux01;
Elementel01;
Elementel02;
Elementel03;
last_elem = new List () ;
aux01 = last_elem.Init () ;
head = last_elem;
aux01 = head.Init () ;
aux01 = head.Print () ;
el01 = new Element () ;
aux01 = el01.Init (25,37000,false) ;
head = head.Insert (el01) ;
aux01 = head.Print () ;
System.out.println (10000000) ;
el01 = new Element () ;
aux01 = el01.Init (39,42000,true) ;
el02 = el01;
head = head.Insert (el01) ;
aux01 = head.Print () ;
System.out.println (10000000) ;
el01 = new Element () ;
aux01 = el01.Init (22,34000,false) ;
head = head.Insert (el01) ;
aux01 = head.Print () ;
el03 = new Element () ;
aux01 = el03.Init (27,34000,false) ;
System.out.println (head.Search (el02) ) ;
System.out.println (head.Search (el03) ) ;
System.out.println (10000000) ;
el01 = new Element () ;
aux01 = el01.Init (28,35000,false) ;
head = head.Insert (el01) ;
aux01 = head.Print () ;
System.out.println (2220000) ;
head = head.Delete (el02) ;
aux01 = head.Print () ;
System.out.println (33300000) ;
head = head.Delete (el01) ;
aux01 = head.Print () ;
System.out.println (44440000) ;
return 0;

}

}