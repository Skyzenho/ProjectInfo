#include "configwindow.h"
#include "ui_configwindow.h"

ConfigWindow::ConfigWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigWindow)
{
    ui->setupUi(this);
    taille = 2;
    qDebug()<<"init"<<endl;

}

ConfigWindow::~ConfigWindow()
{
    delete ui;
}


void ConfigWindow::on_LevelButton_clicked()
{
    qDebug()<<"Clicked"<<endl;

}

void ConfigWindow::on_Taillepetit_clicked()
{
    qDebug()<<"Petit Clicked"<<endl;
}
