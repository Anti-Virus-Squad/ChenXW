#include "register.h"
#include "ui_register.h"
#include <QFile>
#include <QMessageBox>
#include <QLineEdit>
#include <QTextStream>
#include <QString>
#include <QProcess>



Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_Register_button_clicked()
{
    QString p1=ui->Pass->text();
    QString p2=ui->Confirm->text();
    if(p1!=p2)
    {
        QMessageBox::information(this, "Error Message", "两次输入密码不一致!请检查!");
        return;
    }
    QFile file("normal_register.txt");//注册用户信息文件
    if (!file.open(QFile::WriteOnly | QFile::Text))     //检测文件是否打开
    {
        QMessageBox::information(this, "Error Message", "Please Select a Text File!");
        return;
    }
    QTextStream out(&file);                 //分行写入文件
    out << ui->User->text();  //Username
    out<<endl;
    out<<ui->Pass->text();    //Password
    out<<endl;
    file.close();
    this->hide();
    l1.show();

}
