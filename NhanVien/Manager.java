package NhanVien;

import java.util.ArrayList;

public class Manager {
    private ArrayList <QLNhanVien> employee;

    QLNhanVien nv1 = new QLNhanVien();    
    
    //Constructor
    public Manager(){
        employee = new ArrayList<QLNhanVien>();
    }

    public void addNhanVien(QLNhanVien nv){
        employee.add(nv);
        System.out.println("Added");
    }

    public void removeNhanVien(String nv){
        QLNhanVien found = null;
        for(QLNhanVien nv1 : employee){ 
            if(nv1.getMaNV() == nv){
                found = nv1;
                break;
            }
        }
        System.out.println(found);
            if(found != null){
                employee.remove(found);
                System.out.println("Removed");
            }
            else{
                System.out.println("Employee"+found+" not found");
            }
    }

    public void displayNhanVien(){
        System.out.println("List of Employee: ");
        int i = 1;
        for(QLNhanVien nv : employee){
            System.out.println("Nhan Vien thu "+i+++":");
            System.out.println("Ma Nhan Vien: " + nv.getMaNV()+ "\n"+"CCCD: " + nv.getCCCD() +"\n" + "Ho va ten: " + nv.gethoTen() + "\n" +
            "Ngay Thang Vao Lam: " + nv.getDate() + "\n" + "So Dien Thoai: "+nv.getSDT()+"\n"+"---------------");
        }
    }
}
