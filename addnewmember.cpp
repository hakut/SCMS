#include "addnewmember.h"
#include "ui_addnewmember.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

AddNewMember::AddNewMember(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewMember)
{
    ui->setupUi(this);
    ui->memberIDLineEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]*")));

}

AddNewMember::~AddNewMember()
{
    delete ui;
}

void AddNewMember::on_pushButton_clicked()
{
    qry = new QSqlQuery(conn.mydb);
    QString id,name,surname,sex,date,duration;
    id = ui->memberIDLineEdit->text();
    name = ui->memberNameLineEdit->text();
    surname = ui->memberSurnameLineEdit->text();
    if(ui->radioButton_female->isChecked())
        sex = ui->radioButton_female->text();
    else if(ui->radioButton_male->isChecked())
        sex = ui->radioButton_male->text();
    QDate dob = ui->dateEdit->date();
    date = dob.toString("dd/MM/yyyy");
    qint16 dur = ui->spinBox->value();
    duration = QString::number(dur);
    QString insertQ = "Insert into memberdb (id,name,surname,sex,dob,duration) values(" + id + ",'"+ name + "', '" + surname + "','" + sex + "', '" + date + "'," + duration + ")" ;
    qDebug() << "Query : " << insertQ;
    qry->exec(insertQ);
    AddNewMember::close();

}

