#include "updatememberinfo.h"
#include "ui_updatememberinfo.h"

UpdateMemberInfo::UpdateMemberInfo(QString val,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateMemberInfo)
{
    ui->setupUi(this);
    qry = new QSqlQuery(conn.mydb);
    id = val;
    qDebug() << "Update ID : " << id;
    QString quer = "select name,surname,sex,dob,duration from memberdb where id=" + id;
    qDebug() << "Query : " << quer;
    qDebug() << qry->value(0).toString();
    qry->exec(quer);
    while(qry->next()) {
        ui->memberNameUpdate->setText(qry->value(0).toString());
        ui->memberSurnameUpdate->setText(qry->value(1).toString());
        ui->memberIDUpdate->setText(id);
        if(qry->value(2).toString() == ui->radioButton_femaleUpdate->text()){
            ui->radioButton_femaleUpdate->setChecked(1);
        }
        else if(qry->value(2).toString() == ui->radioButton_maleUpdate->text()){
            ui->radioButton_maleUpdate->setChecked(1);
        }
        QDate date = QDate::fromString(qry->value(3).toString(),"dd/MM/yyyy");
        qDebug() << "Date: " << qry->value(3).toString();

        ui->dateEditUpdate->setDate(date);

        ui->spinBoxUpdate->setValue(qry->value(4).toInt());
    }

}

UpdateMemberInfo::~UpdateMemberInfo()
{
    delete ui;
}

void UpdateMemberInfo::on_pushButton_clicked()
{
    qry = new QSqlQuery(conn.mydb);
    QString id,name,surname,sex,date,duration;
    id = ui->memberIDUpdate->text();
    name = ui->memberNameUpdate->text();
    surname = ui->memberSurnameUpdate->text();
    if(ui->radioButton_femaleUpdate->isChecked())
        sex = ui->radioButton_femaleUpdate->text();
    else if(ui->radioButton_maleUpdate->isChecked())
        sex = ui->radioButton_maleUpdate->text();
    QDate dob = ui->dateEditUpdate->date();
    date = dob.toString("dd/MM/yyyy");
    qint16 dur = ui->spinBoxUpdate->value();
    duration = QString::number(dur);
    QString insertQ = "Update memberdb set id=" + id + ", name='"+ name + "', surname='" + surname + "', sex='" + sex + "', dob='" + date + "', duration=" + duration  ;
    qDebug() << "Query : " << insertQ;
    qry->exec(insertQ);
    UpdateMemberInfo::close();
}

