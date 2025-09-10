def tinh_tien_dien(so_kwh):
    # Định nghĩa giá điện theo bậc
    bac_gia = [
        (50, 1678),  # Bậc 1: 50 kWh đầu tiên
        (50, 1734),  # Bậc 2: 50 kWh tiếp theo
        (100, 2014), # Bậc 3: 100 kWh tiếp theo
        (100, 2536), # Bậc 4: 100 kWh tiếp theo
        (100, 2834), # Bậc 5: 100 kWh tiếp theo
        (float('inf'), 2927)  # Bậc 6: Phần còn lại
    ]

    tong_tien = 0  # Tổng tiền điện
    for bac in bac_gia:
        so_kwh_bac, gia_bac = bac
        if so_kwh > so_kwh_bac:  # Nếu còn nhiều kWh hơn mức của bậc này
            tong_tien += so_kwh_bac * gia_bac
            so_kwh -= so_kwh_bac
        else:  # Nếu chỉ còn số kWh trong bậc này
            tong_tien += so_kwh * gia_bac
            break

    return tong_tien


# Nhập số kWh từ người dùng
so_kwh = float(input("Nhập số kWh tiêu thụ: "))
tien_dien = tinh_tien_dien(so_kwh)

# Hiển thị kết quả
print(f"Số tiền điện phải trả cho {so_kwh} kWh là: {tien_dien:,} đồng")
