package QuanLySinhVienJava;

import java.util.Scanner;

public class Sach {
    private String tenSach;
    private int giaBan;
    private int namXuatBan;
    private TacGia tacGia;

    public Sach(String a,int b,int c, TacGia d){
        this.tenSach = a;
        this.giaBan = b;
        this.namXuatBan = c;
        this.tacGia = d;
    }

    Scanner scanner = new Scanner(System.in);

public void setSach(String sach){
    this.tenSach = sach;
}

public String getSach(){
    return tenSach;
}

public void setGiaBan(int gia){
    this.giaBan = gia;
}

public int getGiaBan(){
    return giaBan;
}

public void setNamXuatBan(int nam){
    this.namXuatBan = nam;
}

public int getNamXuatBan(){
    return namXuatBan;
}

public void setTacGia(TacGia tacGia){
    this.tacGia = tacGia;
}

public TacGia getTacGia(){
    return tacGia;
}

public void inTenSach(){
    System.out.println("Ten sach: " + this.tenSach);
}
public boolean kiemTraNamXuatBan(Sach sach){
    System.out.println("so sanh nam xuat ban cua 2 sach: ");
    return this.namXuatBan == sach.namXuatBan;
}

public void giamGia(){
    System.out.println("Ban muon giam gia bao nhieu phan tram: ");
    float b = scanner.nextInt();
    /*while(b > 100 || b < 0){
        System.out.println("Nhap lai so giam gia lon hon 0 va be hon 100 ");
        final int b = scanner.nextInt();
    }/* */
    System.out.println("Gia sach sau khi duoc giam: "+ this.giaBan*(1-b/100));
}
}