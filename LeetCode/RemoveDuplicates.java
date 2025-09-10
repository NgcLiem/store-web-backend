package LeetCode;

public class RemoveDuplicates {
    public int removeDuplicates(int[] a) {
        int n = a.length;
        int cur = 0;
        for(int i = 1; i < n; i++){
            if(a[cur] != a[i]){
                cur++;
                a[cur] = a[i];
            }
        }
        return cur + 1;
    }
}
