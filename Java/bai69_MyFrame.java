package Java;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Image;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class bai69_MyFrame extends JFrame implements MouseListener{

    JLabel label;
    ImageIcon nervous;
    ImageIcon dizzy;
    ImageIcon pain;
    ImageIcon smile;

    bai69_MyFrame(){
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLayout(new FlowLayout());
        this.setSize(500,500);

        nervous = new ImageIcon("nervous.jpg");
        dizzy = new ImageIcon("dizzy.jpg");
        pain = new ImageIcon("pain.jpg");
        smile = new ImageIcon("smile.jpg");

        label = new JLabel();
        
        label.addMouseListener(this);
        label.setIcon(smile);
        this.add(label);
        this.setVisible(true);
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        System.out.println("You clicked the mouse");
        label.setIcon(dizzy);
    }

    @Override
    public void mousePressed(MouseEvent e) {
        System.out.println("You pressed the mouse");
        label.setIcon(smile);
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        System.out.println("You released the mouse");
        label.setIcon(pain);
    }

    @Override
    public void mouseEntered(MouseEvent e) {
        System.out.println("You entered the mouse");
        label.setIcon(pain);
    }

    @Override
    public void mouseExited(MouseEvent e) {
        System.out.println("You excited the mouse");
        label.setIcon(smile);
    }
    
}
