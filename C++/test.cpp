#include <iostream>

// Định nghĩa cấu trúc của một nút trong danh sách liên kết đơn
struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

// Hàm thêm một phần tử vào đầu danh sách liên kết đơn
void addToFront(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Hàm in ra tất cả các phần tử trong danh sách liên kết đơn
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Khởi tạo danh sách liên kết đơn
    Node* head = nullptr;

    // Thêm các phần tử vào đầu danh sách liên kết đơn
    addToFront(head, 3);
    addToFront(head, 2);
    addToFront(head, 1);

    // In ra danh sách liên kết đơn sau khi thêm
    std::cout << "Danh sach lien ket don sau khi them: ";
    printList(head);

    return 0;
}