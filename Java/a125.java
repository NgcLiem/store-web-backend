package Java;

public class a125 {
    String name;
    int old;
    public a125(){
        name = "hey";
        old = 17;
        System.out.println("constructor");
    }

    public String toString(){
        return this.name + this.old;
    }
    public static void main(String[] args) {
        a125 a = new a125();
        
    }
}
