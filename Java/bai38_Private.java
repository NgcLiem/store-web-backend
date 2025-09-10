package Java;

public class bai38_Private {
    private String name = "This is a pen";
    protected String mode = "on";

    void setName(String name ){
        this.name = name;
    }
    String getName(){
        return this.name;
    }

    
}
