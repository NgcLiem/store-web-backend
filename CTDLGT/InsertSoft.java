package CTDLGT;

public class InsertSoft {
    public static void printArray(int n, int[] a){
        System.out.printf("%d: ",n);
        for(int i = 0;i < a.length; i++){
            System.out.printf("%d ",a[i]);
        }
        System.out.println();
    }

    public static void insertSoft(int[] a){
        int n = a.length;
        for(int i = 1; i < n;i++){
            int ai = a[i];
            int j = i-1;
            while(j >= 0 && a[j] > ai){
                a[j+1] = a[j];
                j--; 
            }
            a[j+1] = ai;
        printArray(i, a);
    }
}
    public static void main(String[] args) {
        int[] a = {7,8,6,9,3,5,4};
        insertSoft(a);
    }
}
