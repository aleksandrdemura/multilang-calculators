#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("Калькулятор (Qt)");

    QLineEdit *a = new QLineEdit();
    QLineEdit *b = new QLineEdit();
    QLineEdit *res = new QLineEdit();
    res->setReadOnly(true);

    QPushButton *add = new QPushButton("+");
    QPushButton *sub = new QPushButton("-");
    QPushButton *mul = new QPushButton("*");
    QPushButton *div = new QPushButton("/");

    auto calc = [&](char op){
        bool ok1, ok2;
        double da = a->text().toDouble(&ok1);
        double db = b->text().toDouble(&ok2);
        if (!ok1 || !ok2) { res->setText("Ошибка ввода"); return; }
        if (op == '/' && db == 0) { res->setText("Деление на ноль"); return; }
        double r = 0;
        switch(op){ case '+': r = da+db; break; case '-': r = da-db; break; case '*': r=da*db; break; case '/': r=da/db; break; }
        res->setText(QString::number(r));
    };

    QObject::connect(add, &QPushButton::clicked, [&](){ calc('+'); });
    QObject::connect(sub, &QPushButton::clicked, [&](){ calc('-'); });
    QObject::connect(mul, &QPushButton::clicked, [&](){ calc('*'); });
    QObject::connect(div, &QPushButton::clicked, [&](){ calc('/'); });

    QHBoxLayout *h1 = new QHBoxLayout();
    h1->addWidget(new QLabel("A:")); h1->addWidget(a);
    h1->addWidget(new QLabel("B:")); h1->addWidget(b);

    QHBoxLayout *h2 = new QHBoxLayout();
    h2->addWidget(add); h2->addWidget(sub); h2->addWidget(mul); h2->addWidget(div);

    QVBoxLayout *main = new QVBoxLayout();
    main->addLayout(h1);
    main->addLayout(h2);
    main->addWidget(new QLabel("Результат:"));
    main->addWidget(res);

    window.setLayout(main);
    window.show();
    return app.exec();
}
