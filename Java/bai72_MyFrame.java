package Java;

import javax.swing.JFrame;

public class bai72_MyFrame extends JFrame {

    bai72_MyPanel panel;

    bai72_MyFrame(){

        panel = new bai72_MyPanel();

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        this.add(panel);
        //his.setLocationRelativeTo(null);
        this.pack();
        this.setSize(500,500);
        this.setVisible(true);
    }
}
