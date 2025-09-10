class KhachHang:
    def __init__(self, ma, ten, chiSoDau, chiSoMoi):
        self.maKH = "KH{:02d}".format(ma)
        self.ten = ten
        self.chiSoDau = chiSoDau
        self.chiSoMoi = chiSoMoi
        self.soNuocTieuThu = int(self.chiSoMoi) - int(self.chiSoDau) 
        self.soTien()
        
    def soTien(self):
        soNuocTieuThu1 = self.soNuocTieuThu
        
        if self.soNuocTieuThu <= 50:
            self.tongSoTien = soNuocTieuThu1 * 100 * 1.02
        elif self.soNuocTieuThu <= 100:
            self.tongSoTien = (50 * 100 + (soNuocTieuThu1 - 50) * 150) * 1.03
        else:
            self.tongSoTien = (50 * 100 + 50 * 150 + (soNuocTieuThu1 - 100) * 200) * 1.05

    def __lt__(self, other):
        return self.tongSoTien > other.tongSoTien

    def __str__(self):
        return f"{self.maKH} {self.ten} {round(self.tongSoTien)}"
    
a = int(input())
ds = []
for i in range(a):
    ten = input()
    chiSoDau = input()
    chiSoCuoi = input() 
    khachHang = KhachHang(i + 1, ten, chiSoDau, chiSoCuoi)
    ds.append(khachHang)
    
ds.sort()

for i in ds:
    print(i)  
    
      
    
                     
           