import struct
import math

S = [7, 12, 17, 22] * 4 + [5, 9, 14, 20] * 4 + [4, 11, 16, 23] * 4 + [6, 10, 15, 21] * 4
K = [int(abs(math.sin(i + 1)) * (2**32)) & 0xFFFFFFFF for i in range(64)]

def left_rotate(x, c):
    return ((x << c) | (x >> (32 - c))) & 0xFFFFFFFF

def md5(message):
    message = bytearray(message.encode('utf-8'))
    original_len = (8 * len(message)) & 0xFFFFFFFFFFFFFFFF
    message.append(0x80)

    while len(message) % 64 != 56:
        message.append(0)

    message += struct.pack('<Q', original_len)

    A = 0x67452301
    B = 0xefcdab89
    C = 0x98badcfe
    D = 0x10325476

    for chunk_offset in range(0, len(message), 64):
        chunk = message[chunk_offset:chunk_offset+64]
        M = list(struct.unpack('<16I', chunk))

        a, b, c, d = A, B, C, D

        for i in range(64):
            if 0 <= i <= 15:
                f = (b & c) | (~b & d)
                g = i
            elif 16 <= i <= 31:
                f = (d & b) | (~d & c)
                g = (5 * i + 1) % 16
            elif 32 <= i <= 47:
                f = b ^ c ^ d
                g = (3 * i + 5) % 16
            else:
                f = c ^ (b | ~d)
                g = (7 * i) % 16

            temp = d
            d = c
            c = b
            b = (b + left_rotate((a + f + K[i] + M[g]) & 0xFFFFFFFF, S[i])) & 0xFFFFFFFF
            a = temp

        A = (A + a) & 0xFFFFFFFF
        B = (B + b) & 0xFFFFFFFF
        C = (C + c) & 0xFFFFFFFF
        D = (D + d) & 0xFFFFFFFF

    return ''.join(f'{x:02x}' for x in struct.pack('<4I', A, B, C, D))

# === CHẠY CHƯƠNG TRÌNH ===
chuoi = input("Nhập chuỗi để băm MD5: ")
hash_result = md5(chuoi)
print(f"→ MD5('{chuoi}') = {hash_result}")
