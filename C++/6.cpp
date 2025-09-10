#include<iostream>
using namespace std;

void move(int n, int a, int b){
    if(n == 0){
        return ;
    }
    move(n-1, a, 6-a-b);
    cout << a << "=>" << b <<"\n";
    move(n-1, 6-a-b, b);
}

int main(){
    move(3,3,1);
    return 0;
}