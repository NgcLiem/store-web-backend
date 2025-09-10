#include <iostream>
#include <string>

using namespace std;

class SinhVien {
public:
    std::string hoTen;
    int maSV;
    SinhVien* next;

    SinhVien(const std::string& ten, int ma) : hoTen(ten), maSV(ma), next(nullptr) {}
};

class DanhSachSinhVien {
private:
    SinhVien* head;

public:
    DanhSachSinhVien() : head(nullptr) {}

    ~DanhSachSinhVien() {
        while (head != nullptr) {
            SinhVien* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void themSinhVien(const std::string& ten, int ma) {
        SinhVien* sv = new SinhVien(ten, ma);
        sv->next = head;
        head = sv;
    }

    void hienThiDanhSach() const {
        SinhVien* current = head;
        while (current != nullptr) {
            std::cout << "MaSV: " << current->maSV << ", Ho Ten: " << current->hoTen << std::endl;
            current = current->next;
        }
    }

    // void xoaDanhSach() {
    //     while (head != nullptr) {
    //         SinhVien* temp = head;
    //         head = head->next;
    //         delete temp;   
    //     }
    // }
    void xoaSinhVien(int ma) {
        SinhVien* current = head;
        SinhVien* prev = nullptr;

        while (current != nullptr && current->maSV != ma) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Khong tim thay sinh vien co ma " << ma << std::endl;
            return;
        }

        if (prev != nullptr) {
            prev->next = current->next;
        } else {
            head = current->next;
        }

        delete current;
        std::cout << "Da xoa sinh vien co ma " << ma << std::endl;
    }
};

int main() {
    DanhSachSinhVien danhSach;

    // Nhập danh sách sinh viên
    
    int choose;
    
    string ten;
    int mssv, ma1;
    do{
        cout<<"1. Nhap danh sach sinh vien."<<endl;
        cout<<"2. Xoa danh sach sinh vien."<<endl;
        cout<<"Nhap lua chon: ";
        cin >> choose;
        
        while(true){
            switch(choose)
            {
            case 1:
                cout<< "\nNhap tenSV: ";cin >> ten;
                cout<< "Nhap maSV: "; cin >> mssv;
                danhSach.themSinhVien(ten,mssv);
                break;

            case 2:
                cout<<"Nhap mssv can xoa: "; cin>>ma1;
                danhSach.xoaSinhVien(ma1);
                break;

            default:
                cout<<"Vui long chon lai" << endl;
                break;
            }
        }
    } while (choose >= 3);

    return 0;
}
