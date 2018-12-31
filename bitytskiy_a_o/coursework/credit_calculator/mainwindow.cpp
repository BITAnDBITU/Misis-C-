#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "resultwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_doButton_clicked()
{
    if(!isDigit(ui->sumLineEdit->text()) || !isDigit(ui->percentLineEdit->text())
            || !isDigit(ui->timeLineEdit->text()) ){
        QMessageBox::StandardButton messageBox = QMessageBox::critical(this,"EXEPTION","ВВЕДЕНЫ НЕКОРЕКТНЫЕ ДАННЫЕ!"
                                                                       ,QMessageBox::Ok);
        if(messageBox == QMessageBox::Ok){
            hide();
            MainWindow *mainWindow = new MainWindow(this);
            mainWindow->show();
        }

    }else{
        hide();
        ResultWindow *resultWindow = new ResultWindow(this);
        QObject::connect(this,SIGNAL(sendText(QString)),resultWindow,SLOT(resirvedText(QString)));
        emit sendText(ui->sumLineEdit->text()+","+ ui->timeLineEdit->text()+","
                  +ui->percentLineEdit->text()+","+ui->periodComboBox->currentText()+","
                  +ui->rateComboBox->currentText()+","+ui->paymentTypeComboBox->currentText()+","+ui->dateEdit->date().toString("dd.MM.yyyy"));
        resultWindow->exec();
    }
}

bool MainWindow::isDigit(QString str){
    bool digit = true;
    if(str.length() == 0){
       return false;
    }else{
       for(int i(0);i < str.length();i++){
            if(str[i] == "."){
                continue;
            }
            if(!str[i].isDigit()){
                digit = false;
            }
        }
        return digit;
    }
}
