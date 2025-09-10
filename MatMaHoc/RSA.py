def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def extended_gcd(a, b):
    if b == 0:
        return (1, 0)
    else:
        x1, y1 = extended_gcd(b, a % b)
        x, y = y1, x1 - (a // b) * y1
        return (x, y)

def mod_inverse(e, phi):
    x, y = extended_gcd(e, phi)
    return x % phi

def is_prime(n):
    if n <= 1: return False
    if n <= 3: return True
    if n % 2 == 0: return False
    for i in range(3, int(n ** 0.5) + 1, 2):
        if n % i == 0:
            return False
    return True

def generate_keys(p, q):
    if not (is_prime(p) and is_prime(q)):
        raise ValueError("p và q phải là số nguyên tố.")

    if p == q:
        raise ValueError("p và q phải khác nhau.")

    n = p * q
    phi = (p - 1) * (q - 1)

    e = 65537
    if gcd(e, phi) != 1:
        e = 3
        while gcd(e, phi) != 1:
            e += 2

    d = mod_inverse(e, phi)
    return (e, d, n)

def encrypt(message, e, n):
    return pow(message, e, n)

def decrypt(ciphertext, d, n):
    return pow(ciphertext, d, n)

try:
    p = int(input("Nhập số nguyên tố p: "))
    q = int(input("Nhập số nguyên tố q: "))

    e, d, n = generate_keys(p, q)
    print(f"\nKhóa công khai (e, n): ({e}, {n})")
    print(f"Khóa bí mật (d, n): ({d}, {n})")

    message = int(input("\nNhập thông điệp (số nguyên) để mã hóa: "))
    cipher = encrypt(message, e, n)
    print("→ Mã hóa:", cipher)

    original = decrypt(cipher, d, n)
    print("→ Giải mã:", original)

except ValueError as ve:
    print("Lỗi:", ve)
