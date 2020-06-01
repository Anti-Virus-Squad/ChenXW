#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <register.h>
#include "ui_login.h"
namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    QString output;

private slots:
    void on_register_2_clicked();

    void on_login_button_clicked();

    void on_login_button_2_clicked();

    void on_read();

private:
    Ui::login *ui;
     Register r1;
};

#endif // LOGIN_H
