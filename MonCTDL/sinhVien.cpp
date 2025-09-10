#include<iostream>
#include<string>
using namespace std;

struct SinhVien {
    string maSV, tenSV, cccd;
    SinhVien* next;

    SinhVien(string maSV,string tenSV,string cccd) : maSV(), tenSV(), cccd(), next(nullptr) {};
};

void themSinhVien(SinhVien*& head, string maSV, string tenSV, string cccd){

    SinhVien* sv = new SinhVien(maSV, tenSV, cccd);
    sv->next = head;
    head = sv;
}

void inDanhSach(SinhVien * head){
    while(head != nullptr){
        cout<<"Ma sinh vien:"<<head->maSV<<"Ten: "<<head->tenSV<<"CCCD: "<<head->cccd<<endl;
    }
}

void addTail(SinhVien*& head){
    
}

int main(){
    SinhVien* head = nullptr;
    int choose = 0;
    
    string ma, ma1,ten,cccd;

    cout<<"Nhap lua chon: ";
    cin >> choose;
    while(true){
        cout<<"1. Nhap danh sach sinh vien."<<endl;
        cout<<"2. Xoa danh sach sinh vien."<<endl;

        switch(choose)
        {
        case 1:
            cout<< "Nhap vao thong tin sinh vien"; cin>>ma;
            cout<< "\nNhap maSV: "; cin>>ma;
            cout<< "\nNhap tenSV: ";cin>> ten;
            cout<< "\nNhap cccd: "; cin>>cccd;
        themSinhVien(head,ma,ten,cccd);
        break;
        case 2:
            cout<<"Nhap mssv can xoa: "; cin>>ma1;
            
        default:
            break;
        }
    }
    return 0;
}