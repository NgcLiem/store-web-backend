#include <iostream>
#include <algorithm>

void nextPermutation(int arr[], int n) {
    // Bước 1
    int i = n - 2;
    while (i >= 0 && arr[i] >= arr[i + 1]) {
        i--;
    }

    // Bước 2
    if (i >= 0) {
        int j = n - 1;
        while (arr[j] <= arr[i]) {
            j--;
        }

        // Bước 3
        std::swap(arr[i], arr[j]);
    }

    // Bước 4
    std::reverse(arr + i + 1, arr + n);
}

int main() {
    int n = 4;
    int arr[] = {1, 2, 3, 4};

    std::cout << "Current permutation: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    // Tạo hoán vị kế tiếp
    nextPermutation(arr, n);

    std::cout << "Next permutation: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}