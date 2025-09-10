#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int>& a){
    int n = a.size(); 
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] == a[j]*2 || a[i]*2 == a[j]){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int arr[] = {10,2,5,7};
    vector<int> a(arr,arr + sizeof(arr)/ sizeof(int));
    bool n = check(a);
    cout<< n;
}   