package Java;

import java.util.ArrayList;

public class bai19_ArryList {
    public static void main(String[] args) {
        ArrayList<String> food = new ArrayList<String>();

        food.add("hamburger");
        food.add("hotdog");
        food.add("bread");

        food.set(1,"sushi");
        //food.remove(0);
        //food.clear();

        for(int i = 0;i <food.size();i++){
            System.out.println(food.get(i));
        }


    }
}
