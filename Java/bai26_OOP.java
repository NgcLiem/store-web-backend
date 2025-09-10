package Java;

public class bai26_OOP {
    public static void main(String[] args) {
        bai26_Car myCar1 = new bai26_Car();
        bai26_Car myCar2 = new bai26_Car();
        System.out.println(myCar1.model);
        myCar1.drive();

        System.out.println(myCar2.price);
    }
}
