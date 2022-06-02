#ifndef ADDNEWMEMBER_H
#define ADDNEWMEMBER_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "logindialog.h"

namespace Ui {
class AddNewMember;
}

class AddNewMember : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewMember(QWidget *parent = nullptr);
    ~AddNewMember();
    LoginDialog conn;
    QSqlQuery *qry;

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddNewMember *ui;
};

#endif // ADDNEWMEMBER_H
