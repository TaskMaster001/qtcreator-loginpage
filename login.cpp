#include "login.h"
#include "ui_login.h"
#include "dialog.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("/home/vinay/Desktop/NAnda/Database/database.db"); //change the directory path based on ur database

    if(mydb.open())
        ui->label_4->setText("Connected...");
    else
        ui->label_4->setText("Dis-Connected...");
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString username,password;
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_2_password->text();

    if(!mydb.open())
    {
        qDebug()<<"Not Connected to DataBase";
        return;

    }

    QSqlQuery qry;

    if(qry.exec("select * from login where name ='"+ username +"' and password='"+password +"'"))
    {
    int count=0;
        if(qry.next())
        {
            count++;
        }

        if(count==1){
            ui->label_4->setText("Username and password is correct");
            this->hide();
            Dialog dialog;
            dialog.setModal(true);
            dialog.exec();

        }
        if(count>1)
            ui->label_4->setText("Username and password is In-correct");
        if(count<1)
            ui->label_4->setText("Username or password is not Available");


    }
}
