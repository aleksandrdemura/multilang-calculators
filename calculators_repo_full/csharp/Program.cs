using System;

class Program {
    static void Main() {
        Console.WriteLine("=== Консольный калькулятор C# ===");
        Console.Write("Введите первое число: ");
        if (!double.TryParse(Console.ReadLine(), out double a)) { Console.WriteLine("Ошибка ввода"); return; }
        Console.Write("Введите операцию (+ - * /): ");
        string op = Console.ReadLine() ?? "";
        Console.Write("Введите второе число: ");
        if (!double.TryParse(Console.ReadLine(), out double b)) { Console.WriteLine("Ошибка ввода"); return; }

        try {
            double r = op switch {
                "+" => a + b,
                "-" => a - b,
                "*" => a * b,
                "/" => b == 0 ? throw new DivideByZeroException() : a / b,
                _ => throw new InvalidOperationException("Неизвестная операция")
            };
            Console.WriteLine($"Результат: {r}");
        } catch (Exception e) {
            Console.WriteLine("Ошибка: " + e.Message);
        }
    }
}
