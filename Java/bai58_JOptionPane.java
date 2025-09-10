package Java;

import javax.swing.ImageIcon;
import javax.swing.JOptionPane;

public class bai58_JOptionPane {
    public static void main(String[] args) {
        //JOptionPane.showMessageDialog(null, "This is some unless info", "title", JOptionPane.PLAIN_MESSAGE);
        //JOptionPane.showMessageDialog(null, "Really?", "title", JOptionPane.QUESTION_MESSAGE);
        //JOptionPane.showMessageDialog(null, " info", "title", JOptionPane.INFORMATION_MESSAGE);
        //JOptionPane.showMessageDialog(null, "This is some unless ", "title", JOptionPane.CANCEL_OPTION);

        //JOptionPane.showMessageDialog(null, "error 404", "title", JOptionPane.ERROR_MESSAGE);

        //JOptionPane.showMessageDialog(null, "Virus", "title", JOptionPane.WARNING_MESSAGE);
        //JOptionPane.showConfirmDialog(null, "Bro", "This", JOptionPane.CANCEL_OPTION);
        //int answer = JOptionPane.showConfirmDialog(null, "Can u play volleyball with me?", "Please",  JOptionPane.YES_NO_CANCEL_OPTION);
        //String name = JOptionPane.showInputDialog("What your name? ");

        String[] response = {"No","You are female","thank you","blush"};
        ImageIcon icon = new ImageIcon("img.png");
        JOptionPane.showInputDialog(null,"You are ","Male",JOptionPane.INFORMATION_MESSAGE,icon,response,0);
        
        
    }
}
