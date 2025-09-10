#include <iostream>
#include<vector>
using namespace std;

int countNumOfDigit(int n){
    int count = 0;
    while(n > 0){
        count++;
        n /= 10;
    }
    return count;
}

int findNumber(vector<int>& a){
    int count = 0;

    for(int i = 0; i < a.size(); i++){
        if(countNumOfDigit(a[i]) % 2 == 0){
            count++;
        }
    }
    return count;
}

int main(){
    int arr[] = {555,197,1797,67};
    vector<int> a(arr,arr + sizeof(arr)/ sizeof(int)); 
    cout<<findNumber(a) << endl;
}