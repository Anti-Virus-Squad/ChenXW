#include "admin.h"
#include "ui_admin.h"
#include "mainwindow.h"

#include <QFile>
#include <QMessageBox>
#include <QLineEdit>
#include <QTextStream>
#include <QCheckBox>
#include <QProcess>
#include <QString>
#include <QDebug>


admin::admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

void admin::on_admin_login_clicked()
{
    QFile file("admin_info.txt"); //管理员信息文件
    if (!file.open(QFile::WriteOnly | QFile::Text))     //检测文件是否打开
    {
        QMessageBox::information(this, "Error Message", "Please Select a Text File!");
        return;
    }
    QTextStream out(&file);                 //分行写入文件
    out << ui->lineEdit_3->text();   //name
    out<<endl;
    out<<ui->lineEdit->text();   //password
    out<<endl;
    if(ui->checkBox->isChecked()==true)
        out<<"ten";
    else
        out<<"fifty";
    file.close();

    QProcess *pProces = new QProcess(this);
    connect(pProces, SIGNAL(readyRead()),this, SLOT(on_read()));
    QStringList list;

    pProces->start("client.exe");
}
void admin::on_read()
{
    QProcess *pProces = (QProcess *)sender();
    output += QString::fromLocal8Bit(pProces->readAll());
    ui->textEdit->setText(output);
}

