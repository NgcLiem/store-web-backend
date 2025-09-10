#include <iostream>
#include <queue>

using namespace std;

// Hàm xuất các phần tử của queue
void printQueue(queue<int> q) {
    cout << "danh sach queue: ";
    while (!q.empty()) {
        cout << q.front() << " "; // In ra phần tử đầu của queue
        q.pop(); // Loại bỏ phần tử đầu khỏi queue
    }
    cout << endl;
}

int main() {
    queue<int> myQueue;
    int choice, item;
        cout << "\nChon chuc nang :\n";
        cout << "1. Nhap vao phan tu queue\n";
        cout << "2. Kiem tra queue co rong khong\n";
        cout << "3. Xoa phan tu queue\n";
        cout << "4. Xuat queue\n";
        cout << "5. thoat\n";
        
        while(true){
            cout << "Lua chon cua ban: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Nhap 1 phan tu queue: ";
                cin >> item;
                myQueue.push(item);
                break;
            case 2:
                if (myQueue.empty())
                    cout << "Queue dang rong\n";
                else
                    cout << "Queue khong rong\n";
                break;
            case 3:
                if (!myQueue.empty()) {
                    cout << "Nhap gia tri can xoa: ";
                    cin >> item;
                    queue<int> temp;
                    while (!myQueue.empty()) {
                        if (myQueue.front() != item) {
                            temp.push(myQueue.front());
                        }
                        myQueue.pop();
                    }
                    while (!temp.empty()) {
                        myQueue.push(temp.front());
                        temp.pop();
                    }
                    cout << "Da xoa phan tu " << item<<endl;
                } else {
                    cout << "Khong the xoa vi dang rong";
                }
                break;
            case 4:
                printQueue(myQueue);
                break;
            case 5:
                return 0;
        }
    }
    return 0;
}