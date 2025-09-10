#include <iostream>
#include <vector>

using namespace std;

void RC4(const vector<unsigned char>& key, const vector<unsigned char>& data, vector<unsigned char>& output) {
    int S[256], T[256];
    int i = 0, j = 0;

    // Khởi tạo S
    for (int i = 0; i < 256; i++) {
        S[i] = i;
        T[i] = key[i % key.size()];
    }

    // Trộn S
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + T[i]) % 256;
        swap(S[i], S[j]);
    }

    // Mã hóa
    i = 0;
    j = 0;
    for (int k = 0; k < data.size(); k++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        swap(S[i], S[j]);
        int K = S[(S[i] + S[j]) % 256];
        output.push_back(data[k] ^ K);
    }
}

int main() {
    vector<unsigned char> key = { 1, 2, 3, 4, 5, 6, 7, 8 };
    vector<unsigned char> data = { 'H', 'e', 'l', 'l', 'o' };
    vector<unsigned char> encryptedData;
    
    RC4(key, data, encryptedData);

    cout << "Encrypted: ";
    for (auto& byte : encryptedData) {
        cout << byte;
    }
    cout << endl;

    // Decrypting (RC4 is symmetric)
    vector<unsigned char> decryptedData;
    RC4(key, encryptedData, decryptedData);

    cout << "Decrypted: ";
    for (auto& byte : decryptedData) {
        cout << byte;
    }
    cout << endl;

    return 0;
}
