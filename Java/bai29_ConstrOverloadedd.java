package Java;

public class bai29_ConstrOverloadedd {
    
        String bread;
        String sauce;
        String cheese;
        String topping;
        
        bai29_ConstrOverloadedd(String bread,String sauce, String cheese,String topping){
            this.bread = bread;
            this.sauce = sauce;
            this.cheese = cheese;
            this.topping = topping;
        }
        bai29_ConstrOverloadedd(String bread,String sauce, String cheese){
            this.bread = bread;
            this.sauce = sauce;
            this.cheese = cheese;
        }
        bai29_ConstrOverloadedd(String bread,String sauce){
            this.bread = bread;
            this.sauce = sauce;

        }
        bai29_ConstrOverloadedd(String bread){
            this.bread = bread;
        }
        bai29_ConstrOverloadedd(){
           
        }


}
