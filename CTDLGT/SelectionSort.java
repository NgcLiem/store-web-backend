package CTDLGT;

public class SelectionSort {
    public static void printArray(int n, int[] a){
        System.out.printf("%d: ", n);
        for(int i = 0;i < a.length;i++){
            System.out.printf("%d ", a[i]);
        }
        System.out.println();
    }
    public static void selectionSort(int[] a){
        int n = a.length;

        for(int i = 0;i < n;i++){
            int vitri = i;
            for(int j = i+1;j < n; j++){
                if(a[j] < a[vitri]){
                    vitri = j;   
                }
            }
            if(vitri != i){
                int y = a[vitri];
                a[vitri] = a[i];
                a[i] = y;
            }
            if(vitri == i){
                break;
            }
            printArray(i, a);
        }
    }
    public static void main(String[] args) {
        int[] a = {3,7,9,6,7,7,8,2};
        selectionSort(a);
    }
}
