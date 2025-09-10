package Java;

public class bai41_Interface {
    public static void main(String[] args) {

        bai41_Rabbit rabbit = new bai41_Rabbit();
        rabbit.flee();
        System.out.println();

        bai41_Hawk hawk = new bai41_Hawk();
        hawk.hunt();
        System.out.println();

        bai41_Fish fish = new bai41_Fish();
        fish.flee();
        System.out.println();
        fish.hunt();
    }
}
