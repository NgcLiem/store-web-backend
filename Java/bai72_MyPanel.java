package Java;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JPanel;

public class bai72_MyPanel extends JPanel   {

    Image image;

    bai72_MyPanel(){
        image = new ImageIcon("img.png").getImage(); 
        this.setPreferredSize(new Dimension(500,500));
    }
    public void paint(Graphics g){

        Graphics2D g2D = (Graphics2D) g;

        g2D.drawImage(image,0 ,0,null);
        g2D.setPaint(Color.BLUE);
        g2D.setStroke(new BasicStroke(5));
        g2D.drawLine(0,0,500,500);

        g2D.setPaint(Color.PINK);
        //g2D.drawRect(100,100,100,100);
        g2D.fillRect(100,100,100,100);

        g2D.setPaint(Color.GREEN);
        //g2D.drawOval(200, 200, 100, 100);
        g2D.fillOval(200,200,100,100);
        
        g2D.setPaint(Color.RED);
        //g2D.drawOval(200, 200, 100, 100);
        g2D.fillArc(0,0,100,100,180,180);  
        
        g2D.setPaint(Color.ORANGE);
        g2D.fillArc(0,0,100,100,0,180);

        int x[] = {150,500,200,400,600};
        int y[] = {200,300,100,144,500};
        g2D.setPaint(Color.RED);
        //g2D.drawPolygon(x,y,3);
        g2D.fillPolygon(x, y, 5);

        
    }

}
