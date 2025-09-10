package QuanLySinhVienJava;

public class Ngay {
    private int ngay;
    private int thang;
    private int nam;

    public Ngay(int a,int b, int c){
        this.ngay = a;
        this.thang = b;
        this.nam = c;
    }
    public void setNgay(int ngay){
        this.ngay = ngay;
    }
    
    public int getNgay(){
        return ngay;
    }

    public void setThang(int thang){
        this.thang = thang;
    }
    
    public int getThang(){
        return thang;
    }
    public void setNam(int nam){
        this.nam = nam;
    }
    
    public int getNam(){
        return nam;
    }
    
}
