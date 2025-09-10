# bai 1 khoi tao
class SieuNhan:
    def __init__(self, paraten):
        self.name = "i love you " + paraten
        
    def xin_chao(self):
        return "Xin chao " + self.name     

sieuNhan = SieuNhan("ten cua toi la: ")

# print(sieuNhan.name)
# print(sieuNhan.xin_chao())
# print(SieuNhan.xin_chao(sieuNhan))

# bai 3 phuong thuc
class SieuNhan3:
    def __init__(self, ten, vuKhi, mauSac):
        self.ten = ten
        self.vu_khi = vuKhi
        self.mau_sac = mauSac
        
    @classmethod
    def from_string(cls, s):
        lst = s.split('-')
        new_lst = [i.strip() for i in lst]
        ten, vu_khi, mau_sac = new_lst
        return cls(ten, vu_khi, mau_sac)
    
    @staticmethod
    def layPau():
        return "xinchao"
    
infor_str = "Vang - Luc-Lam "
sieuNhanA3 = SieuNhan3.from_string(infor_str)
sieuNhanA33 = SieuNhan3.from_string(infor_str)
# print(sieuNhanA3.__dict__)
# sieuNhanA3.ten = "ngoc"
# print(sieuNhanA3.__dict__)
# print(sieuNhanA33.__dict__)

# print(SieuNhan3.layPau())
# print(sieuNhanA3.layPau())


# bai 4 ke thua
class SieuNhan4:
    suc_manh = 50
    def __init__(self, ten, vuKhi, mauSac):
        self.ten = ten
        self.vu_khi = vuKhi
        self.mau_sac = mauSac
        
    def showSucManh(self):
        print("Suc manh la", self.suc_manh)    

class SieuNhanDo4(SieuNhan4):
    suc_manh = 40 # ke thua thuoc tinh
    def __init__(self, ten, vuKhi, mauSac, suThu): # ke thua thuoc tinh
        super().__init__(ten, vuKhi, mauSac)
        # self.ten = ten
        # self.vu_khi = vuKhi
        # self.mau_sac = mauSac
        self.su_thu = suThu
        
    def showSucManh(self): # ke thua phuong thuc
        print("Suc manh la", self.suc_manh)     
    
sieuNhanA44 = SieuNhan4("gao", "sung", "Kem")
sieuNhanA4 = SieuNhanDo4("gao", "sung", "Kem", "Cop")

# print(sieuNhanA44.__dict__)  
# print(sieuNhanA4.__dict__)    
# sieuNhanA44.showSucManh()
# sieuNhanA4.showSucManh()

                    
# bai 5 special method
class SieuNhan5:
    suc_manh = 50
    def __init__(self, ten, vuKhi, mauSac):
        self.ten = ten
        self.vu_khi = vuKhi
        self.mau_sac = mauSac                    
    def __str__(self):
        return "Day la {}, su dung {}".format(self.ten, self.vu_khi)
    def __repr__(self):
        return 'ten: {}\nvu khi: {}\nmau sac: {}\n'.format(self.ten, self.vu_khi, self.mau_sac)
    # tu dinh nghia special method
    def __len__(self):
        return len(self.ten)
    def __add__(self, other):
        return self.suc_manh + other.suc_manh
                    
SN_A = SieuNhan5("Sieu nhan Do", "Kiem", "Do")
SN_B = SieuNhan5("Sieu nhan Xanh", "Bom", "Vang")
# print(SN_A)  
# print('%s' %SN_A)
# print('%r' %SN_A)
# print(SN_A.__len__())

# print(int.__add__(2,3)) # special method +
# print(str.__add__("Ngoc", "Liem"))
# print(list.__add__([1,2], [4,5])) 
# print(SieuNhan5.__add__(SN_A, SN_B))          

# bai 6 setter getter deleter
class Kter:
    def __init__(self, ho, ten):
        self.ho = ho
        self.ten = ten
        
    @property    #getter
    def hoVaTen(self):
        return '{} {}'.format(self.ho, self.ten)
    @property   #getter
    def email(self):
        return self.ho +' '+ self.ten + '@gmail.com'
    
    @hoVaTen.setter  #setter
    def hoVaTen(self, tenMoi):
        hoMoi, tenMoi = tenMoi.split(' ')
        self.ho = hoMoi
        self.ten = tenMoi
        
    @hoVaTen.deleter #deleter
    def hoVaTen(self):
        self.ho = None
        self.ten = None
        print("Da xoa")
        
# test getter    
# name1 = Kter("Vo", "Liem")   
# print(name1.hoVaTen)
# print(name1.email)

# # test setter
# name1.hoVaTen = "Nguyen Ngoc"
# print(name1.hoVaTen)

# # test deleter
# del name1.hoVaTen
# print(name1.hoVaTen)