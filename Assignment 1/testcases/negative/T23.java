class NoReturn {
    public static void main(String[] a){
        System.out.println(new A().run());
    }
}

class A {
    public int run(){
    } // return statement is compulsory
}
