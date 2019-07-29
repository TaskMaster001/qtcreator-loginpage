#include "dialog.h"
#include "ui_dialog.h"
#include "QProcess"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QProcess exec;

    exec.execute("sshpass -p 'zeropoint' ssh pooja@192.168.1.104");
}

void Dialog::on_pushButton_2_clicked()
{

}
