package Java;

public class bai33_Friend {
    String name;
    static int numberOfFriends;
    bai33_Friend(String name){
        this.name = name;
        numberOfFriends++;
    }
    public static void displayFriends(){
        System.out.println("You have "+ numberOfFriends +" friends");
    }

    public static void displayFriends(bai33_Friend fr){
        System.out.println("You have "+ fr.numberOfFriends +" friends");
    }
}
