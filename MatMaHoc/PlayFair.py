def generate_playfair_matrix(key):
    # Xử lý khóa: loại bỏ các ký tự trùng lặp và thay 'J' bằng 'I'
    key = ''.join(dict.fromkeys(key.upper().replace('J', 'I')))
    matrix = []
    alphabet = 'ABCDEFGHIKLMNOPQRSTUVWXYZ'
    
    for char in key:
        if char not in matrix:
            matrix.append(char)
    
    for char in alphabet:
        if char not in matrix:
            matrix.append(char)
    
    return matrix

def find_position(matrix, char):
    index = matrix.index(char)
    return index // 5, index % 5

def prepare_text(text):
    # Chuẩn hóa văn bản: thay 'J' bằng 'I' và nếu có 1 ký tự lẻ thì thêm 'X'
    text = text.upper().replace('J', 'I')
    prepared_text = ''
    i = 0
    while i < len(text):
        prepared_text += text[i]
        if i + 1 < len(text) and text[i] == text[i + 1]:
            prepared_text += 'X'
        elif i + 1 == len(text):
            prepared_text += 'X'
        else:
            prepared_text += text[i + 1]
            i += 1
        i += 1
    return prepared_text

def playfair_encrypt(text, key):
    matrix = generate_playfair_matrix(key)
    prepared_text = prepare_text(text)
    encrypted_text = ''
    
    for i in range(0, len(prepared_text), 2):
        first, second = prepared_text[i], prepared_text[i + 1]
        row1, col1 = find_position(matrix, first)
        row2, col2 = find_position(matrix, second)
        
        if row1 == row2:
            encrypted_text += matrix[row1 * 5 + (col1 + 1) % 5]
            encrypted_text += matrix[row2 * 5 + (col2 + 1) % 5]
        elif col1 == col2:
            encrypted_text += matrix[((row1 + 1) % 5) * 5 + col1]
            encrypted_text += matrix[((row2 + 1) % 5) * 5 + col2]
        else:
            encrypted_text += matrix[row1 * 5 + col2]
            encrypted_text += matrix[row2 * 5 + col1]
    
    return encrypted_text

def playfair_decrypt(text, key):
    matrix = generate_playfair_matrix(key)
    prepared_text = text
    decrypted_text = ''
    
    for i in range(0, len(prepared_text), 2):
        first, second = prepared_text[i], prepared_text[i + 1]
        row1, col1 = find_position(matrix, first)
        row2, col2 = find_position(matrix, second)
        
        if row1 == row2:
            decrypted_text += matrix[row1 * 5 + (col1 - 1) % 5]
            decrypted_text += matrix[row2 * 5 + (col2 - 1) % 5]
        elif col1 == col2:
            decrypted_text += matrix[((row1 - 1) % 5) * 5 + col1]
            decrypted_text += matrix[((row2 - 1) % 5) * 5 + col2]
        else:
            decrypted_text += matrix[row1 * 5 + col2]
            decrypted_text += matrix[row2 * 5 + col1]
    
    return decrypted_text.replace('X', '')

# Nhập dữ liệu từ người dùng
key = input("Nhập khóa Playfair: ")
text = input("Nhập chuỗi văn bản cần mã hóa: ")

encrypted_text = playfair_encrypt(text, key)
decrypted_text = playfair_decrypt(encrypted_text, key)

print("Playfair Cipher Encrypted:", encrypted_text)
print("Playfair Cipher Decrypted:", decrypted_text)
