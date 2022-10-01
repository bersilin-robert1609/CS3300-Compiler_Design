class SimpleMinijava {
    public static void main(String[] args)
    {
        System.out.println(new BBS().Start());
    }
}

class BS
{
    int i;
    int j;

    public int Start()
    {
        i = 1;
        j = 1;
        while (i <= 10)
        {
            i = i + 1;
            j = j + 2;
        }
        // j = 21 
        return j;
    }
    public int End()
    {
        return 0;
    }
}

class BBS extends BS
{
    int k;
    int l;
    
    public int Start3()
    {
        k = 0;
        l = 0;
        while (k <= 10)
        {
            k = k + 1;
            l = l + 1;
        }
        return l;
    }

    public int End3()
    {
        return 0;
    }

    public int Start2()
    {
        i = 0;
        j = 0;
        while (i <= 10)
        {
            i = i + 1;
            j = j + 1;
        }
        return j;
    }
}
