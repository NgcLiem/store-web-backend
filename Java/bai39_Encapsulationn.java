package Java;

public class bai39_Encapsulationn {
    public static void main(String[] args) {
        bai39_Car car = new bai39_Car("BMW", "Macaro", 2024);

        car.setYear(2022);

        System.out.println(car.getMake());
        System.out.println(car.getModel());
        System.out.println(car.getYear());

        
    }
}
