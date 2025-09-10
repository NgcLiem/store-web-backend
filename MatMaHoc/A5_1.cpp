#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

// Định nghĩa ba bộ LFSR
class LFSR {
public:
    vector<int> register_bits;
    vector<int> feedback_taps;

    LFSR(int size, vector<int> taps) {
        register_bits = vector<int>(size, 0);
        feedback_taps = taps;
    }

    void set_initial_state(const vector<int>& state) {
        register_bits = state;
    }

    int shift() {
        // Tính toán bit phản hồi từ các taps
        int feedback = 0;
        for (int tap : feedback_taps) {
            feedback ^= register_bits[tap];
        }

        // Dịch chuyển bit và đưa feedback vào đầu
        int output_bit = register_bits[0];
        register_bits.erase(register_bits.begin());
        register_bits.push_back(feedback);

        return output_bit;
    }

    int get_output() {
        return register_bits[register_bits.size() - 1];
    }
};

// Chức năng A5/1
vector<int> A5_1_encrypt(const vector<int>& key, const vector<int>& input_data) {
    // Khởi tạo ba LFSR với chiều dài và các tap khác nhau
    LFSR R1(19, {0, 1, 2, 3, 4});
    LFSR R2(22, {0, 1, 2, 3, 4, 5, 6});
    LFSR R3(23, {0, 1, 2, 3, 4, 5, 6, 7, 8});

    // Cài đặt giá trị ban đầu cho LFSR (key được giả định là đúng kích thước)
    R1.set_initial_state({key.begin(), key.begin() + 19});
    R2.set_initial_state({key.begin() + 19, key.begin() + 41});
    R3.set_initial_state({key.begin() + 41, key.begin() + 64});

    vector<int> keystream;

    // Kết hợp các LFSR để tạo ra keystream (vòng lặp cho đến khi đủ số bit cần thiết)
    for (int i = 0; i < input_data.size(); i++) {
        // Dịch chuyển các LFSR
        int output_R1 = R1.shift();
        int output_R2 = R2.shift();
        int output_R3 = R3.shift();

        // Quy tắc chọn bit từ các LFSR để kết hợp
        int majority = output_R1 + output_R2 + output_R3;

        // Nếu đa số là 1, chọn 1, ngược lại chọn 0
        keystream.push_back(majority >= 2 ? 1 : 0);
    }

    // XOR keystream với dữ liệu đầu vào
    vector<int> encrypted_data(input_data.size());
    for (int i = 0; i < input_data.size(); i++) {
        encrypted_data[i] = input_data[i] ^ keystream[i];
    }

    return encrypted_data;
}

int main() {
    // Ví dụ khóa A5/1 (64-bit)
    vector<int> key = {1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0};

    // Dữ liệu đầu vào (ví dụ: văn bản hoặc dữ liệu nhị phân cần mã hóa)
    vector<int> input_data = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0};

    // Mã hóa dữ liệu với A5/1
    vector<int> encrypted_data = A5_1_encrypt(key, input_data);

    // In kết quả mã hóa
    cout << "Encrypted Data: ";
    for (int bit : encrypted_data) {
        cout << bit;
    }
    cout << endl;

    return 0;
}
