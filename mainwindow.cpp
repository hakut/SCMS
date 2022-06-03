#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "addnewmember.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{   
    ui->setupUi(this);
    QPixmap pix(":/Resources/logo.jpg");

    ui->label_image->setPixmap(pix);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(time_function()));
    timer->start(1000);
    conn.connOpen();
    this->modal->setQuery("select * from memberdb");
    ui->tableView->setModel(modal);


}

MainWindow::~MainWindow()
{
    delete ui;
    conn.connClose();

}



void MainWindow::on_newMember_clicked()
{
    addmember = new AddNewMember;
    addmember->show();
    addmember->exec();
    this->modal->setQuery("select * from memberdb");
    ui->tableView->setModel(modal);
}


void MainWindow::on_delMember_clicked()
{
    ui->tableView->setModel(modal);
    qry = new QSqlQuery(conn.mydb);
    qry->exec("Delete from memberdb where id=" + val);
    this->modal->setQuery("select * from memberdb");
    ui->tableView->setModel(modal);
}


void MainWindow::on_updateMember_clicked()
{
    updateMem = new UpdateMemberInfo(val,this);
    updateMem->show();
    updateMem->exec();
    this->modal->setQuery("select * from memberdb");
    ui->tableView->setModel(modal);
}

void MainWindow::time_function(){
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    QString time_text = time.toString("hh:mm:ss");
    QString date_text = date.toString("dd/MM/yyyy");
    ui->label_date->setText(date_text);
    ui->label_time->setText(time_text);
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    val = ui->tableView->model()->data(index).toString();
    qDebug() << val;
}

