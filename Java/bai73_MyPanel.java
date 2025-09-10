package Java;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.util.Timer;

import javax.swing.ImageIcon;
import javax.swing.JPanel;

public class bai73_MyPanel extends JPanel implements ActionListener {
    
    final int panel_width = 500;
    final int panel_height = 500;
    Image enemy;
    Image backgroundImage;
    Timer timer;
    int xVe = 1;
    int yVe = 1;
    int x = 0;
    int y = 0;

    bai73_MyPanel(){
        this.setPreferredSize(new Dimension(panel_width,panel_height));
        this.setBackground(Color.black);
        enemy = new ImageIcon("img.png").getImage();
        timer = new Timer(1000,this);
        timer.start();
    }
    public void paint(Graphics g){
        super.paint(g);
        Graphics2D g2D = (Graphics2D) g ;

        g2D.drawImage(enemy,x,y,null);
        
    }
    @Override
    
}
