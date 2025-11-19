package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Println("=== Консольный калькулятор Go ===")
    fmt.Print("Введите первое число: ")
    aStr, _ := reader.ReadString('\n')
    aStr = strings.TrimSpace(aStr)
    a, err := strconv.ParseFloat(aStr, 64)
    if err != nil { fmt.Println("Ошибка ввода"); return }

    fmt.Print("Введите операцию (+ - * /): ")
    op, _ := reader.ReadString('\n')
    op = strings.TrimSpace(op)

    fmt.Print("Введите второе число: ")
    bStr, _ := reader.ReadString('\n')
    bStr = strings.TrimSpace(bStr)
    b, err := strconv.ParseFloat(bStr, 64)
    if err != nil { fmt.Println("Ошибка ввода"); return }

    switch op {
    case "+":
        fmt.Println("Результат:", a+b)
    case "-":
        fmt.Println("Результат:", a-b)
    case "*":
        fmt.Println("Результат:", a*b)
    case "/":
        if b == 0 { fmt.Println("Деление на ноль"); return }
        fmt.Println("Результат:", a/b)
    default:
        fmt.Println("Неизвестная операция")
    }
}
