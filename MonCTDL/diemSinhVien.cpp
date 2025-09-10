#include <iostream>
#include <string>

// Định nghĩa cấu trúc SinhVien
struct DiemSinhVien {
    int maSinhVien;
    std::string monHoc;
    float diem;
    DiemSinhVien* next;

    // Constructor
    DiemSinhVien(int maSV, std::string mon, float d) : maSinhVien(maSV), monHoc(mon), diem(d), next(nullptr) {}
};

// Hàm thêm điểm sinh viên vào cuối danh sách liên kết đơn
void themDiemSinhVienVaoCuoi(DiemSinhVien*& head, int maSV, std::string mon, float diem) {
    DiemSinhVien* newNode = new DiemSinhVien(maSV, mon, diem);
    
    if (head == nullptr) {
        head = newNode;
        return;
    }

    DiemSinhVien* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Hàm in ra tất cả các điểm sinh viên trong danh sách liên kết đơn
void inDanhSachDiemSinhVien(DiemSinhVien* head) {
    while (head != nullptr) {
        std::cout << "Ma SV: " << head->maSinhVien << ", Mon hoc: " << head->monHoc << ", Diem: " << head->diem << std::endl;
        head = head->next;
    }
}

int main() {
    // Khởi tạo đầu danh sách liên kết đơn
    DiemSinhVien* head = nullptr;

    // Nhập dữ liệu từ bàn phím và thêm điểm sinh viên vào danh sách
    int maSV;
    std::string monHoc;
    float diem;

    char tiepTuc;
    do {
        std::cout << "Nhap ma sinh vien: ";
        std::cin >> maSV;
        std::cout << "Nhap mon hoc: ";
        std::cin >> monHoc;
        std::cout << "Nhap diem: ";
        std::cin >> diem;

        themDiemSinhVienVaoCuoi(head, maSV, monHoc, diem);

        std::cout << "Ban muon nhap them diem cho sinh vien khac? (Y/N): ";
        std::cin >> tiepTuc;
    } while (tiepTuc == 'Y' || tiepTuc == 'y');

    // In ra danh sách điểm sinh viên
    std::cout << "Danh sach diem sinh vien:\n";
    inDanhSachDiemSinhVien(head);

    return 0;
}
