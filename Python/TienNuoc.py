hoGiaDinh = {'ho dan cu', 'ho ngheo'}
def tinhTienNuoc(mucTieuThu, soNguoi, thueNuocSach, donGiaXuLiNuoc, thueXuLiNuocSach):
    if (mucTieuThu <= soNguoi * 4):
        return 6700 * mucTieuThu + 6700 * mucTieuThu * (thueNuocSach + donGiaXuLiNuoc + thueXuLiNuocSach) / 1000000
    elif (mucTieuThu <= soNguoi * 6):
        return 4 * soNguoi * 6700 + (mucTieuThu - 4 * soNguoi) * 12900 + (4 * soNguoi * 6700 + (mucTieuThu - 4 * soNguoi) * 12900) * (thueNuocSach + donGiaXuLiNuoc + thueXuLiNuocSach)/ 1000000
    else:
        return 6 * soNguoi * 12900 + (mucTieuThu - 6 * soNguoi) * 14400 + (6 * soNguoi * 12900 + (mucTieuThu - 6 * soNguoi) * 14400) * (thueNuocSach + donGiaXuLiNuoc + thueXuLiNuocSach) / 1000000

print(tinhTienNuoc(int(input("Nhap tien nuoc thu: ")),
                   int(input("Nhap nguoi: ")),
                   int(input("Nhap thue nuoc sach(%): ")),
                   int(input("Nhap don gia xu li nuoc(%): ")),
                   int(input("Nhap thue xu li nuoc(%): "))))