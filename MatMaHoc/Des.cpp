#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const vector<int> IP = {58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4,
                        62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8,
                        57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3,
                        61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};

const vector<int> IP_inv = {40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31,
                            38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29,
                            36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27,
                            34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25};

vector<int> permute(const vector<int>& data, const vector<int>& table) {
    vector<int> result(table.size());
    for (size_t i = 0; i < table.size(); ++i) {
        result[i] = data[table[i] - 1];
    }
    return result;
}

vector<int> xorBits(const vector<int>& a, const vector<int>& b) {
    vector<int> result(a.size());
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = a[i] ^ b[i];
    }
    return result;
}

vector<int> desEncrypt(const vector<int>& data, const vector<int>& key) {
    vector<int> permutedData = permute(data, IP);
    vector<int> left(permutedData.begin(), permutedData.begin() + 32);
    vector<int> right(permutedData.begin() + 32, permutedData.end());
    
    // Vòng mã hóa DES ở đây
    for (int i = 0; i < 16; ++i) {
        // DES Round logic: mở rộng, XOR, thay thế bằng S-box, P4 permutation, ...
        // Chú ý: Mã này cần được hoàn thiện thêm
    }
    
    // Kết hợp nửa trái và nửa phải, áp dụng hoán vị cuối
    vector<int> finalData;
    finalData.insert(finalData.end(), left.begin(), left.end());
    finalData.insert(finalData.end(), right.begin(), right.end());
    return permute(finalData, IP_inv);
}

int main() {
    vector<int> data = {1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1};
    vector<int> key = {1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1};
    
    vector<int> encryptedData = desEncrypt(data, key);
    for (int bit : encryptedData) {
        cout << bit;
    }
    cout << endl;
    
    return 0;
}
