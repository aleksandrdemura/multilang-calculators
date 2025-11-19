#include <iostream>
#include <stdexcept>

int main() {
    std::cout << "=== Консольный калькулятор C++ ===\n";
    double a, b;
    char op;
    std::cout << "Введите первое число: ";
    if (!(std::cin >> a)) return 0;
    std::cout << "Введите операцию (+ - * /): ";
    std::cin >> op;
    std::cout << "Введите второе число: ";
    std::cin >> b;

    try {
        double res;
        switch (op) {
            case '+': res = a + b; break;
            case '-': res = a - b; break;
            case '*': res = a * b; break;
            case '/':
                if (b == 0) throw std::runtime_error("Деление на ноль");
                res = a / b; break;
            default: throw std::runtime_error("Неизвестная операция");
        }
        std::cout << "Результат: " << res << "\n";
    } catch (const std::exception &e) {
        std::cout << "Ошибка: " << e.what() << "\n";
    }
    return 0;
}
