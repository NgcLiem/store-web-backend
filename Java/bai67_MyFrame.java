package Java;

import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JLabel;
import javax.swing.JFrame;
import java.awt.event.ActionListener;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Label;
import java.awt.event.ActionEvent;

public class bai67_MyFrame extends JFrame implements ActionListener{

    JButton button;
    JLabel label; 

    bai67_MyFrame(){

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLayout(new FlowLayout());

        button = new JButton("Pick a color: ");
        label  = new JLabel("Choose a color");

        label.setBackground(Color.BLACK);
        label.setOpaque(true);
        label.setFont(new Font("MV Boli", ABORT, 23));

        button.addActionListener(this);
        this.add(button);
        this.add(label);

        this.pack();
        this.setVisible(true);

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == button){
            JColorChooser colorChooser = new JColorChooser();
            Color color = JColorChooser.showDialog(null, "Pick color ............... i guess", Color.black);
            label.setForeground(color);
            label.setBackground(color);
        }
    }
    
}
