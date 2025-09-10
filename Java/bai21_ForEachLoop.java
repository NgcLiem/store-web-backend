package Java;

import java.util.ArrayList;

public class bai21_ForEachLoop {
    public static void main(String[] args) {
        ArrayList<String> animals = new ArrayList<String>();
        animals.add("cat");
        animals.add("dog");
        animals.add("rat");
        animals.add("duck");

        for(String i : animals){
            System.out.println(i);
        }
    }
}
