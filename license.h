#ifndef LICENSE_H
#define LICENSE_H

#include <QMainWindow>

namespace Ui {
class License;
}

class License : public QMainWindow
{
    Q_OBJECT

public:
    explicit License(QWidget *parent = nullptr);
    ~License();
    QString output;

private slots:
    void on_Register_button_clicked();
    void on_Register_button_2_clicked();
    void on_read();
private:
    Ui::License *ui;
};

#endif // LICENSE_H
