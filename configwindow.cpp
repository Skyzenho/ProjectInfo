#include "configwindow.h"
#include "ui_configwindow.h"

ConfigWindow::ConfigWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigWindow)
{
    ui->setupUi(this);
    taille = 2;
    qDebug()<<"marche";

}

ConfigWindow::~ConfigWindow()
{
    delete ui;
}


void ConfigWindow::on_Taillepetit_toggled(bool checked)
{
    connect(ui->Taillepetit, SIGNAL(toggled(bool)), this, SLOT(petitpalet()));
}

void ConfigWindow::on_Taillemoyen_toggled(bool checked)
{
    if(checked){
        taille = 2;
    }
}

void ConfigWindow::on_Taillegrand_toggled(bool checked)
{
    if(checked){
        taille = 3;
    }
}

void ConfigWindow::on_LevelButton_clicked()
{
    qDebug()<<"marche";

}

void petitpalet(){
    qDebug()<<"marche";
    /*if(checked){
        taille = 1;
    }*/
}
