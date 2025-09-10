#include <iostream>
#include <vector>

using namespace std;

bool validMountainArray(vector<int>& a) {
    int n = a.size();
    bool biS = true;
    if(n < 3){
        return false;
    }
    for(int i = 0; i+1 < n; i++){
        int j = i + 1;
        if(a[i] > a[j]){
            if(biS == false){
                // normal
            }
            else{ // biS == true
                if(i == 0){
                    return false;
                }
                biS = false;
            }
        }
        else if(a[i] < a[j]){
            if(biS == true){
                // normal
            }

            else{
                return false;
            }
        }
        else{
            return false;
        }
    }    
    if(biS == false)
        return true;
    return false;
}

int main(){

}