#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool isDigit(QString str);

signals:
    void sendText(QString str);

private slots:
    void on_doButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
