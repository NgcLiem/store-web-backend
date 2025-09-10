package Java;

public class bai31_ArrayOfObject {
    public static void main(String[] args) {

    bai31_Food[] refrigerator = new bai31_Food[3];

    bai31_Food food1 = new bai31_Food("pizza");
    bai31_Food food2 = new bai31_Food("hamburger");
    bai31_Food food3 = new bai31_Food("hotdog");

    refrigerator[0] = food1;
    refrigerator[1] = food2;
    refrigerator[2] = food3;

    System.out.println(refrigerator[0].name);
    System.out.println(refrigerator[1].name);
    System.out.println(refrigerator[2].name);
    }
}

