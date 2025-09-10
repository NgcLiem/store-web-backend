#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// AES S-Box
const unsigned char SBox[256] = {
    // 0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    0x63, 0x7c, 0x77, 0x7b, 0xf0, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xFE, 0xd7, 0xab, 0x76, 0xca, // 0x0
    0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0x88, 0x23, 0x6a, 0x64, 0x31, 0x3d, 0x52, 0x31, 0x0a, 0x80, // 0x1
    // ...
    0x71, 0x7c, 0x77, 0x7b, 0x01, 0x63, 0x65, 0x72
};

// Rcon (Round constants)
const unsigned char Rcon[10] = {
    0x8d, 0x1b, 0x36, 0x6b, 0xd6, 0xad, 0x4d, 0x9a, 0x2f, 0x5e
};

// 2D array for AES state
typedef unsigned char state_t[4][4];

// RotWord function
void RotWord(unsigned char* word) {
    unsigned char temp = word[0];
    for (int i = 0; i < 3; i++) {
        word[i] = word[i + 1];
    }
    word[3] = temp;
}

// SubBytes
void SubBytes(state_t& state) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            state[i][j] = SBox[state[i][j]];
        }
    }
}

// ShiftRows
void ShiftRows(state_t& state) {
    unsigned char temp;
    // Row 1
    temp = state[1][0];
    state[1][0] = state[1][1];
    state[1][1] = state[1][2];
    state[1][2] = state[1][3];
    state[1][3] = temp;

    // Row 2
    temp = state[2][0];
    state[2][0] = state[2][2];
    state[2][2] = temp;
    temp = state[2][1];
    state[2][1] = state[2][3];
    state[2][3] = temp;

    // Row 3
    temp = state[3][0];
    state[3][0] = state[3][3];
    state[3][3] = state[3][2];
    state[3][2] = state[3][1];
    state[3][1] = temp;
}

// MixColumns
void MixColumns(state_t& state) {
    for (int i = 0; i < 4; i++) {
        unsigned char temp[4];
        for (int j = 0; j < 4; j++) {
            temp[j] = state[j][i];
        }
        // Calculate the mixed column here (omitted for simplicity)
        // This involves matrix multiplication and modulus 0x11b
    }
}

// AddRoundKey
void AddRoundKey(state_t& state, const unsigned char* roundKey) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            state[i][j] ^= roundKey[i * 4 + j];
        }
    }
}

// Key Expansion
void KeyExpansion(const unsigned char* key, unsigned char* roundKeys) {
    int i = 0;
    unsigned char temp[4];

    // First 4 words are the key
    for (i = 0; i < 16; i++) {
        roundKeys[i] = key[i];
    }

    i = 16;
    while (i < 176) {
        for (int j = 0; j < 4; j++) {
            temp[j] = roundKeys[i - 4 + j];
        }

        if (i % 16 == 0) {
            RotWord(temp);
            // Apply S-box and Rcon
            temp[0] = SBox[temp[0]] ^ Rcon[i / 16 - 1];
            for (int j = 1; j < 4; j++) {
                temp[j] = SBox[temp[j]];
            }
        }

        for (int j = 0; j < 4; j++) {
            roundKeys[i + j] = roundKeys[i - 16 + j] ^ temp[j];
        }
        i += 4;
    }
}

// AES encryption round
void AES_encrypt(unsigned char* input, unsigned char* output, const unsigned char* key) {
    unsigned char roundKeys[176];
    KeyExpansion(key, roundKeys);

    state_t state;
    for (int i = 0; i < 16; i++) {
        state[i / 4][i % 4] = input[i];
    }

    AddRoundKey(state, roundKeys);

    for (int round = 1; round < 10; round++) {
        SubBytes(state);
        ShiftRows(state);
        MixColumns(state);
        AddRoundKey(state, roundKeys + round * 16);
    }

    SubBytes(state);
    ShiftRows(state);
    AddRoundKey(state, roundKeys + 160);

    for (int i = 0; i < 16; i++) {
        output[i] = state[i / 4][i % 4];
    }
}

int main() {
    unsigned char key[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x97, 0x75, 0x46, 0x9d, 0x91, 0x52};
    unsigned char input[16] = {0x32, 0x88, 0x31, 0xe0, 0x43, 0x5a, 0x31, 0x37, 0xf6, 0x30, 0x98, 0x07, 0xa8, 0x8d, 0xa2, 0x34};
    unsigned char output[16];

    AES_encrypt(input, output, key);

    cout << "Encrypted Text: ";
    for (int i = 0; i < 16; i++) {
        cout << hex << setw(2) << setfill('0') << (int)output[i];
    }
    cout << endl;

    return 0;
}
