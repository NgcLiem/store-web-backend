#include <iostream>
#include <string>
using namespace std;

// Chuyển ký tự thành số (A=0, B=1, ..., Z=25)
int charToInt(char c) {
    return toupper(c) - 'A';
}

// Chuyển số thành ký tự
char intToChar(int i) {
    return 'A' + (i % 26);
}

// Mã hóa OTP
string encryptOTP(const string& plainText, const string& key) {
    string result = "";
    for (size_t i = 0; i < plainText.length(); ++i) {
        char p = toupper(plainText[i]);
        char k = toupper(key[i]);
        if (isalpha(p)) {
            int enc = (charToInt(p) + charToInt(k)) % 26;
            result += intToChar(enc);
        } else {
            result += p;
        }
    }
    return result;
}

// Giải mã OTP
string decryptOTP(const string& cipherText, const string& key) {
    string result = "";
    for (size_t i = 0; i < cipherText.length(); ++i) {
        char c = toupper(cipherText[i]);
        char k = toupper(key[i]);
        if (isalpha(c)) {
            int dec = (charToInt(c) - charToInt(k) + 26) % 26;
            result += intToChar(dec);
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string plainText, key;

    cout << "Nhap chuoi can ma hoa (chi gom chu cai): ";
    getline(cin, plainText);

    cout << "Nhap khoa (phai co do dai bang chuoi can ma hoa): ";
    getline(cin, key);

    if (key.length() != plainText.length()) {
        cout << "Loi: Do dai khoa phai bang do dai chuoi!" << endl;
        return 1;
    }

    string encrypted = encryptOTP(plainText, key);
    string decrypted = decryptOTP(encrypted, key);

    cout << "\nChuoi da ma hoa: " << encrypted << endl;
    cout << "Chuoi da giai ma: " << decrypted << endl;

    return 0;
}
