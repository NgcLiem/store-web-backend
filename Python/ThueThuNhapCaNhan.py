def thueThuNhap(tienLuong, nguoi):
    tienTruocThue = tienLuong - 11000000 - (nguoi * 4400000)
    if tienTruocThue < 0:
        return 0
    elif tienTruocThue <= 5000000:
        return tienTruocThue * 5 / 100 
    elif tienTruocThue <= 10000000:
        return tienTruocThue * 10 / 100 - 250000
    elif tienTruocThue < 18000000:
        return tienTruocThue * 15 / 100 - 750000
    elif  tienTruocThue < 32000000:
        return tienTruocThue * 20 / 100 - 1650000
    elif tienTruocThue < 52000000:
        return tienTruocThue * 25 / 100 - 3250000
    elif tienTruocThue < 80000000:
        return tienTruocThue * 30 / 100 - 5850000
    else:
        return tienTruocThue * 35 / 100 - 9850000
    
    
print(thueThuNhap(int(input("Nhap tien luong: ")), int(input("Nhap so nguoi phu thuoc: "))))