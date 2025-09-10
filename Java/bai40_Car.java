package Java;

public class bai40_Car {
    private String make;
    private String model;
    private int year;

    bai40_Car(String make, String model, int year){
        this.setMake(make);
        this.setModel(model);
        this.setYear(year);
    }

    bai40_Car(bai40_Car x){
        this.copy(x);
    }

    public String getMake(){
        return make;
    }

    public String getModel(){
        return model;
    }

    public int getYear(){
        return year;
    }

    public void setMake(String make){
        this.make = make;
    }

    public void setModel(String model){
        this.model = model;
    }

    public void setYear (int year){
        this.year = year;
    }

    public void copy(bai40_Car x){
        this.setMake(x.getMake());
        this.setModel(x.getModel());
        this.setYear(x.getYear());
    }
}

