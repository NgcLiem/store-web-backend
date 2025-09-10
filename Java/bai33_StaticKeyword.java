package Java;

public class bai33_StaticKeyword {
    public static void main(String[] args) {
        bai33_Friend friend1 = new bai33_Friend("Hello");
        bai33_Friend friend2 = new bai33_Friend("Hi");
        //bai33_Friend friend3 = new bai33_Friend("Hey");

        bai33_Friend.displayFriends(friend1);

        System.out.println(friend1.numberOfFriends);
        System.out.println(friend2.numberOfFriends);
        //System.out.println(friend3.numberOfFriends);
    }
}
