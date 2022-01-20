#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include <QTime>
#include <QtGlobal>
#include <QRandomGenerator>
#include <qdatetime.h>
#include <QLCDNumber>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void timerUpdate();
    void sleep(unsigned int msec);
    void timerEvent(QTimerEvent *) override;


private slots:
    void on_pushButton_clicked();

private:
    //QTimer *timer;
    int timerID;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
