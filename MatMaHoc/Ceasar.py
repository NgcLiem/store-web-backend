def caesar_cipher(text, shift):
    result = ""
    for char in text:
        if char.isalpha():
            shift_base = 65 if char.isupper() else 97
            result += chr((ord(char) - shift_base + shift) % 26 + shift_base)
        else:
            result += char
    return result

# Nhập dữ liệu bằng tay
text = input("Nhập chuỗi cần mã hóa: ")
shift = int(input("Nhập độ dịch chuyển (shift): "))
encrypted_text = caesar_cipher(text, shift)
print("Chuỗi mã hóa Caesar:", encrypted_text)
