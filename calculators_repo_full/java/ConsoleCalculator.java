import java.util.Scanner;

public class ConsoleCalculator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Введите первое число: ");
        double a = sc.nextDouble();
        System.out.print("Введите операцию (+ - * /): ");
        String op = sc.next();
        System.out.print("Введите второе число: ");
        double b = sc.nextDouble();
        switch (op) {
            case "+":
                System.out.println("Результат: " + (a + b));
                break;
            case "-":
                System.out.println("Результат: " + (a - b));
                break;
            case "*":
                System.out.println("Результат: " + (a * b));
                break;
            case "/":
                if (b == 0) System.out.println("Деление на ноль");
                else System.out.println("Результат: " + (a / b));
                break;
            default:
                System.out.println("Неизвестная операция");
        }
    }
}
