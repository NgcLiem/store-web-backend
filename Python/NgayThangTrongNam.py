def ngayTrongThang(year, month):
    if month in [1, 3, 5, 7, 8, 10, 12]:
        return 31
    elif month in [4, 6, 9, 11]:
        return 30
    elif month == 2:
        if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
            return 29
        else:
            return 28
    else:
        return None

year = int(input("Nhập năm: "))
month = int(input("Nhập tháng (1-12): "))

days = ngayTrongThang(year, month)

if days is not None:
    print(f"Tháng {month} năm {year} có {days} ngày.")
else:
    print("Tháng không hợp lệ.")
