def chuanHoaTen(ten):
    return ' '.join(ten.title().split())    
    #return " ".join(word.capitalize() for word in ten.strip().lower().split())    
def dinhMuc(loai):
    return {'A': 100, 'B': 500, 'C': 200}.get(loai, 0)

class KhachHang:
    def __init__(self, ma, ten, loai, chiSoDau, chiSoCuoi):
        self.maKH = "KH{:02d}".format(ma)
        self.ten = chuanHoaTen(ten)
        self.loai = loai
        self.chiSoDau = chiSoDau
        self.chiSoCuoi = chiSoCuoi
        self.dienTieuThu = (self.chiSoCuoi - self.chiSoDau)
        self.dinhMuc = dinhMuc(self.loai)
        self.tinhTien()
        
    def tinhTien(self):
        if self.dienTieuThu < self.dinhMuc:
            self.tienDienTrongDinhMuc = self.dienTieuThu * 450
        else:
            self.tienDienTrongDinhMuc = self.dinhMuc * 450  
            
        if self.dienTieuThu > self.dinhMuc:
            self.tienDienNgoaiDinhMuc = (self.dienTieuThu - self.dinhMuc) * 1000
        else:
            self.tienDienNgoaiDinhMuc = 0
            
        self.thue = self.tienDienNgoaiDinhMuc // 20
        self.soTienPhaiNop = self.tienDienTrongDinhMuc + self.tienDienNgoaiDinhMuc + self.thue
    
    def __lt__(self, other):
        return self.soTienPhaiNop > other.soTienPhaiNop
    
    def __str__(self):
        return "{} {} {} {} {} {}".format(self.maKH, self.ten, self.tienDienTrongDinhMuc,
                                          self.tienDienNgoaiDinhMuc, self.thue, self.soTienPhaiNop)
        
a = int(input())
ds = []
for i in range(a):
    ten = input()
    loai, chiSoDau, chiSoCuoi = input().split()
    kh = KhachHang(i + 1, ten, loai, int(chiSoDau), int(chiSoCuoi))   
    ds.append(kh)

ds.sort()

for i in ds:
    print(i)                         
            