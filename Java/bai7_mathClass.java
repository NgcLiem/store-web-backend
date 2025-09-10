package Java;

import java.util.Scanner;

public class bai7_mathClass {
    public static void main(String[] args) {
        //double c = Math.ceil(a);//lam tron so + 1 don vi
        //double d = Math.round(a);//lam tron so binh thuong
        double x;
        double y;
        double z;

        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter x:");
        x = scanner.nextDouble();
        System.out.println("Enter y:");
        y = scanner.nextDouble();
        z = Math.sqrt((x*x)+y*y);

        System.out.println("The hypotenuse is: "+z);
        scanner.close();
}
}