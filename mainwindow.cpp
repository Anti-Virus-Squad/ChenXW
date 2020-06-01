#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QLineEdit>
#include <QTextStream>
#include <QFileDialog>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_pushButton_clicked()
{
    path = QFileDialog::getOpenFileName(
                    this, "选择CLIENT文件",
                    "/",
                    "程序文件 (*.exe);; 所有文件 (*.*);; ");
    int  i = path.lastIndexOf("/");
    filepath = path.left(i + 1);
    qDebug() << "p=" << path;
    qDebug() << "pf=" << filepath;
}*/

void MainWindow::on_User_Type1_clicked()
{
    this->close();
    QFile file("user_type.txt"); //用户类型文件
    if (!file.open(QFile::WriteOnly | QFile::Text))     //检测文件是否打开
    {
        QMessageBox::information(this, "Error Message", "Please Select a Text File!");
        return;
    }
    QTextStream out(&file);
    out<<"a";
    file.close();
    a1.show();
}

void MainWindow::on_User_Type2_clicked()
{
    this->close();
    QFile file("user_type.txt"); //用户类型文件
    if (!file.open(QFile::WriteOnly | QFile::Text))     //检测文件是否打开
    {
        QMessageBox::information(this, "Error Message", "Please Select a Text File!");
        return;
    }
    QTextStream out(&file);
    out<<"u";
    file.close();
    l1.show();
}


