package NhanVien;

public class QLNhanVien {
    private String maNV;
    private String cccd;
    private String hoTen;
    private String date;
    private String sdt;

    //Constructor
    public QLNhanVien(String maNV,String cccd,String hoTen,String date,String sdt){
        this.maNV = maNV;
        this.cccd = cccd;
        this.hoTen = hoTen;
        this.date = date;
        this.sdt = sdt;
    }

    public QLNhanVien(){
        
    }
    public void setMaNV(String maNV){
        this.maNV = maNV;
    }

    public void setCCCD(String cccd){
        this.cccd = cccd;
    }

    public void setHoTen(String hoTen){
        this.hoTen = hoTen;
    }

    public void setDate(String date){
        this.date = date;
    }

    public void setSDT(String sdt){
        this.sdt = sdt;
    }

    public String getMaNV(){
        return maNV;
    }

    public String getCCCD(){
        return cccd;
    }

    public String gethoTen(){
        return hoTen;
    }

    public String getDate(){
        return date;
    }

    public String getSDT(){
        return sdt;
    }

    
}
