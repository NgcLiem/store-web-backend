package LeetCode;

public class ReplaceElement {
    public int[] replaceElements(int[] a) {
        int n = a.length;
        for(int i = n - 1; i >= 0; i--){
            if(i != n - 1){
                a[i] = Math.max(a[i], a[i+1]);
            }
        }
        for(int i = 1; i < n; i++){
            a[i - 1] = a[i];
        }
        a[n - 1] = - 1;
        return a;
    }
}
