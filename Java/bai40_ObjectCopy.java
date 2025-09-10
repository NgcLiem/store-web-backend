
package Java;

public class bai40_ObjectCopy {
    public static void main(String[] args) {
        bai40_Car car1 = new bai40_Car("BMW", "Macaro", 2024);
        bai40_Car car2 = new bai40_Car(car1);
        
        car2.copy(car1);

        System.out.println(car1.getMake());
        System.out.println(car1.getModel());
        System.out.println(car1.getYear());
        System.out.println();

        System.out.println(car2.getMake());
        System.out.println(car2.getModel());
        System.out.println(car2.getYear());
        
    }
}
