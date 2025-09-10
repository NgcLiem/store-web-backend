def create_substitution_cipher(key):
    # Tạo bảng thay thế dựa trên khóa
    alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    substitution_table = {}
    
    for i in range(len(alphabet)):
        substitution_table[alphabet[i]] = key[i]
    
    return substitution_table

def monoalphabetic_encrypt(text, substitution_table):
    text = text.upper().replace(' ', '')
    encrypted_text = ''
    for char in text:
        if char in substitution_table:
            encrypted_text += substitution_table[char]
        else:
            encrypted_text += char  # Nếu không phải chữ cái, giữ nguyên
    return encrypted_text

def monoalphabetic_decrypt(encrypted_text, substitution_table):
    reversed_table = {v: k for k, v in substitution_table.items()}
    decrypted_text = ''
    for char in encrypted_text:
        if char in reversed_table:
            decrypted_text += reversed_table[char]
        else:
            decrypted_text += char  # Nếu không phải chữ cái, giữ nguyên
    return decrypted_text

# Nhập dữ liệu từ người dùng
key = input("Nhập khóa (một chuỗi 26 ký tự không trùng lặp): ").upper()
text = input("Nhập chuỗi văn bản cần mã hóa: ")

# Kiểm tra khóa có đúng 26 ký tự không trùng lặp
if len(key) != 26 or len(set(key)) != 26:
    print("Khóa phải chứa 26 ký tự không trùng lặp!")
else:
    substitution_table = create_substitution_cipher(key)
    encrypted_text = monoalphabetic_encrypt(text, substitution_table)
    decrypted_text = monoalphabetic_decrypt(encrypted_text, substitution_table)

    print("Encrypted Text:", encrypted_text)
    print("Decrypted Text:", decrypted_text)
