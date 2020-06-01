#include "license.h"
#include "ui_license.h"
#include "mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QLineEdit>
#include <QProcess>
#include <QString>


License::License(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::License)
{
    ui->setupUi(this);
}

License::~License()
{
    delete ui;
}

void License::on_Register_button_clicked()
{
    QFile file("licen.txt");//注册用户信息文件
    if (!file.open(QFile::WriteOnly | QFile::Text))     //检测文件是否打开
    {
        QMessageBox::information(this, "Error Message", "Please Select a Text File!");
        return;
    }
    QTextStream out(&file);                 //分行写入文件
    out << ui->lic->text();  //Username
    out<<endl;
    file.close();

    //client();
     QProcess *pProces = new QProcess(this);
     connect(pProces, SIGNAL(readyRead()),this, SLOT(on_read()));
     QStringList list;
     pProces->start("client.exe");
 }
 void License::on_read()
 {
     QProcess *pProces = (QProcess *)sender();
     output += QString::fromLocal8Bit(pProces->readAll());
     ui->textEdit->setText(output);
 }
    //this->close();
     //加文本框，加取消


void License::on_Register_button_2_clicked()
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
