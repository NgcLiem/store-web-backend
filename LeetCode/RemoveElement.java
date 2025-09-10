package LeetCode;

public class RemoveElement {
    public int removeElement(int[] a, int val) {
        int n = a.length;
        int cur = 0;
        for(int i = 0; i < n; i++){
            if(a[i] != val){
                a[cur] = a[i];
                cur++;
            }
        }
        return cur;
    }
}