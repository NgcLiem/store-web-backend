package Java;

public class bai36_Hero extends bai36_Person{
    
    String power;

    bai36_Hero(String name, int age , String power){
        super(name,age);
        this.power = power;
    }

    public String toString(){
        return super.toString() +this.power;
    }
}
