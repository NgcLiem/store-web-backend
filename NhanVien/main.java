package NhanVien;

import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Manager mana = new Manager();
        //QLNhanVien ql = new QLNhanVien();

        while(true){
            System.out.println("----------------------------");
            System.out.println("1. Add Employee");
            System.out.println("2. Remove Employee");
            System.out.println("3. Display Employee");
            System.out.println("4. Exit");
            System.out.println("Enter your choose: ");
            int choose = scanner.nextInt();
            scanner.nextLine();

        switch(choose){
            case 1:
                System.out.println("Enter ma nhan vien: ");
                String maNV = scanner.nextLine();
                System.out.println("Enter cccd: ");
                String cccd = scanner.nextLine();
                System.out.println("Enter ho va ten: ");
                String hoTen = scanner.nextLine();
                System.out.println("Enter ngay vao lam: ");
                String date = scanner.nextLine();
                System.out.println("Enter so dien thoai: ");
                String sdt = scanner.nextLine();

                QLNhanVien emp = new QLNhanVien(maNV,cccd,hoTen,date,sdt);
                mana.addNhanVien(emp);
                break;

            case 2:
                System.out.println("Enter ma nhan vien muon remove: ");
                String maRemove = scanner.nextLine();
                mana.removeNhanVien(maRemove);
                break;

            case 3:
                mana.displayNhanVien();  
                break;

            case 4:
                System.out.println("Exiting....");  
                System.exit(0);
            default:
                System.out.println("Invalid choise. Please choose a number between 1 and 4.");    
            }
        }
    }
}
