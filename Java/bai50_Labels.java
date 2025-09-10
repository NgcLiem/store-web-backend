package Java;

import java.awt.Color;
import java.awt.Font;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.border.Border;

public class bai50_Labels {
    public static void main(String[] args) {
        ImageIcon image = new ImageIcon("img.png");
        Border border = BorderFactory.createLineBorder(Color.GREEN,3);
        
        JLabel label = new JLabel();
        label.setText("Do you even code");
        label.setIcon(image);
        label.setHorizontalTextPosition(JLabel.CENTER); // set text left, right, center of image
        label.setVerticalTextPosition(JLabel.BOTTOM);   // set text top, bottom, center of image
        label.setForeground(new Color(0x00FF)); // set font color of text
        label.setFont(new Font("MV", Font.PLAIN, 20)); // set font of text
        label.setIconTextGap(-25); // set gap of text to image
        label.setBackground(Color.BLACK); // set backgound color
        label.setOpaque(true); // display backgound color
        label.setBorder(border);
        label.setVerticalAlignment(JLabel.CENTER); //chinh ca 2 
        label.setHorizontalAlignment(JLabel.CENTER);
        //label.setBounds(100, 400, 250, 250);

        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //frame.setSize(500,500);
        //frame.setLayout(null);
        frame.setVisible(true);
        frame.add(label);
        frame.pack();

    }   
}
