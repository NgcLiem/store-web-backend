package LeetCode;

public class SortArrayByParity {
    public int[] sortArrayByParity(int[] a) {
        int i = 0;
        int j = a.length - 1;
        int n ;
        while(i < j){
            if(a[i] % 2 != 0 && a[j] % 2 == 0){
                n = a[i];
                a[i] = a[j];
                a[j] = n;
                i++;
                j--;
            }
            else if(a[i] % 2 == 0){
                i++;
            }
            else if(a[j] % 2 != 0){
                j--;
            }
            
        }
       return a;
    }
}
