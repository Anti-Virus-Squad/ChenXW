#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>
#include <license.h>
namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_Register_button_clicked();

private:
    Ui::Register *ui;
    License l1;
};

#endif // REGISTER_H
