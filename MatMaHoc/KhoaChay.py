def running_key_encrypt(plaintext, key):
    result = ''
    if len(plaintext) != len(key):
        return "Lỗi: Khóa phải có độ dài bằng chuỗi mã hóa."
    for i in range(len(plaintext)):
        p = ord(plaintext[i].upper()) - 65
        k = ord(key[i].upper()) - 65
        c = (p + k) % 26
        result += chr(c + 65)
    return result

def running_key_decrypt(ciphertext, key):
    result = ''
    if len(ciphertext) != len(key):
        return "Lỗi: Khóa phải có độ dài bằng chuỗi mã hóa."
    for i in range(len(ciphertext)):
        c = ord(ciphertext[i].upper()) - 65
        k = ord(key[i].upper()) - 65
        p = (c - k + 26) % 26
        result += chr(p + 65)
    return result

# Nhập dữ liệu từ người dùng
plaintext = input("Nhập chuỗi văn bản cần mã hóa: ")
key = input("Nhập khóa (độ dài khóa phải bằng với độ dài chuỗi): ")

encrypted_text = running_key_encrypt(plaintext, key)
decrypted_text = running_key_decrypt(encrypted_text, key)
print("Running Key Cipher Encrypted:", encrypted_text)
print("Running Key Cipher Decrypted:", decrypted_text)
