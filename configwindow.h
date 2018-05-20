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
    void on_Taillepetit_toggled(bool checked);

    void on_Taillemoyen_toggled(bool checked);

    void on_Taillegrand_toggled(bool checked);

private:
   Ui::ConfigWindow *ui;
public:
   int taille;
};
#endif // CONFIGWINDOW_H
