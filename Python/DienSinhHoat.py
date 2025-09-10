import math


def HamDienSinhHoat(a, dk):
    if(dk == 'banle'):
        if a <= 50:
            return a * 1806
        elif a <= 100:
            return 50 * 1806 + (a-50) * 1866 + (50 * 1806 + (a-50) * 1866) * 5 / 100
        elif a <= 200:
            return 100 * 1866 + (a-100) * 2167 + (100 * 1866 + (a-100) * 2167) * 5 / 100
        elif a <= 300:
            return 200 * 2167 + (a-200) * 2729 + (200 * 2167 + (a-200) * 2729) * 5 / 100
        elif a <= 400:
            return 300 * 1806 + (a-300) * 3050 + (300 * 1806 + (a-300) * 3050) * 5 / 100
        else:
            return 400 * 3050 + (a-400) * 3151 + (400 * 3050 + (a-400) * 3151) * 5 / 100
    else:
        return a * 2649 + (a * 2649) * 5 / 100    

a = int(input("Nhap so dien: "))
dk = str(input("Nhap dien ban le hay dien cong to: "))   

print(HamDienSinhHoat(a, dk))
   
    
    