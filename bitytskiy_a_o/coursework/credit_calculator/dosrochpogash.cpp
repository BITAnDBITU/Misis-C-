#include "dosrochpogash.h"
#include "ui_dosrochpogash.h"
#include <QMessageBox>

DosrochPogash::DosrochPogash(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DosrochPogash)
{
    ui->setupUi(this);
}

DosrochPogash::~DosrochPogash()
{
    delete ui;
}

void DosrochPogash::resirvedText(QString str)
{
    QStringList list = str.split(',');
    count = list.at(0);
    time = list.at(1);
    percent = list.at(2);
    period = list.at(3);
    typePercent = list.at(4);
    payType = list.at(5);
    startDate = QDate::fromString(list.at(6),"dd.MM.yyyy");

}

void DosrochPogash::on_pushButton_perechet_clicked()
{
    if(ui->dateEdit_dosrochdate->date().day() != startDate.day()){
        QMessageBox::warning(this,"EXCEPTION","День должен совпадать с днем кредита!");
        hide();
        DosrochPogash *window = new DosrochPogash(this);
        window->exec();
    }else if(ui->dateEdit_dosrochdate->date().month() < startDate.month()
             || ui->dateEdit_dosrochdate->date().year() < startDate.year()){
        QMessageBox::warning(this,"EXCEPTION","Некоректные данные!");
        hide();
        DosrochPogash *window = new DosrochPogash(this);
        window->exec();

    }else if(ui->lineEdit_summa->text() == ""){
        hide();
        resultWindow = new ResultWindow(this);
        QObject::connect(this,SIGNAL(sendText(QString)),resultWindow,SLOT(resirvedText(QString)));
        emit sendText(count+","+time+","+percent+","+period+","
                      +typePercent+","+payType+","+startDate.toString("dd.MM.yyyy"));
        resultWindow->exec();

    }else{
        hide();
        resultWindow = new ResultWindow(this);
        QObject::connect(this,SIGNAL(sendText(QString)),resultWindow,SLOT(resirvedText2(QString)));
        emit sendText(count+","+time+","+percent+","+period+","
                      +typePercent+","+payType+","+startDate.toString("dd.MM.yyyy")+","+ui->lineEdit_summa->text()
                      +","+ui->dateEdit_dosrochdate->date().toString("dd.MM.yyyy"));
        resultWindow->exec();
    }
}


void DosrochPogash::on_back_button_clicked(){
    hide();
    resultWindow = new ResultWindow(this);
    QObject::connect(this,SIGNAL(sendText(QString)),resultWindow,SLOT(resirvedText(QString)));
    emit sendText(count+","+time+","+percent+","+period+","
                  +typePercent+","+payType+","+startDate.toString("dd.MM.yyyy"));
    resultWindow->exec();
}
