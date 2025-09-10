package Java;

import java.util.Scanner;

public class bai43_DynamicPoly {
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        bai43_Animal animal;

        System.out.println("What animal do you want? ");
        System.out.print("1 = dog or 2 = cat: ");

        int choice = scanner.nextInt();

        if (choice == 1){
            animal = new bai43_Dog();
            animal.speak();
        }

        else if (choice == 2){
            animal = new bai43_Cat();
            animal.speak();
        }

        else{
            animal = new bai43_Animal();
            System.out.println("That choice is invalid");
            animal.speak();
        }

        scanner.close();
    }
}
