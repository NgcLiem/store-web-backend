#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int>& a,int val){
    int n = a.size();
    int cur = 0;
    for(int i = 0 ;i < n; i++){
        if(a[i] != val){
            a[cur] = a[i];
            cur++;
        }
    }
    return cur;
}
int main(){
    int arr[] = {3,2,2,3};
    int val = 3;
    vector<int> a(arr,arr + sizeof(a)/sizeof(int));
    removeElement(a,val);

    int n = removeElement(a,3);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0; 
}