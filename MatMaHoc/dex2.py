# --- Các bảng chuẩn DES ---
IP = [58, 50, 42, 34, 26, 18, 10, 2,
      60, 52, 44, 36, 28, 20, 12, 4,
      62, 54, 46, 38, 30, 22, 14, 6,
      64, 56, 48, 40, 32, 24, 16, 8,
      57, 49, 41, 33, 25, 17,  9, 1,
      59, 51, 43, 35, 27, 19, 11, 3,
      61, 53, 45, 37, 29, 21, 13, 5,
      63, 55, 47, 39, 31, 23, 15, 7]

PC1 = [57, 49, 41, 33, 25, 17, 9,
        1, 58, 50, 42, 34, 26, 18,
       10, 2, 59, 51, 43, 35, 27,
       19, 11, 3, 60, 52, 44, 36,
       63, 55, 47, 39, 31, 23, 15,
        7, 62, 54, 46, 38, 30, 22,
       14, 6, 61, 53, 45, 37, 29,
       21, 13, 5, 28, 20, 12, 4]

PC2 = [14, 17, 11, 24, 1, 5,
        3, 28, 15, 6, 21, 10,
       23, 19, 12, 4, 26, 8,
       16, 7, 27, 20, 13, 2,
       41, 52, 31, 37, 47, 55,
       30, 40, 51, 45, 33, 48,
       44, 49, 39, 56, 34, 53,
       46, 42, 50, 36, 29, 32]

SHIFT_SCHEDULE = [1, 1, 2, 2, 2, 2, 2, 2,
                  1, 2, 2, 2, 2, 2, 2, 1]

E = [32, 1, 2, 3, 4, 5, 4, 5,
     6, 7, 8, 9, 8, 9, 10, 11,
    12, 13, 12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21, 20, 21,
    22, 23, 24, 25, 24, 25, 26, 27,
    28, 29, 28, 29, 30, 31, 32, 1]

S_BOX = [
    # S-box 1
    [[14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7],
     [0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8],
     [4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0],
     [15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13]],

    # S-box 2
    [[15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10],
     [3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5],
     [0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15],
     [13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9]],

    # S-box 3
    [[10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8],
     [13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1],
     [13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7],
     [1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12]],

    # S-box 4
    [[7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15],
     [13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9],
     [10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4],
     [3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14]],

    # S-box 5
    [[2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9],
     [14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6],
     [4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14],
     [11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3]],

    # S-box 6
    [[12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11],
     [10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8],
     [9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6],
     [4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13]],

    # S-box 7
    [[4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1],
     [13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6],
     [1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2],
     [6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12]],

    # S-box 8
    [[13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7],
     [1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2],
     [7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8],
     [2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11]]
]

P = [16, 7, 20, 21, 29, 12, 28, 17,
     1, 15, 23, 26, 5, 18, 31, 10,
     2, 8, 24, 14, 32, 27, 3, 9,
     19, 13, 30, 6, 22, 11, 4, 25]

# --- Hàm phụ ---
def permute(block, table):
    return ''.join(block[i - 1] for i in table)

def left_shift(bits, n):
    return bits[n:] + bits[:n]

def xor(a, b):
    return ''.join('0' if i == j else '1' for i, j in zip(a, b))

def sbox_substitution(bits):
    output = ''
    for i in range(8):
        chunk = bits[i*6:(i+1)*6]
        row = int(chunk[0] + chunk[5], 2)
        col = int(chunk[1:5], 2)
        val = S_BOX[i][row][col]
        output += f'{val:04b}'
    return output

def feistel(R, K):
    expanded = permute(R, E)
    xored = xor(expanded, K)
    sbox_out = sbox_substitution(xored)
    return permute(sbox_out, P)

# --- Sinh khóa và in C0, D0, C1, D1, K1, K2 ---
def generate_keys(key64):
    key = permute(key64, PC1)
    C = key[:28]
    D = key[28:]

    print(f"\n PC-1 Key: {key}")
    print(f"C0: {C}")
    print(f"D0: {D}")

    keys = []
    for i, shift in enumerate(SHIFT_SCHEDULE):
        C = left_shift(C, shift)
        D = left_shift(D, shift)
        round_key = permute(C + D, PC2)
        keys.append(round_key)

        if i == 0:
            print(f"\n Round 1 Shift:")
            print(f"C1: {C}")
            print(f"D1: {D}")
            print(f"K1: {round_key}")
        elif i == 1:
            print(f"\n Round 2 Shift:")
            print(f"K2: {round_key}")

    return keys

# --- DES vòng 1 có debug ---
def des_round1_debug(plain64, key64, label="BLOCK"):
    print(f"\n===  DES ROUND 1 - {label} ===")
    print(f"Plaintext (BIN): {plain64}")
    print(f"Key      (BIN): {key64}")
    print("=" * 60)

    keys = generate_keys(key64)
    text = permute(plain64, IP)
    L0, R0 = text[:32], text[32:]
    print(f"\n L0: {L0}")
    print(f" R0: {R0}")

    L1 = R0
    R1 = xor(L0, feistel(R0, keys[0]))
    print(f"\n L1: {L1}")
    print(f" R1: {R1}")

# --- Hỗ trợ nhập tối đa 16 ký tự ---
def ascii_to_bin64(s):
    s = s.ljust(8, '\x00')[:8]
    return ''.join(f'{ord(c):08b}' for c in s)

# --- Nhập dữ liệu ---
plaintext = input(" Nhập plaintext (tối đa 16 ký tự): ").strip()
key       = input(" Nhập key       (tối đa 16 ký tự): ").strip()

plaintext = plaintext.ljust(16, '\x00')[:16]
key       = key.ljust(16, '\x00')[:16]

# Chia thành 2 block 64-bit
plain_block1 = ascii_to_bin64(plaintext[:8])
plain_block2 = ascii_to_bin64(plaintext[8:])

key_block1 = ascii_to_bin64(key[:8])
key_block2 = ascii_to_bin64(key[8:])

print(f"\n Plaintext blocks: \"{plaintext[:8]}\" & \"{plaintext[8:]}\"")
print(f" Key blocks      : \"{key[:8]}\" & \"{key[8:]}\"")

# Mã hóa từng block
des_round1_debug(plain_block1, key_block1, label="BLOCK 1")
des_round1_debug(plain_block2, key_block2, label="BLOCK 2")