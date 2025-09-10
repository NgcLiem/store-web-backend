#include <iostream>
#include <queue>
#include <string>

using namespace std;

void printQueue(queue<int> q) {
    cout << "danh sach queue: ";
    while (!q.empty()) {
        cout << q.front() << " "; // In ra phần tử đầu của queue
        q.pop(); // Loại bỏ phần tử đầu khỏi queue
    }
    cout << endl;
}

int main() {
    queue<string> myQueue;
    int sl;
    int choise ;
    string a, item;
    
    cout<<"Nhap so luong phan tu: "; cin >> sl;
        string a;
        for(int i = 1;i <= sl; i++){
            cout<<"Nhap phan tu thu "<<i<<": ";
            cin>> a;
            cin.ignore();
            myQueue.push(a);
    }
do{
    cout << "1. Kiem tra Queue rong" << endl;
    cout << "2. Them phan tu vao Queue" << endl;
    cout << "3. Xoa phan tu trong Queue" << endl;
    cout << "4. Xuat Queue" << endl;
    cout << "5. Thoat" << endl;
    
    cout<<"Nhap lua chon: "; cin >> choise;

    switch (choise)
    {
    case 1:
        if(myQueue.empty()){
            cout<<"queue rong"<<endl;
        }
        else{
            cout<<"queue khong rong" << endl;
        }
        break;
    case 2:
        cout<<"Nhap 1 phan tu: "; cin >> a;
        myQueue.push(a);
        break;
    case 3:
        if(!myQueue.empty()){
            cout << "Nhap item can xoa: ";
            cin >> item;
            queue<int> temp;
            while(!myQueue.empty()){
                if(myQueue.front() != item){
                    temp.push(myQueue.front());
                }
                myQueue.pop();
            }
            while(!temp.empty()){
                myQueue.push(temp.front());
                temp.pop();
            }
            cout<<"Da xoa phan tu! " << endl;
        }
        else{
            cout<<"Khong the xoa phan tu" << endl;
        }
        break;
    default:
        break;
    }
}
while(choise != 6);
    return 0;
}
