#include "admininterface.h"
#include "ui_admininterface.h"

adminInterface::adminInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminInterface)
{
    ui->setupUi(this);
}

adminInterface::~adminInterface()
{
    delete ui;
}
