import math

def DTvaCV(a, b, c):
    # Kiểm tra điều kiện tam giác
    if a + b > c and a + c > b and b + c > a:
        # Chu vi
        chuVi = a + b + c
        # Diện tích sử dụng công thức Heron
        s = chuVi / 2  # Nửa chu vi
        dienTich = math.sqrt(s * (s - a) * (s - b) * (s - c))
        return dienTich, chuVi
    else:
        return None, None

# Nhập 3 cạnh của tam giác
a = float(input("Nhập cạnh a: "))
b = float(input("Nhập cạnh b: "))
c = float(input("Nhập cạnh c: "))

dienTich, chuVi = DTvaCV(a, b, c)

if dienTich is not None:
    print(f"Diện tích tam giác: {dienTich:.2f}")
    print(f"Chu vi tam giác: {chuVi:.2f}")
else:
    print("Ba cạnh không tạo thành tam giác.")
