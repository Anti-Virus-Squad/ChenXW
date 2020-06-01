#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QLineEdit>
#include <QTextStream>
#include <QProcess>
#include <QDebug>


login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_register_2_clicked()
{
    this->close();
    r1.show();
}

void login::on_login_button_clicked()
{
        QFile file("Userinfo.txt");//用户信息文件
        if (!file.open(QFile::WriteOnly | QFile::Text))     //检测文件是否打开
        {
            QMessageBox::information(this, "Error Message", "Please Select a Text File!");
            return;
        }
        QTextStream out(&file);                 //分行写入文件
        out << ui->lineEdit_2->text();
        out<<endl;
        out<<ui->lineEdit->text();
        file.close();

        QProcess *pProces = new QProcess(this);
        connect(pProces, SIGNAL(readyRead()),this, SLOT(on_read()));
        QStringList list;

        pProces->start("client.exe");

        //this->close();
        //client();
        //加上文本框，输出回传的信息，加按钮（返回）

}

void login::on_login_button_2_clicked()
{
    QFile file("non_ticket.txt");//是否删除ticket文件
    if (!file.open(QFile::WriteOnly | QFile::Text))     //检测文件是否打开
    {
        QMessageBox::information(this, "Error Message", "Please Select a Text File!");
        return;
    }
    QTextStream out(&file);

    out<<"1";
    file.close();
}
void login::on_read()
{
    QProcess *pProces = (QProcess *)sender();
    output += QString::fromLocal8Bit(pProces->readAll());
    ui->textEdit->setText(output);
}
