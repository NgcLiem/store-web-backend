#include <iostream>
#include <string>
using namespace std;

// Hàm mã hóa Caesar
string encryptCaesar(string text, int shift) {
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + shift) % 26 + base;
        }
        result += c;
    }
    return result;
}

// Hàm giải mã Caesar
string decryptCaesar(string text, int shift) {
    return encryptCaesar(text, 26 - shift); // Giải mã là mã hóa với dịch ngược lại
}

int main() {
    string plainText;
    int shift;

    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, plainText);

    cout << "Nhap so buoc dich (0-25): ";
    cin >> shift;

    string encrypted = encryptCaesar(plainText, shift);
    string decrypted = decryptCaesar(encrypted, shift);

    cout << "Chuoi da ma hoa: " << encrypted << endl;
    cout << "Chuoi da giai ma: " << decrypted << endl;

    return 0;
}
