package Java;

import javax.swing.JFrame;
import javax.swing.JPanel;

public class bai73_Myframe extends JFrame{

    bai73_MyPanel panel;

    bai73_Myframe(){

        panel = new bai73_MyPanel();

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.add(panel);
        this.pack();
        this.setLocation(null);
        this.setVisible(true);

    }
}
