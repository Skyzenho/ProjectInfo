#ifndef CONFIGWINDOW_H
#define CONFIGWINDOW_H

#include <QDialog>
#include <QDebug>


namespace Ui {
class ConfigWindow;
}

class ConfigWindow : public QDialog
{


public:
    explicit ConfigWindow(QWidget *parent = 0);
    ~ConfigWindow();

private slots:
   void on_LevelButton_clicked();

   void on_Taillepetit_clicked();

private:
   Ui::ConfigWindow *ui;
public:
   int taille;

};
#endif // CONFIGWINDOW_H
