#include "windowparam.h"
#include "ui_windowparam.h"

windowParam::windowParam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowParam)
{
    ui->setupUi(this);
}

windowParam::~windowParam()
{
    delete ui;
}

void windowParam::on_pushButton_clicked()
{
    this->close();
}
