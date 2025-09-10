package Java;

import java.io.File;

public class bai45_File {
    public static void main(String[] args) {
    File file = new File("secret.txt");

    if(file.exists()){
        System.out.println("That file is exists!");
        System.out.println(file.getAbsolutePath());
        System.out.println(file.getPath());
        System.out.println(file.isFile());
        file.delete();
    }
    else 
    {
        System.out.println("This file doesn't exists! ");
    }
}}
