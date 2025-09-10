package Java;

public class a123
{
    public String name;
    private int age;
    public float height;

    public a123(String name, int age, float height)
    {
        this.name = name;
        this.age = age;
        this.height = height;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public String getName()
    {
        return this.name;
    }

    public void getInfo()
    {
        System.out.println("Name: "+this.name);
        System.out.println("Age: "+this.age);
        System.out.println("Height: "+this.height);
    }
}