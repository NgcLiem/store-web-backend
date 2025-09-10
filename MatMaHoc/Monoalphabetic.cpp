#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>
using namespace std;

// Bảng thay thế đơn giản: A -> Q, B -> W, C -> E, ..., Z -> M (có thể tùy chỉnh)
const string originalAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string substitutionKey   = "QWERTYUIOPASDFGHJKLZXCVBNM"; 

// Mã hóa
string encryptMonoalphabetic(const string& plainText) {
    string result = "";
    for (char c : plainText) {
        if (isalpha(c)) {
            bool isUpper = isupper(c);
            char upperChar = toupper(c);
            size_t index = originalAlphabet.find(upperChar);
            char encryptedChar = substitutionKey[index];
            result += isUpper ? encryptedChar : tolower(encryptedChar);
        } else {
            result += c; 
        }
    }
    return result;
}

// Giải mã
string decryptMonoalphabetic(const string& cipherText) {
    string result = "";
    for (char c : cipherText) {
        if (isalpha(c)) {
            bool isUpper = isupper(c);
            char upperChar = toupper(c);
            size_t index = substitutionKey.find(upperChar);
            char decryptedChar = originalAlphabet[index];
            result += isUpper ? decryptedChar : tolower(decryptedChar);
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string text;
    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, text);

    string encrypted = encryptMonoalphabetic(text);
    string decrypted = decryptMonoalphabetic(encrypted);

    cout << "Chuoi da ma hoa: " << encrypted << endl;
    cout << "Chuoi da giai ma: " << decrypted << endl;

    return 0;
}
