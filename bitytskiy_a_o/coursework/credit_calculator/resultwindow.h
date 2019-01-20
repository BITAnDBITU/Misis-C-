#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QDialog>
#include <QTableWidget>
#include <QDate>
namespace Ui {
class ResultWindow;
}

class ResultWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ResultWindow(QWidget *parent = nullptr);
    ~ResultWindow();

    void createTable(QTableWidget *table);
    void createDosrochTable(QTableWidget *table);
    void countPayAnnuit();
    void countPayAnnuitDosroch();
    void fillTableAnnuit(QTableWidget *table, int i);
    void fillTableDiff(QTableWidget *table, int i);
    void setTableHeaders(QTableWidget *table);

signals:
    void sendText(QString str);

public slots:
    void resirvedText(QString str);
    void resirvedText2(QString str);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_dosroch_clicked();


private:
    Ui::ResultWindow *ui;
    QString count;
    qreal double_count;
    qreal allSum;
    qreal overPay;
    QString time;
    QString payType;
    QString period;
    QString percent;
    QString typePercent;
    QDate dosrochDate;
    QString dosrochSumma;
    qreal monthPay;
    QDate startDate;
    QDate startDate2;
    QDate startDate3;
};

#endif // RESULTWINDOW_H
