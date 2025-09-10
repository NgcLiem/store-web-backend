def xor_cipher(text, key):
    return ''.join(chr(ord(t) ^ ord(key)) for t in text)

# Nhập dữ liệu từ người dùng
text = input("Nhập chuỗi văn bản cần mã hóa: ")
key = input("Nhập khóa (một ký tự): ")

encrypted_text = xor_cipher(text, key)
decrypted_text = xor_cipher(encrypted_text, key)
print("XOR Cipher Encrypted:", encrypted_text)
print("XOR Cipher Decrypted:", decrypted_text)
