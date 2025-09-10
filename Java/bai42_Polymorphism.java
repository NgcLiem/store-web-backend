package Java;

public class bai42_Polymorphism {
    public static void main(String[] args) {

        bai42_Bicycle bicycle = new bai42_Bicycle();
        bai42_Boat boat = new bai42_Boat();
        bai42_Car car = new bai42_Car();

        bai42_Vehicle[] racers = {car,boat,bicycle};

        for(bai42_Vehicle x : racers)
        {
            x.go();
        }
    }
}
