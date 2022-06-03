#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QApplication>
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT
public:
    bool correct = false;
    bool is_open_db = false;
    QSqlDatabase mydb;
    QSqlQuery *qry;
    bool isOpen(){
        if(is_open_db)
            return true;
        else
            return false;
    }
    void connClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen(){
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName(qApp->applicationDirPath() + "/memberdb.sqlite");

        if(mydb.open()){
            is_open_db = true;
            qry = new QSqlQuery(mydb);
            qry->exec("CREATE TABLE memberdb(id int primary key, name varchar(20), surname varchar(20), sex varchar(10), dob DATE, duration int)");
            return true;
        }
        else{
             return false;
        }
    }

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
