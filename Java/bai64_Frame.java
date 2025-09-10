package Java;

import java.awt.Color;
import java.awt.Font;

import javax.swing.JFrame;
import javax.swing.JProgressBar;

public class bai64_Frame {

    JFrame frame;
    JProgressBar progressBar;

    bai64_Frame(){

        frame = new JFrame();
        progressBar = new JProgressBar(0,500);

        progressBar.setValue(0);
        progressBar.setStringPainted(true);
        progressBar.setBounds(200, 100, 420, 200);
        progressBar.setBackground(Color.black);
        progressBar.setForeground(Color.ORANGE);
        progressBar.setFont(new Font("MV Boli",Font.ITALIC,22));


        frame.add(progressBar);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(1000, 500);
        frame.setLayout(null);
        frame.setVisible(true);

        fill();
    }    
    public void fill(){
        int counter = 0;
        while (counter <= 500){
            progressBar.setValue(counter);
            try{
                Thread.sleep(10,20000);
            }
            catch(InterruptedException e){
                e.printStackTrace();
            }
            counter +=1 ;
        }
        progressBar.setString("Done");
    }

}
