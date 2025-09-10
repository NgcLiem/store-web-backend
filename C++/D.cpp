#include <iostream>
#include <unordered_set>
#include <vector>

bool hasPairWithSum(const std::vector<int>& A, int K) {
    std::unordered_set<int> complements;

    for (int i = 0; i < A.size(); ++i) {
        int complement = K - A[i];
        if (complements.find(complement) != complements.end()) {
            return true; // Tìm thấy cặp (i, j)
        }
        complements.insert(A[i]);
    }

    return false; // Không tìm thấy cặp nào
}

int main() {
    int N, K;
    std::cout << "Nhập số phần tử của mảng N: ";
    std::cin >> N;

    std::vector<int> A(N);
    std::cout << "Nhập các phần tử của mảng A: ";
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    std::cout << "Nhập giá trị K: ";
    std::cin >> K;

    if (hasPairWithSum(A, K)) {
        std::cout << "Tồn tại cặp (i, j) sao cho A[i] + A[j] = " << K << std::endl;
    } else {
        std::cout << "Không tồn tại cặp (i, j) nào có tổng bằng " << K << std::endl;
    }

    return 0;
}