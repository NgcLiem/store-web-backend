#include <iostream>
#include <string>
using namespace std;

// Chuyển ký tự thành số (A=0, ..., Z=25)
int charToInt(char c) {
    return toupper(c) - 'A';
}

// Chuyển số thành ký tự
char intToChar(int n) {
    return 'A' + (n % 26);
}

// Mã hóa
string encryptRunningKey(const string& plainText, const string& runningKey) {
    string cipherText = "";
    for (size_t i = 0; i < plainText.length(); ++i) {
        char p = toupper(plainText[i]);
        char k = toupper(runningKey[i]);
        if (isalpha(p) && isalpha(k)) {
            int c = (charToInt(p) + charToInt(k)) % 26;
            cipherText += intToChar(c);
        } else {
            cipherText += p;
        }
    }
    return cipherText;
}

// Giải mã
string decryptRunningKey(const string& cipherText, const string& runningKey) {
    string plainText = "";
    for (size_t i = 0; i < cipherText.length(); ++i) {
        char c = toupper(cipherText[i]);
        char k = toupper(runningKey[i]);
        if (isalpha(c) && isalpha(k)) {
            int p = (charToInt(c) - charToInt(k) + 26) % 26;
            plainText += intToChar(p);
        } else {
            plainText += c;
        }
    }
    return plainText;
}

int main() {
    string plainText, key;

    cout << "Nhap chuoi can ma hoa (chi chu cai): ";
    getline(cin, plainText);

    cout << "Nhap khoa chay (do dai >= chuoi can ma hoa): ";
    getline(cin, key);

    if (key.length() < plainText.length()) {
        cout << "Loi: Khoa chay phai dai hon hoac bang chuoi can ma hoa.\n";
        return 1;
    }

    string encrypted = encryptRunningKey(plainText, key);
    string decrypted = decryptRunningKey(encrypted, key);

    cout << "Chuoi da ma hoa: " << encrypted;
    cout << "\nChuoi da giai ma: " << decrypted << endl;

    return 0;
}
