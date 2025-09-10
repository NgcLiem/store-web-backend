package Java;

import java.awt.Dimension;
import java.awt.Font;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSlider;
import javax.swing.SwingConstants;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

public class bai63_MyFrame implements ChangeListener{

    JFrame frame;
    JPanel panel;
    JLabel label;
    JSlider slider; 

    bai63_MyFrame(){

        frame = new JFrame("Temperature");
        panel = new JPanel();
        label = new JLabel();
        slider = new JSlider(0,100,50);

        slider.setPreferredSize(new Dimension(400, 400));

        slider.setPaintTicks(true); //  Xác định xem dấu tích có được vẽ trên thanh trượt hay không.
        slider.setMinorTickSpacing(10); // Phương pháp này đặt khoảng cách đánh dấu nhỏ.

        slider.setPaintTrack(true); //  Xác định xem rãnh có được vẽ trên thanh trượt hay không.
        slider.setMajorTickSpacing(25); //  Phương pháp này đặt khoảng cách đánh dấu chính.

        slider.setPaintLabels(true); // Xác định xem nhãn có được vẽ trên thanh trượt hay không.
        slider.setFont(new Font("MV Body",Font.PLAIN,20));
        label.setFont(new Font("MV Body",Font.PLAIN,25  ));

        slider.setOrientation(SwingConstants.VERTICAL); // dat cot thanh hang doc
        //slider.setOrientation(SwingConstants.HORIZONTAL); // dat cot thanh hang ngang

        label.setText("oC = "+ slider.getValue());

        slider.addChangeListener(this);

        panel.add(label);
        panel.add(slider);
        frame.add(panel);
        frame.setSize(800,500);
        frame.setVisible(true);
    }
    @Override
    public void stateChanged(ChangeEvent e) {
        label.setText("oC = "+ slider.getValue());
    }
    
}
