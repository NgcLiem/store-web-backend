class HocSinh:
    def __init__(self, ma, ten, diemLT, diemTH):
        self.ma = f"TS0{str(ma)}"
        self.ten = ten
        self.diemTB = ((diemLT if diemLT <= 10 else diemLT / 10) + (diemTH if diemTH <= 10 else diemTH / 10)) / 2
        if self.diemTB < 5:
            self.xepLoai = "TRUOT"
        elif self.diemTB < 8:
            self.xepLoai = "CAN NHAC"         
        elif self.diemTB < 9.5:
            self.xepLoai = "DAT"
        else:
            self.xepLoai = "XUAT SAC" 
    def __str__(self):
        return f"{self.ma} {self.ten} {round(self.diemTB, 2):.2f} {self.xepLoai}"
    def __lt__(self, other):
        return self.diemTB > other.diemTB
    
a = int(input())
ds = []
for i in range(a):
    ds.append(HocSinh(i + 1, input(), float(input()), float(input())))

ds.sort()
for i in ds:
    print(i)    
