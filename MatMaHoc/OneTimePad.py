import random

def xor_cipher(text, key):
    return ''.join(chr(ord(t) ^ ord(k)) for t, k in zip(text, key))

def generate_key(length):
    return ''.join(chr(random.randint(0, 255)) for _ in range(length))

def one_time_pad_encrypt_decrypt(text):
    # Tạo khóa với độ dài bằng độ dài của chuỗi
    key = generate_key(len(text))
    encrypted_text = xor_cipher(text, key)
    decrypted_text = xor_cipher(encrypted_text, key)
    return encrypted_text, decrypted_text, key

# Example usage
text = "LIEM"
encrypted_text, decrypted_text, key = one_time_pad_encrypt_decrypt(text)
print("One Time Pad Encrypted:", encrypted_text)
print("One Time Pad Decrypted:", decrypted_text)
