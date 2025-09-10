package Java;
 
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame; 
import java.awt.event.ActionListener;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;


public class bai60_MyFrame extends JFrame implements ActionListener{

    JButton button;
    JCheckBox checkBox;
    ImageIcon icon1;
    ImageIcon icon2;

    bai60_MyFrame(){
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setLayout(new FlowLayout());

        icon1 = new ImageIcon("tichxanh.png");
        icon2 = new ImageIcon("tichdo.jpg");

        button = new JButton();
        button.setText("Submit");
        button.addActionListener(this);

        checkBox = new JCheckBox();
        checkBox.setText("I'm a robot");
        checkBox.setFocusable(true);
        checkBox.setFont(new Font("Consolas", Font.BOLD, 30));
        checkBox.setIcon(icon1);
        checkBox.setSelectedIcon(icon2);
        
        this.add(button);
        this.add(checkBox);
        this.pack();
        this.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == button)
        {
            System.out.println(checkBox.isSelected());
        }
    }
}
