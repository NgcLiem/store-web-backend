package Java;

import java.util.Random;

public class bai28_VariableScopee {
    Random random;
    int number ;

    bai28_VariableScopee(){
        random = new Random();
        roll();
    }

    void roll(){
        number = random.nextInt(6)+1;
        System.out.println(number);
    }
}
