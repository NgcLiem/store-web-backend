#include<iostream>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int current = 0;
    for(int i = 0; i < n; i++){
        if(nums[i] != nums[current]){
            current += 1;
            nums[current] = nums[i];
        }
    }
    return current + 1;
}


int main(){
    int arr[] = {0,0,1,1,1,2,2,3,3,4};
    vector<int> a(arr, arr + sizeof(arr)/sizeof(int));

    int n = removeDuplicates(a); 

    for(int i = 0; i < n; i++){
        cout << a[i] << " "; 
    }

    
    return 0;
}