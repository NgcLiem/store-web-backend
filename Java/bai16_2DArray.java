package Java;

public class bai16_2DArray {
    public static void main(String[] args) {
        String[][] cars = new String[3][3];
        // String [][] cars ={
                            //{"How","What","When"},
                            //{"Who","Which","Where"},
                            //{"Whom","Whose","Do"}
                                                    //};
        cars[0][0] = "How";
        cars[0][1] = "What";
        cars[0][2] = "When";
        cars[1][0] = "Who";
        cars[1][1] = "Which";
        cars[1][2] = "Where";
        cars[2][0] = "Whom";
        cars[2][1] = "Whose";
        cars[2][2] = "Do";
        for (int i = 0;i<cars.length;i++){
            System.out.println();
            for(int j = 0;j<cars.length;j++){
                System.out.print(cars[i][j]+" ");
            }
        }
    }
}
