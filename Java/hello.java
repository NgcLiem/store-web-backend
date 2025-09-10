package Java;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

import javax.swing.JTextField;

public class hello{
    public static void main(String[] args) {
        JFrame frame = new JFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new FlowLayout(FlowLayout.CENTER,10, 10));

        JButton button1 = new JButton("Next");
        button1.setBounds(10, 10, 20, 20);
        button1.setBackground(Color.ORANGE);
        button1.setFont(new Font("Comic Sans",Font.ITALIC,25));

        JButton button2 = new JButton("Password: ");
        button2.setBounds(10, 10, 20, 20);
        button2.setBackground(Color.BLUE);
        button2.setFont(new Font("Comic Sans",Font.BOLD,25));

        JTextField textField1 = new JTextField();
        textField1.setPreferredSize(new Dimension(40, 250));
        textField1.setFont(new Font("Consolas ", Font.ITALIC, 25));
        textField1.setForeground(Color.BLUE);
        textField1.setBackground(Color.BLACK);
        textField1.setCaretColor(Color.WHITE);

        JTextField textField2 = new JTextField();
        textField2.setPreferredSize(new Dimension(40, 250));
        textField2.setFont(new Font("Consolas ", Font.ITALIC, 25));
        textField2.setForeground(Color.BLUE);
        textField2.setBackground(Color.BLACK);
        textField2.setCaretColor(Color.WHITE);

        JLabel label1 = new JLabel("Sign in: ");
        label1.setHorizontalAlignment(JLabel.LEFT);
        label1.setBounds(0, 0, 0, 0);
        label1.setForeground(Color.BLACK);

        JPanel panel1 = new JPanel();
        panel1.add(textField1);
        panel1.add(label1);
        panel1.setBackground(Color.CYAN);
        panel1.setBounds(10, 10, 100, 100);
        panel1.setLayout(null);

        frame.add(panel1);

        frame.setSize(500, 500);
        frame.setVisible(true);
    }
}