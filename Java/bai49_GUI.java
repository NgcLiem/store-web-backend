package Java;

import java.awt.Color;

import javax.swing.ImageIcon;
import javax.swing.JFrame;

public class bai49_GUI {
public static void main(String[] args) {
    
    JFrame frame = new JFrame();
    frame.setTitle("JFrame title goes here");
    frame.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
    frame.setResizable(false);
    frame.setSize(420, 420);
    frame.setVisible(true);

    ImageIcon image = new ImageIcon("img.png");
    frame.setIconImage(image.getImage());
    frame.getContentPane().setBackground(new Color(167, 4, 130));
    }
}
