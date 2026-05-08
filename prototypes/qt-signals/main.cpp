#include <QApplication>
#include <QPushButton>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QPushButton button("Click me");
    button.resize(200, 100);

    int count = 0;
    QObject::connect(&button, &QPushButton::clicked, [&]() {
        count++;
        button.setText(QString("Clicked %1 times").arg(count));
    });

    button.show();
    return app.exec();
}