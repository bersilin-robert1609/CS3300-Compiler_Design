class MethodOverloadingSimple {
    public static void main(String[] args)
    {
        System.out.println(new A().foo(1, 2, true));
    }
}
class A
{
	public int foo(int n, int m, boolean k)
	{
		return 1;
	}
}

class B extends A
{
	public boolean foo(int n, boolean k, int m, int l)
	{
		return false;
	}
}
