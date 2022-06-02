#ifndef UPDATEMEMBERINFO_H
#define UPDATEMEMBERINFO_H

#include <QDialog>
#include <QSqlQuery>
#include "logindialog.h"
namespace Ui {
class UpdateMemberInfo;
}

class UpdateMemberInfo : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateMemberInfo(QString val, QWidget *parent = nullptr);
    ~UpdateMemberInfo();
    QSqlQuery *qry;
    LoginDialog conn;
    QString id;

private slots:
    void on_pushButton_clicked();

private:
    Ui::UpdateMemberInfo *ui;
};

#endif // UPDATEMEMBERINFO_H
