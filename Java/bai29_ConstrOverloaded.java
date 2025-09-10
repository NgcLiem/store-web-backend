package Java;

public class bai29_ConstrOverloaded {
    public static void main(String[] args) {
        bai29_ConstrOverloadedd pizza = new bai29_ConstrOverloadedd("chi","hoa","le","nang");
        System.out.println("Here: "+pizza.bread+" "+pizza.sauce+" "+pizza.cheese+" "+pizza.topping);

        bai29_ConstrOverloadedd pizza1 = new bai29_ConstrOverloadedd("dao","mai","loa ");
        System.out.println("Here: "+pizza1.bread+" "+pizza1.sauce+" "+pizza1.cheese);
    }
}

