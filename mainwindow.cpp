#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //设置抽奖系统时间
    /*ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    QTimer *timer = new QTimer(this);
    this->connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);*/
    timerID=startTimer(1000);
    ui->lcdNumber->setDigitCount(19);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);


    //加载奖品图片
    QString StrWidth,StrHeigth;
    QString filename="D:\\ad.jpg";
    QImage* img=new QImage,* scaledimg=new QImage;//分别保存原图和缩放之后的图片
    if(! ( img->load(filename) ) ) //加载图像
    {
        QMessageBox::information(this,tr("打开图像失败"),tr("打开图像失败!"));
        delete img;
        return;
    }
    int Owidth=img->width(),Oheight=img->height();
    int Fwidth,Fheight;       //缩放后的图片大小
    ui->label->setGeometry(20,50,420,450);
    int Mul;            //记录图片与label大小的比例，用于缩放图片
    if(Owidth/400>=Oheight/400)
        Mul=Owidth/400;
    else
        Mul=Oheight/400;
    Fwidth=Owidth/Mul;
    Fheight=Oheight/Mul;
    *scaledimg=img->scaled(Fwidth,Fheight,Qt::KeepAspectRatio);
    ui->label->setPixmap(QPixmap::fromImage(*scaledimg));

    //this->exec();
}

MainWindow::~MainWindow()
{
    //delete timer;
    delete ui;
}
//时钟
void MainWindow::timerEvent(QTimerEvent *event)
{
    if (event->timerId()==timerID)
    {
        QDateTime time = QDateTime::currentDateTime();
        QString str = time.toString("yyyy-MM-dd hh:mm:ss");
        ui->lcdNumber->display(str);
    }
}

void MainWindow::timerUpdate()
{

    int num=0234023;
    QString str = QString::number(num);

}

//抽取随机数
void MainWindow::on_pushButton_clicked()
{
    QString maximum = ui->lineEdit->text();
    int maxNumber=1;
    maxNumber = maximum.toInt();
    int lottery = QRandomGenerator::global()->bounded(1, maxNumber);
    QString str = QString::number(lottery);
    for(int i=1;i<100;++i)
    {
        lottery = QRandomGenerator::global()->bounded(1, maxNumber);
        QString str = QString::number(lottery);
        ui->lotteryBrowser->setText(str);
        sleep(100);
    }
}

//延时函数，用于抽奖数字滚动效果
void MainWindow::sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
