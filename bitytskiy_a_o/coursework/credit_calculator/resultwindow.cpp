#include "resultwindow.h"
#include "ui_resultwindow.h"
#include "mainwindow.h"
#include"dosrochpogash.h"
#include <QTableWidget>
#include <QMessageBox>
#include <QStringList>
#include <QTableWidgetItem>
#include<QtMath>


ResultWindow::ResultWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultWindow)
{
   ui->setupUi(this);

}

ResultWindow::~ResultWindow()
{
    delete ui;
}

void ResultWindow::on_pushButton_clicked()
{
   QMessageBox::StandardButton messageBox =  QMessageBox::question(this,"Sure?","Вы уверены?"
                                                                   ,QMessageBox::No|QMessageBox::Yes);
   if(messageBox == QMessageBox::Yes){
       hide();
       MainWindow *mainWindow = new MainWindow(this);
       mainWindow->show();
   }

}
void ResultWindow::resirvedText(QString str){
    QStringList list = str.split(',');
    count = list.at(0);
    double_count = count.toDouble(); 
    time = list.at(1);
    percent = list.at(2);
    period = list.at(3);
    typePercent = list.at(4);
    payType = list.at(5);
    startDate = QDate::fromString(list.at(6),"dd.MM.yyyy");
    startDate3.setDate(startDate.year(),startDate.month(),startDate.day());
    createTable(ui->tableWidget);

}

void ResultWindow::resirvedText2(QString str)
{
    QStringList list = str.split(',');
    count = list.at(0);
    double_count = count.toDouble();
    time = list.at(1);
    percent = list.at(2);
    period = list.at(3);
    typePercent = list.at(4);
    payType = list.at(5);
    startDate2 = QDate::fromString(list.at(6),"dd.MM.yyyy");
    startDate3.setDate(startDate2.year(),startDate2.month(),startDate2.day());
    dosrochSumma = list.at(7);
    dosrochDate = QDate::fromString(list.at(8),"dd.MM.yyyy");
    createDosrochTable(ui->tableWidget);
}

void ResultWindow::createTable(QTableWidget *table){
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setColumnCount(6);
    if(period == "Месяцев"){
        table->setRowCount(time.toInt());
    }else{
        table->setRowCount(time.toInt()*12);
    }

    setTableHeaders(table);

    if(payType == "Аннуитетные"){
        countPayAnnuit();
    }else if(payType == "Дифференцированные"){
        if(period == "Месяцев"){
            monthPay = double_count / time.toDouble();
        }else{
            monthPay = double_count /( time.toDouble()*12);
        }
    }

    for (int i(0);i < table->rowCount();i++) {
        QString str = startDate.toString("dd.MM.yyyy");
        QString opisanie = "Ежемесячный платеж за "+startDate.toString("MM/yyyy");
        QTableWidgetItem * item =new QTableWidgetItem(str);
        QTableWidgetItem * item2 =new QTableWidgetItem(opisanie);
        item->setTextAlignment(Qt::AlignCenter);
        item2->setTextAlignment(Qt::AlignCenter);
        table->setItem(i,0,item);
        table->setItem(i,5,item2);

        if(startDate.month() < 12){
           startDate = startDate.addMonths(1);
        }else{
           startDate.setDate(startDate.year()+1,1,startDate.day());
        }

        if(payType == "Аннуитетные"){
           fillTableAnnuit(table, i);
        }else if(payType == "Дифференцированные"){
           fillTableDiff(table, i);
        }
    }

    if(payType == "Аннуитетные"){
        allSum = monthPay * (table->rowCount());
        overPay = allSum - count.toDouble();
        ui->sumInMonthLabel->setText(QString::number(monthPay,'g',6));
        ui->mainSumLabel->setText(QString::number(allSum,'g',6));
        ui->overPayLabel->setText(QString::number(overPay,'g',6));
    } else if(payType == "Дифференцированные"){

    }

}

void ResultWindow::createDosrochTable(QTableWidget *table)
{
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setColumnCount(6);
    if(period == "Месяцев"){
        table->setRowCount(time.toInt()+1);
    }else{
        table->setRowCount(time.toInt()*12 + 1);
    }

    setTableHeaders(table);

    if(payType == "Аннуитетные"){
        countPayAnnuit();
    }else if(payType == "Дифференцированные"){
        if(period == "Месяцев"){
            monthPay = double_count / time.toDouble();
        }else{
            monthPay = double_count /( time.toDouble()*12);
        }
    }

    int time_before_dosroch(0);
    if(startDate2.year() == dosrochDate.year()){
        time_before_dosroch = dosrochDate.month() - startDate2.month();
    }else{
        time_before_dosroch+= (dosrochDate.year() - startDate2.year())*12;
        time_before_dosroch+= dosrochDate.month() - startDate2.month();
    }

    for (int i(0);i<time_before_dosroch;i++) {
        QString str = startDate2.toString("dd.MM.yyyy");
        QString opisanie = "Ежемесячный платеж за "+startDate2.toString("MM/yyyy");
        QTableWidgetItem * item =new QTableWidgetItem(str);
        QTableWidgetItem * item2 =new QTableWidgetItem(opisanie);
        item->setTextAlignment(Qt::AlignCenter);
        item2->setTextAlignment(Qt::AlignCenter);
        table->setItem(i,0,item);
        table->setItem(i,5,item2);

        if(startDate2.month() < 12){
           startDate2 = startDate2.addMonths(1);
        }else{
           startDate2.setDate(startDate2.year()+1,1,startDate2.day());
        }

        if(payType == "Аннуитетные"){
           fillTableAnnuit(table, i);
    }else if(payType == "Дифференцированные"){
           fillTableDiff(table, i);
        }

    }

    QString str = dosrochDate.toString("dd.MM.yyyy");
    QString opisanie = "Досрочное погашение";
    QTableWidgetItem * item =new QTableWidgetItem(str);
    QTableWidgetItem * item2 =new QTableWidgetItem(opisanie);
    item->setTextAlignment(Qt::AlignCenter);
    item2->setTextAlignment(Qt::AlignCenter);
    table->setItem(time_before_dosroch,0,item);
    table->setItem(time_before_dosroch,5,item2);

    if(double_count >= dosrochSumma.toDouble()){
        QTableWidgetItem * item3 = new QTableWidgetItem(dosrochSumma);
        QTableWidgetItem * item_3 = new QTableWidgetItem(dosrochSumma);
        item3->setTextAlignment(Qt::AlignCenter);
        item_3->setTextAlignment(Qt::AlignCenter);
        table->setItem(time_before_dosroch,1,item3);
        table->setItem(time_before_dosroch,2,item_3);

        QString per = "0.0";
        QTableWidgetItem * item4 =new QTableWidgetItem(per);
        item4->setTextAlignment(Qt::AlignCenter);
        table->setItem(time_before_dosroch,3,item4);

        double_count -= dosrochSumma.toDouble();
        qreal ost = double_count;
        QString ostatok = QString::number(ost,'g',6); ;
        QTableWidgetItem * item5 =new QTableWidgetItem(ostatok);
        item5->setTextAlignment(Qt::AlignCenter);
        table->setItem(time_before_dosroch,4,item5);
    }else{        
        qreal qlean = dosrochSumma.toDouble() - (dosrochSumma.toDouble() - double_count);
        double_count = 0.0;
        QString qlean_str = QString::number(qlean,'g',4); ;
        QTableWidgetItem * item3 =new QTableWidgetItem(qlean_str);
        item3->setTextAlignment(Qt::AlignCenter);
        table->setItem(time_before_dosroch,1,item3);
        table->setItem(time_before_dosroch,2,item3);

        QString per = "0.0";
        QTableWidgetItem * item4 =new QTableWidgetItem(per);
        item4->setTextAlignment(Qt::AlignCenter);
        table->setItem(time_before_dosroch,3,item4);

        QString ostatok = "0.0";
        QTableWidgetItem * item5 =new QTableWidgetItem(ostatok);
        item5->setTextAlignment(Qt::AlignCenter);
        table->setItem(time_before_dosroch,4,item5);
    }
    if(double_count != 0.0){
        if(payType == "Аннуитетные"){
            countPayAnnuitDosroch();
        }else if(payType == "Дифференцированные"){
            qreal timeAfterDosroch = time.toDouble() - startDate2.month() + 1 ;
            if(period == "Месяцев"){
                monthPay = double_count / timeAfterDosroch;
            }else{
                monthPay = double_count /(timeAfterDosroch*12);
            }
        }
        for (int i(time_before_dosroch+1); i < table->rowCount(); i++) {
            QString str = startDate2.toString("dd.MM.yyyy");
            QString opisanie = "Ежемесячный платеж за "+startDate2.toString("MM/yyyy");
            QTableWidgetItem * item =new QTableWidgetItem(str);
            QTableWidgetItem * item2 =new QTableWidgetItem(opisanie);
            item->setTextAlignment(Qt::AlignCenter);
            item2->setTextAlignment(Qt::AlignCenter);
            table->setItem(i,0,item);
            table->setItem(i,5,item2);

            if(startDate2.month() < 12){
               startDate2 = startDate2.addMonths(1);
            }else{
               startDate2.setDate(startDate2.year()+1,1,startDate2.day());
            }

            if(payType == "Аннуитетные"){
               fillTableAnnuit(table, i);
            }else if(payType == "Дифференцированные"){
               fillTableDiff(table, i);
            }

        }
    }

}

void ResultWindow::countPayAnnuit(){
    qreal percent_double = 0.0;
    if(typePercent == "% в год"){
       percent_double = 1 + 0.01*percent.toDouble()/12;
    }else if(typePercent == "% в месяц"){
       percent_double = 1 + 0.01*percent.toDouble();
    }
    if(period == "Месяцев"){
        monthPay = qPow(percent_double,time.toDouble())*(percent_double - 1) * double_count
                /(qPow(percent_double,time.toDouble()) - 1);
    }else{
        monthPay = qPow(percent_double,time.toDouble()*12)*(percent_double - 1) * double_count
                /(qPow(percent_double,time.toDouble()*12) - 1);
    }
}

void ResultWindow::countPayAnnuitDosroch()
{
    qreal percent_double = 0.0;
    qreal timeAfterDosroch = time.toDouble() - startDate2.month() + 1;
    if(typePercent == "% в год"){
       percent_double = 1 + 0.01*percent.toDouble()/12;
    }else if(typePercent == "% в месяц"){
       percent_double = 1 + 0.01*percent.toDouble();
    }
    if(period == "Месяцев"){
        monthPay = qPow(percent_double,timeAfterDosroch)*(percent_double - 1) * double_count
                /(qPow(percent_double,timeAfterDosroch) - 1);
    }else{
        monthPay = qPow(percent_double,timeAfterDosroch * 12)*(percent_double - 1) * double_count
                /(qPow(percent_double,timeAfterDosroch * 12) - 1);
    }
}

void ResultWindow::fillTableAnnuit(QTableWidget *table, int i)
{
       QString str = QString::number(monthPay,'g',6);
       QTableWidgetItem * item3 =new QTableWidgetItem(str);
       item3->setTextAlignment(Qt::AlignCenter);
       table->setItem(i,1,item3);

       qreal per = 0.0;
       if(typePercent == "% в год"){
           per = double_count * percent.toDouble()/1200;
       }else if(typePercent == "% в месяц"){
           per = double_count * 0.01 * percent.toDouble();
       }
       QString str2 = QString::number(per,'g',4);
       QTableWidgetItem * item4 =new QTableWidgetItem(str2);
       item4->setTextAlignment(Qt::AlignCenter);
       table->setItem(i,3,item4);

       qreal cleanpay = monthPay - per;
       QString str3 = QString::number(cleanpay,'g',6);
       QTableWidgetItem * item5 =new QTableWidgetItem(str3);
       item5->setTextAlignment(Qt::AlignCenter);
       table->setItem(i,2,item5);

       double_count -= cleanpay;
       QString str4 = QString::number(double_count,'g',6);
       QTableWidgetItem * item6 =new QTableWidgetItem(str4);
       item6->setTextAlignment(Qt::AlignCenter);

       if(i!= table->rowCount()-1){
           table->setItem(i,4,item6);
       }else{
           QString str4 = QString::number(0,10);
           QTableWidgetItem * item6 =new QTableWidgetItem(str4);
           item6->setTextAlignment(Qt::AlignCenter);
           table->setItem(table->rowCount()-1,4,item6);
       }
}

void ResultWindow::fillTableDiff(QTableWidget *table, int i)
{
    QString str1 = QString::number(monthPay,'g',6);
    QTableWidgetItem * item1 =new QTableWidgetItem(str1);
    item1->setTextAlignment(Qt::AlignCenter);
    table->setItem(i,2,item1);

    qreal per = 0.0;
    if(typePercent == "% в год"){
        per = double_count * percent.toDouble()/1200;
    }else if(typePercent == "% в месяц"){
        per = double_count * 0.01 * percent.toDouble();
    }
    QString str2 = QString::number(per,'g',4);
    QTableWidgetItem * item2 =new QTableWidgetItem(str2);
    item2->setTextAlignment(Qt::AlignCenter);
    table->setItem(i,3,item2);

    qreal cleanpay = monthPay + per;
    QString str3 = QString::number(cleanpay,'g',6);
    QTableWidgetItem * item3 =new QTableWidgetItem(str3);
    item3->setTextAlignment(Qt::AlignCenter);
    table->setItem(i,1,item3);

    double_count -= monthPay;
    QString str4 = QString::number(double_count,'g',6);
    QTableWidgetItem * item4 =new QTableWidgetItem(str4);
    item4->setTextAlignment(Qt::AlignCenter);
    if(i!= table->rowCount()-1){
        table->setItem(i,4,item4);
    }else{
        QString str4 = QString::number(0,10);
        QTableWidgetItem * item4 =new QTableWidgetItem(str4);
        item4->setTextAlignment(Qt::AlignCenter);
        table->setItem(table->rowCount()-1,4,item4);
    }
}

void ResultWindow::setTableHeaders(QTableWidget *table)
{
    table->setHorizontalHeaderItem(0,new QTableWidgetItem("Дата"));
    table->setHorizontalHeaderItem(1,new QTableWidgetItem("Сумма"));
    table->setHorizontalHeaderItem(2,new QTableWidgetItem("Погашение основного долга"));
    table->setColumnWidth(2,200);
    table->setHorizontalHeaderItem(3,new QTableWidgetItem("Выплата процентов"));
    table->setColumnWidth(3,150);
    table->setHorizontalHeaderItem(4,new QTableWidgetItem("Остаток"));
    table->setHorizontalHeaderItem(5,new QTableWidgetItem("Описание"));
    table->setColumnWidth(5,250);

}

void ResultWindow::on_pushButton_dosroch_clicked()
{
    hide();
    DosrochPogash *window = new DosrochPogash(this);
    QObject::connect(this,SIGNAL(sendText(QString)),window,SLOT(resirvedText(QString)));
    emit sendText(count+","+time+","+percent+","+period+","+typePercent+","+payType+","+startDate3.toString("dd.MM.yyyy"));
    window->exec();
}

