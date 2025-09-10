package QuanLySinhVienJava;

public class quanLySinhVien {
    public static void main(String[] args) {
        Ngay ngay1 = new Ngay(15, 8, 2021);
        Ngay ngay2 = new Ngay(28, 11, 2041);
        Ngay ngay3 = new Ngay(7, 1, 2026);

        TacGia tacGia1 = new TacGia("nguyen thuong hien", 1979);
        TacGia tacGia2 = new TacGia("xuan dieu", 1965);
        TacGia tacGia3 = new TacGia("to huu", 1900);

        Sach sach1 = new Sach("Trang Ti", 5000 , 2001, tacGia1);
        Sach sach2 = new Sach("Toi Yeu Em", 15000 , 2000, tacGia2);
        Sach sach3 = new Sach("Tat den", 25000 , 2001, tacGia3);

        sach1.inTenSach();

        if(sach1.kiemTraNamXuatBan(sach3) == true){
            System.out.println("cung nam xuat ban");
        }
        else{
            System.out.println("khac nam xuat ban");
        }
        if(sach2.kiemTraNamXuatBan(sach3) == true){
            System.out.println("cung nam xuat ban");
        }
        else{
            System.out.println("khac nam xuat ban");
        }
        sach1.giamGia();
    }
}


