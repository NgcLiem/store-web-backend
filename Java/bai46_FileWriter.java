package Java;

import java.io.FileWriter;
import java.io.IOException;

public class bai46_FileWriter {
    public static void main(String[] args) {
        try{
            FileWriter fileWriter = new FileWriter("poem.txt");
            fileWriter.write("Trinh Cong Son \nTo Huu \nXuan Quynh\nXuan Dieu ");
            fileWriter.append("\nHan Mac Tu");
            fileWriter.close();
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }
}
