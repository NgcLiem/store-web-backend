package Java;

public class bai36_Person {
    String name ;
    int age;
    bai36_Person(String name,int age){
        this.name = name;
        this.age = age;
    }

    public String toString(){
        return this.name + "\n"+this.age+"\n";
    }
}
