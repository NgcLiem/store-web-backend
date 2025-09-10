package Java;

import java.util.Scanner;

public class bai4_userJava {
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner (System.in);

        System.out.println("What is your name? ");
        String name = scanner.nextLine();
        System.out.println("How old are you? ");
        int age = scanner.nextInt();
        scanner.nextLine();
        System.out.println("What is your favorite food?");
        String food = scanner.nextLine();
        System.out.println("How many car in your house?");
        int count = scanner.nextInt();

        System.out.println("hello "+name);
        System.out.println("You are "+age+" year old");
        System.out.println("Your favorite food is "+food);
        System.out.println("Car: "+count);
        scanner.close();
    }
}
