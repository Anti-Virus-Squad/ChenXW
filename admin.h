#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>

namespace Ui {
class admin;
}

class admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();
    QString output;


private slots:
    void on_admin_login_clicked();
    void on_read();

private:
    Ui::admin *ui;
};

#endif // ADMIN_H
