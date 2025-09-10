package Java;

public class bai34_Inheritance {
    public static void main(String[] args) {
        bai34_Vehicle vehi = new bai34_Vehicle();
        bai34_Car car = new bai34_Car();
        bai34_Bycycle bike = new bai34_Bycycle();

        System.out.println(car.wheels);
        System.out.println(bike.pedals);
        vehi.go();
    }
}
