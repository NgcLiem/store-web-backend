#include <iostream>
#include <vector>
using namespace std;

void duplicateZeros(vector<int>& a){
    int n = a.size();
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            for(int j = n - 2; j >= i + 1; j--){
                a[j+1] = a[j];
            }
            if(i+1){
                a[i+1] = 0;
                i++;
            }
        }
    }
}

int main(){
    int arr[] = {1,0,2,3,0,4,5,0};
    vector<int> a(arr,arr + sizeof(arr)/sizeof(int));
    duplicateZeros(a);

    for(int i = 0; i < a.size();i++){
        cout<< a[i]<<" ";
    }
    return 0;
}