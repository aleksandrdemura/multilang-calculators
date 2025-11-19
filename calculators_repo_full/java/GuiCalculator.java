import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class GuiCalculator {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Калькулятор (Swing)");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(320, 180);

        JTextField a = new JTextField();
        JTextField b = new JTextField();
        JTextField res = new JTextField(); res.setEditable(false);

        JButton plus = new JButton("+");
        JButton minus = new JButton("-");
        JButton mul = new JButton("*");
        JButton div = new JButton("/");

        ActionListener doCalc = e -> {
            try {
                double da = Double.parseDouble(a.getText());
                double db = Double.parseDouble(b.getText());
                String op = ((JButton)e.getSource()).getText();
                if (op.equals("/") && db == 0) { res.setText("Деление на ноль"); return; }
                double r = 0;
                switch(op) { case "+": r=da+db; break; case "-": r=da-db; break; case "*": r=da*db; break; case "/": r=da/db; break; }
                res.setText(String.valueOf(r));
            } catch (Exception ex) { res.setText("Ошибка ввода"); }
        };

        plus.addActionListener(doCalc);
        minus.addActionListener(doCalc);
        mul.addActionListener(doCalc);
        div.addActionListener(doCalc);

        frame.setLayout(new GridLayout(4,1));
        JPanel p1 = new JPanel(new GridLayout(1,2)); p1.add(a); p1.add(b);
        JPanel p2 = new JPanel(new GridLayout(1,4)); p2.add(plus); p2.add(minus); p2.add(mul); p2.add(div);
        frame.add(new JLabel("Введите числа:"));
        frame.add(p1);
        frame.add(p2);
        frame.add(res);
        frame.setVisible(true);
    }
}
