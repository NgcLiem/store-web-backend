package Java;

import java.util.InputMismatchException;
import java.util.Scanner;

public class bai44_ExceptionHandling {
    public static void main(String[] args) {
        try{
            Scanner scanner = new Scanner(System.in);

            System.out.println("Enter a whole number to devide: ");
            int x = scanner.nextInt();
            System.out.println("Enter a whole number to devide by: ");
            int y = scanner.nextInt();

            double z = x / y;
            System.out.println("result: "+z);
            scanner.close();
        }
        catch(ArithmeticException e){
            System.out.println("You can't devide by zero ");
        }
        catch(InputMismatchException e){
            System.out.println("Please enter a number ");
        }
        catch(Exception e){
            System.out.println("Something went wrong");
        }
        finally{
            System.out.println("This will always print");
        }
    }
}
