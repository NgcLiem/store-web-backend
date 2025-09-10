package CTDLGT;

public class BubbleSort {
    public static void printArray(int no,int[] a){
        System.out.printf("%d: ",no);
        for(int i = 0;i < a.length;i++){
            System.out.printf("%d ",a[i]);
        }
        System.out.println();
    }

    public static void bubbleSort(int[] a){
        int n = a.length;
        for(int i = 0; i < n ;i++){
            boolean check = true;
            for(int j = 0;j < n-i-1;j++){
                if(a[j] > a[j+1]){
                    check = false;
                    int t = a[j+1];
                    a[j + 1] = a[j];
                    a[j] = t;
                }
            }
            printArray(i, a);
            if (check == true){
                break;
            }
        }
    }
    public static void main(String[] args) {
        int[] a = {7,8,6,9,2,5,4};
        bubbleSort(a);
    }
    
}
