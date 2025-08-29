#include "startuppage.h"
#include<QLabel>
#include<QTimer>
StartupPage::StartupPage(QDialog *parent)
    : QDialog{parent}
{
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool);
    // setFixedSize(1450,860);//PC
    setFixedSize(725,430);//笔记本
    setStyleSheet("background-color:#FFFFFF");


    QLabel* imageLabel =new QLabel(this);
    imageLabel->setPixmap(QPixmap(":/images/startupPage/biteshipin.png"));
    // imageLabel->move(524,374);//PC
    imageLabel->move(192,167);//笔记本
}


void StartupPage::StartTimer()
{
    QTimer*timer=new QTimer();
    connect(timer,&QTimer::timeout,this,[=](){
        timer->stop();
    delete timer;
        close();
    });
        timer->start(2000);
}
