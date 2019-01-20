#ifndef DOSROCHPOGASH_H
#define DOSROCHPOGASH_H

#include <QDialog>
#include<QDate>
#include "resultwindow.h"
namespace Ui {
class DosrochPogash;
}

class DosrochPogash : public QDialog
{
    Q_OBJECT

public:
    explicit DosrochPogash(QWidget *parent = nullptr);
    ~DosrochPogash();

public slots:
    void resirvedText(QString str);

signals:
    void sendText(QString str);

private slots:
    void on_pushButton_perechet_clicked(); 
    void on_back_button_clicked();

private:
    ResultWindow *resultWindow;
    Ui::DosrochPogash *ui;
    QString count;
    QString time;
    QString payType;
    QString period;
    QString percent;
    QString typePercent;
    qreal monthPay;
    QDate startDate;
};

#endif // DOSROCHPOGASH_H
