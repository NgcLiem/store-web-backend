#include <iostream>
#include <string>
using namespace std;

// Hàm XOR Cipher
string xorCipher(const string& text, char key) {
    string result = "";
    for (char c : text) {
        result += c ^ key; // XOR từng ký tự với key
    }
    return result;
}

int main() {
    string plainText;
    char key;

    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, plainText);

    cout << "Nhap mot ky tu khoa (key): ";
    cin >> key;

    // Mã hóa
    string encrypted = xorCipher(plainText, key);
    cout << "\nChuoi da ma hoa (dang ma ASCII): ";
    for (char c : encrypted) cout << (int)c << ' ';

    // Giải mã
    string decrypted = xorCipher(encrypted, key);
    cout << "\nChuoi da giai ma: " << decrypted << endl;

    return 0;
}
