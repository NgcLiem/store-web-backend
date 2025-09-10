def matrix_multiply(mat, vec):
    # Thực hiện phép nhân ma trận 2x2 với vector 2 chiều
    return [
        (mat[0][0] * vec[0] + mat[0][1] * vec[1]) % 26,
        (mat[1][0] * vec[0] + mat[1][1] * vec[1]) % 26
    ]

def hill_encrypt(text, key):
    text = text.upper().replace(' ', '')
    encrypted_text = ''
    for i in range(0, len(text), 2):
        # Chia chuỗi thành các cặp 2 ký tự
        chunk = [ord(text[i]) - 65, ord(text[i+1]) - 65]
        # Thực hiện nhân ma trận với vector
        result = matrix_multiply(key, chunk)
        # Chuyển kết quả trở lại thành ký tự
        encrypted_text += chr(result[0] + 65) + chr(result[1] + 65)
    return encrypted_text

# Nhập dữ liệu từ người dùng
key = []
print("Nhập ma trận khóa 2x2:")
for i in range(2):
    row = list(map(int, input(f"Nhập hàng {i+1} (cách nhau bởi dấu cách): ").split()))
    key.append(row)

text = input("Nhập chuỗi văn bản cần mã hóa: ")
print("Hill Cipher Encrypted:", hill_encrypt(text, key))
