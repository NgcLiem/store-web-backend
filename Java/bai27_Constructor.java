package Java;

public class bai27_Constructor {
    public static void main(String[] args) {
        

        bai27_Human human = new bai27_Human("Rick",64,98.2);
        bai27_Human human2 = new bai27_Human("Kevin", 9, 5.6);
        
        System.out.println(human.name);
        System.out.println(human.age);
        System.out.println(human.weight);
        System.out.println(human2.name);
        System.out.println(human2.age);
        System.out.println(human2.weight);
        
        human2.eat();
        human.drink();
    }
}
