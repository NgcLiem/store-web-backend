package Java;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

public class bai57_LaunchPage implements ActionListener{

    JFrame frame = new JFrame();
    JButton button = new JButton("New windows");

    bai57_LaunchPage(){
        button.setBounds(100, 100, 200, 100);
        button.setFocusable(false);
        button.addActionListener(this);

        frame.add(button);

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500, 500);
        frame.setLayout(null);
        frame.setVisible(true);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource() == button){
            
            bai57_NewWindows newWindow = new bai57_NewWindows();
        }
    }
}
