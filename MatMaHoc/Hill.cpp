#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 26;

// Nhân ma trận 2x2 với vector 2x1
vector<int> multiplyMatrix(const vector<vector<int>>& key, const vector<int>& vec) {
    vector<int> result(2);
    result[0] = (key[0][0] * vec[0] + key[0][1] * vec[1]) % MOD;
    result[1] = (key[1][0] * vec[0] + key[1][1] * vec[1]) % MOD;
    return result;
}

// Chuyển ký tự về số (A=0, B=1,..., Z=25)
int charToInt(char c) {
    return toupper(c) - 'A';
}

// Chuyển số về ký tự
char intToChar(int i) {
    return 'A' + (i % MOD);
}

// Mã hóa Hill Cipher
string encryptHill(const string& text, const vector<vector<int>>& key) {
    string processed = "";
    for (char c : text)
        if (isalpha(c)) processed += toupper(c);

    // Đảm bảo độ dài là bội số của 2
    if (processed.length() % 2 != 0)
        processed += 'X';

    string encrypted = "";
    for (size_t i = 0; i < processed.length(); i += 2) {
        vector<int> vec = { charToInt(processed[i]), charToInt(processed[i + 1]) };
        vector<int> enc = multiplyMatrix(key, vec);
        encrypted += intToChar(enc[0]);
        encrypted += intToChar(enc[1]);
    }

    return encrypted;
}

int main() {
    string text;
    vector<vector<int>> key(2, vector<int>(2));

    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, text);

    cout << "Nhap ma tran khoa 2x2 (4 so nguyen 0-25):\n";
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> key[i][j];

    string encrypted = encryptHill(text, key);
    cout << "Chuoi da ma hoa: " << encrypted << endl;

    return 0;
}
