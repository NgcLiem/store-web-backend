def taxi_bill1(km):
    total = 0
    if km <= 0:
        return "Nhap so km lon hon 0"
    elif km < 0.3:
        total = km * 20000
    elif km < 3:
        total = 0.3 * 20000 + (km - 0.3) * 18600
    elif km < 11:
        total = 0.3 * 20000 + 2.7 * 18600 + (km - 3) * 14200
    elif km <= 20:
        total = 0.3 * 20000 + 2.7 * 18600 + 8 * 14200 + (km - 11) * 13000
    elif km <= 30:
        total = 0.3 * 20000 + 2.7 * 18600 + 8 * 14200 + 9 * 13000 + (km - 20) * 12000
    elif km > 30:
        total = 0.3 * 20000 + 2.7 * 18600 + 8 * 14200 + 9 * 13000 + 10 * 12000 + (km - 30) * 11000
    
    if km > 120:
        total *= 0.9
    
    total *= 1.05
    return round(total)
     

def taxi_bill2(km):
    total = 0
    remaining = km

    if remaining <= 0:
        return 0

    if remaining <= 0.3:
        total += remaining * 20000
        return round(total * 1.05)  # VAT
    else:
        total += 0.3 * 20000
        remaining -= 0.3

    if remaining <= 2.7:  # (3 - 0.3)
        total += remaining * 18600
        return round(total * 1.05)
    else:
        total += 2.7 * 18600
        remaining -= 2.7

    if remaining <= 8:  # (11 - 3)
        total += remaining * 14200
        return round(total * 1.05)
    else:
        total += 8 * 14200
        remaining -= 8

    if remaining <= 9:  # (20 - 11)
        total += remaining * 13000
        return round(total * 1.05)
    else:
        total += 9 * 13000
        remaining -= 9

    if remaining <= 10:  # (30 - 20)
        total += remaining * 12000
        return round(total * 1.05)
    else:
        total += 10 * 12000
        remaining -= 10

    # > 30 km
    total += remaining * 11000

    # Giảm giá nếu > 120 km
    if km > 120:
        total *= 0.9

    # VAT
    total *= 1.05

    return round(total)


    
def main():
    km = float(input("Nhap so km da di: "))
    total1 = taxi_bill1(km)
    total2 = taxi_bill2(km)
    print(f"So tien: {total1:,} VND")
    print(f"So tien: {total2:,} VND") 

main()    