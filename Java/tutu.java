package Java;

public class tutu {
    public static void main(String [] args)
    {
        String x = "water"; 
        String y ="kid" ;
        String z ;
        
        System.out.println("x:"+x);
        System.out.println("y:"+y);
        
        z = x;
        x = y;
        y = z;

        System.out.println("x:"+x);
        System.out.println("y:"+y);

    }
}
