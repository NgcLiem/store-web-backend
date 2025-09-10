#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& ai, int ni, vector<int>& aj, int nj) {
    int i = ni - 1;
    int j = nj - 1;   
    int k = ni + nj - 1;

    while (i >= 0 || j >= 0){
        if(i >= 0 && j >= 0){
            if(ai[i] > aj[j]){
                ai[k] = ai[i];
                k--;
                i--;
            }
            else{
                ai[k] = aj[j];
                j--;
                k--;
            }
        }
        else if (i >= 0){
            ai[k] = ai[i];
            k--;
            i--;
        }
        else{
            ai[k] = aj[j];
            k--;
            j--;
        }
    }
}

int main(){
    int arr1[] = {1,2,3,0,0,0}; int n1 = 3;
    vector<int> a1(arr1,arr1+sizeof(arr1)/sizeof(int));

    int arr2[] = {2,5,6}; int n2 = 3;
    vector<int> a2(arr2,arr2+sizeof(arr2)/sizeof(int));
    merge(a1,n1,a2,n2);

    for(int i = 0;i < a1.size();i++){
        cout<<a1[i]<<" ";
    }
    return 0;
}