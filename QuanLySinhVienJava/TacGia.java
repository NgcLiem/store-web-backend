package QuanLySinhVienJava;

public class TacGia {
    private String tenTacGia;
    private int ngaySinh;

    public TacGia(String a,int b){
        this.tenTacGia = a;
        this.ngaySinh = b;
    }

    public void setTenTacGia(String tenTacGia){
        this.tenTacGia = tenTacGia;
    }
    
    public String getTenTacGia(){
        return tenTacGia;
    }

    public void setNgaySinh(int ngaySinh){
        this.ngaySinh = ngaySinh;
    }
    
    public int getNgaySinh(){
        return ngaySinh;
    }
}
