#include "configwindow.h"
#include "ui_configwindow.h"

ConfigWindow::ConfigWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigWindow)
{
    ui->setupUi(this);
    taille = 2;
}

ConfigWindow::~ConfigWindow()
{
    delete ui;
}


void ConfigWindow::on_Taillepetit_toggled(bool checked)
{
    if(checked){
        taille = 1;
    }
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
