package Java;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ButtonGroup;
import javax.swing.JFrame;
import javax.swing.JRadioButton;

public class bai61_MyFrame extends JFrame implements ActionListener{
    
    JRadioButton pizza;
    JRadioButton chitken;
    JRadioButton salad;

    bai61_MyFrame(){
        
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
        this.setLayout(new FlowLayout());

        pizza = new JRadioButton("pizza");
        chitken = new JRadioButton("chitken");
        salad = new JRadioButton("salad");

        pizza.addActionListener(this);
        chitken.addActionListener(this);
        salad.addActionListener(this);

        ButtonGroup group = new ButtonGroup();
        group.add(pizza);
        group.add(chitken);
        group.add(salad);

        this.add(pizza);
        this.add(chitken);
        this.add(salad);
        this.pack();
        this.setVisible(true);
}

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == pizza){
            System.out.println("you ordered a pizza");
        }
        else if(e.getSource() == chitken)
        {
            System.out.println("you ordered a chitken");
        }
        else if (e.getSource() == salad){
            System.out.println("you ordered a salad");
        }
    }
}
