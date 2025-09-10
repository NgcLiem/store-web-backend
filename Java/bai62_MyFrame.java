package Java;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JComboBox;
import javax.swing.JFrame;

public class bai62_MyFrame extends JFrame implements ActionListener  {

    JComboBox comboBox;

    bai62_MyFrame(){
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLayout(new FlowLayout());
        
        
        String[] animal = {"dog","bird","fish"};
        comboBox = new JComboBox<>(animal);
        comboBox.addActionListener(this);

        //comboBox.setEditable(true); // cho edit
        //comboBox.insertItemAt("cat", 3); // them phan tu vao vi tri
        //comboBox.addItem("horse"); // add item
        //System.out.println(comboBox.getItemCount()); // dua ra so luong 
        //comboBox.setSelectedIndex(1); // bat dau boi vi tri
        //comboBox.removeItem("dog");
        comboBox.removeItemAt(2);
           
        this.add(comboBox);
        this.pack();
        this.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == comboBox){
            System.out.println(comboBox.getSelectedItem());
        }
    }
    
}
