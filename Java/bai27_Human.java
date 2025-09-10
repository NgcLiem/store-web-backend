package Java;

public class bai27_Human {

    String name;
    int age;
    double weight;

    bai27_Human(String name,int age,double weight){

        this.name = name;
        this.age = age;
        this.weight = weight;
        eat();
        drink();
    }

    void eat(){
        System.out.println(this.name+" is eating ");
    }

    void drink(){
        System.out.println(this.name+" is drinking ");
    }
}
