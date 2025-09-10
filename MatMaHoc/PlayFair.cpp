#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int SIZE = 5;

// Tạo ma trận khóa từ khóa nhập vào
vector<vector<char>> generateMatrix(const string& key) {
    string temp = "";
    bool used[26] = { false };

    for (char c : key) {
        c = toupper(c);
        if (c == 'J') c = 'I';
        if (!used[c - 'A'] && isalpha(c)) {
            temp += c;
            used[c - 'A'] = true;
        }
    }

    // Thêm các chữ cái còn thiếu
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue; // Gộp I và J
        if (!used[c - 'A']) {
            temp += c;
            used[c - 'A'] = true;
        }
    }

    vector<vector<char>> matrix(SIZE, vector<char>(SIZE));
    for (int i = 0; i < SIZE * SIZE; i++) {
        matrix[i / SIZE][i % SIZE] = temp[i];
    }

    return matrix;
}

// Tìm vị trí của ký tự trong ma trận
void findPosition(const vector<vector<char>>& matrix, char c, int& row, int& col) {
    if (c == 'J') c = 'I';
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            if (matrix[i][j] == c) {
                row = i;
                col = j;
                return;
            }
}

// Xử lý cặp ký tự để mã hóa
string processPair(const vector<vector<char>>& matrix, char a, char b) {
    int row1, col1, row2, col2;
    findPosition(matrix, a, row1, col1);
    findPosition(matrix, b, row2, col2);

    if (row1 == row2) {
        return string(1, matrix[row1][(col1 + 1) % SIZE]) +
               string(1, matrix[row2][(col2 + 1) % SIZE]);
    }
    else if (col1 == col2) {
        return string(1, matrix[(row1 + 1) % SIZE][col1]) +
               string(1, matrix[(row2 + 1) % SIZE][col2]);
    }
    else {
        return string(1, matrix[row1][col2]) +
               string(1, matrix[row2][col1]);
    }
}

// Mã hóa Playfair
string encryptPlayfair(string text, const string& key) {
    // Tiền xử lý văn bản
    string processed = "";
    for (char c : text) {
        if (isalpha(c)) {
            c = toupper(c);
            if (c == 'J') c = 'I';
            processed += c;
        }
    }

    // Chia thành cặp
    string fixed = "";
    for (size_t i = 0; i < processed.length(); ++i) {
        fixed += processed[i];
        if (i + 1 < processed.length() && processed[i] == processed[i + 1]) {
            fixed += 'X'; // Thêm X nếu 2 chữ giống nhau
        }
        else if (i + 1 < processed.length()) {
            fixed += processed[++i];
        }
    }

    if (fixed.length() % 2 != 0)
        fixed += 'X'; // Nếu lẻ thì thêm X

    // Mã hóa
    vector<vector<char>> matrix = generateMatrix(key);
    string encrypted = "";

    for (size_t i = 0; i < fixed.length(); i += 2) {
        encrypted += processPair(matrix, fixed[i], fixed[i + 1]);
    }

    return encrypted;
}

int main() {
    string key, text;

    cout << "Nhap khoa (key): ";
    getline(cin, key);

    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, text);

    string encrypted = encryptPlayfair(text, key);

    cout << "\nChuoi da ma hoa: " << encrypted << endl;
}