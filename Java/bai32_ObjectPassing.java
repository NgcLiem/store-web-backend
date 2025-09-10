package Java;

public class bai32_ObjectPassing {
    public static void main(String[] args) {
        bai32_Car car = new bai32_Car("BMW");
        bai32_Car car2 = new bai32_Car("Tesla");

        bai32_Garage garage = new bai32_Garage();
        garage.park(car2);
        garage.park(car);

    }
}
