package Java;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Color;
import java.awt.Image;
import java.awt.event.*;

public class bai68_MyFrame extends JFrame implements KeyListener{

    JLabel label;
    ImageIcon icon;

    bai68_MyFrame(){
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLayout(null);

        label = new JLabel();
        label.setBounds(0, 0, 250, 250);
        label.setBackground(Color.BLACK);
        label.setOpaque(true);

        icon = new ImageIcon("tenlua2.jpg");
        label.setIcon(icon);

        this.add(label);
        this.getContentPane().setBackground(Color.black);
        this.addKeyListener(this);
        this.setSize(500,500);
        this.setVisible(true);
    }


    @Override
    public void keyTyped(KeyEvent e) {
        switch (e.getKeyChar()) {
            case 'a':
                label.setLocation(label.getX()-10,label.getY());
                break;
            case 'w':
                label.setLocation(label.getX(),label.getY()-10);
                break;
            case 's':
                label.setLocation(label.getX(),label.getY()+10);
                break;
            case 'd':
                label.setLocation(label.getX()+10,label.getY());
                break;
            case     
            default:
                break;
        }
    }

    @Override
    public void keyPressed(KeyEvent e) {
        switch (e.getKeyCode()) {
            case 37 :
                label.setLocation(label.getX()-10,label.getY());
                break;
            case 38:
                label.setLocation(label.getX(),label.getY()-10);
                break;
            case 40:
                label.setLocation(label.getX(),label.getY()+10);
                break;
            case 39:
                label.setLocation(label.getX()+10,label.getY());
                break;
            default:
                break;
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {
        System.out.println("Key char: "+ e.getKeyChar());
        System.out.println("Key code: " + e.getKeyCode());
        System.out.println();
    }
    
}
