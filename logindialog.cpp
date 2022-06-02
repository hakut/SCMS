#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->passLineEdit->setEchoMode(QLineEdit::Password);

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_clicked()
{
    QString uname = ui->nameLineEdit->text();
    QString pass = ui->passLineEdit->text();
    if(uname == "admin" && pass == "passwd"){
        QMessageBox::information(this,"Login","Login Successfull!");
        hide();
        correct = true;
    }
    else{
        QMessageBox::information(this,"Login","Login Failed!");
    }
}

