#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include "logindialog.h"
#include "addnewmember.h"
#include "updatememberinfo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    LoginDialog conn;
    QSqlQuery *qry = new QSqlQuery(conn.mydb);
    QSqlQueryModel *modal = new QSqlQueryModel();
    QString val;
    UpdateMemberInfo *update;
private slots:
    void on_newMember_clicked();

    void on_delMember_clicked();

    void on_updateMember_clicked();

    void time_function();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    LoginDialog *logDialog;
    AddNewMember *addmember;
    UpdateMemberInfo *updateMem;
    QTimer *timer;
};
#endif // MAINWINDOW_H
