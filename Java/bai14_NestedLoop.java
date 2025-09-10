package Java;

import java.util.Scanner;

public class bai14_NestedLoop {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int rows ;
        int columns ;
        String symbol = "";

        System.out.println("Enter rows: ");
        rows = scanner.nextInt();
        System.out.println("Enter column: ");
        columns = scanner.nextInt();
        System.out.println("Enter number to use: ");
        symbol = scanner.next();

        for(int i = 0; i < rows; i++){
            System.out.println();
            for(int j = 0;j < columns; j++){
                System.out.print(symbol);
            }
            
        }
        scanner.close();
    }
}
