#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("qt-form prototype");

    // Layout - owns every widget we add to it
    auto *layout = new QVBoxLayout(&window);

    // site Field
    auto *siteLabel = new QLabel("Site:");
    auto *siteEdit = new QLineEdit;
    layout->addWidget(siteLabel);
    layout->addWidget(siteEdit);


    // Password field - masked
    auto *pwLabel = new QLabel("Password:");
    auto *pwEdit = new QLineEdit;
    pwEdit->setEchoMode(QLineEdit::Password); // <-- the security-requirement line
    layout->addWidget(pwLabel);
    layout->addWidget(pwEdit);

    // Action button + result display
    auto *shownBtn = new QPushButton("Show what I typed");
    auto *result = new QLabel("(nothing shown yet)");
    layout->addWidget(shownBtn);
    layout->addWidget(result);

    // Wire the button: read both fields, update the label
    QObject::connect(shownBtn, &QPushButton::clicked, [siteEdit, pwEdit, result](){
        result->setText("Site: " + siteEdit->text() + " | Passsword length: " + QString::number(pwEdit->text().length())
    );

    });

    window.show();
    return app.exec();

}