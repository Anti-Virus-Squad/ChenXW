#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <login.h>
#include <admin.h>
#include <register.h>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_User_Type1_clicked();

    void on_User_Type2_clicked();


private:
    Ui::MainWindow *ui;
    login l1;
    admin a1;
};
#endif // MAINWINDOW_H
