#include <QApplication>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    // The dialog itself
    QDialog dlg;
    dlg.setWindowTitle("UnlockVault");

    // Outer vertical layout
    auto *layout = new QVBoxLayout(&dlg);

    // Prompt + masked password field
    layout->addWidget(new QLabel("Enter master password:"));
    auto *pwEdit = new QLineEdit;
    pwEdit->setEchoMode(QLineEdit::Password);
    layout->addWidget(pwEdit);

    // Buttons row 9horizontal sublayout, nested)
    auto *buttonRow = new QHBoxLayout;
    auto *unlockBtn = new QPushButton("Unlock");
    auto *cancelBtn = new QPushButton("Cancel");
    buttonRow->addWidget(unlockBtn);
    buttonRow->addWidget(cancelBtn);
    layout->addLayout(buttonRow);  // note: addLayout, not addWidget

    // Wire buttons to QDialog's built-in slots
    QObject::connect(unlockBtn, &QPushButton::clicked, &dlg, &QDialog::accept);
    QObject::connect(cancelBtn, &QPushButton::clicked, &dlg, &QDialog::reject);

    // Modal: blocks here until the user clicks Unlock or Cancel
    int verdict = dlg.exec();

    // Branch on the verdict - this is what the real app will do too
    if(verdict == QDialog::Accepted) {
        QMessageBox::information(nullptr, "Result", "Accepted. Password length: " + QString::number(pwEdit->text().length())
    );
    }else{
        QMessageBox::information(nullptr, "Result", "Cancelled.");
    }

    // No app.exec() needed: the modal dialog ran its own event loop, 
    // and once we leave main()9 Qt cleans up everything via parent-child destruction.
    return 0;
}