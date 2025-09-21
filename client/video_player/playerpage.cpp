#include "playerpage.h"
#include "ui_playerpage.h"
#include"util.h"
#include"login.h"
#include"toast.h"
#include<time.h>
PlayerPage::PlayerPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PlayerPage)
{
    ui->setupUi(this);
    volume=new Volume(this);
    playSpeed=new PlaySpeed(this);
    // 设置窗口边框
    setWindowFlag(Qt::FramelessWindowHint);
    // 设置窗口为模态对话框
    setAttribute(Qt::WA_ShowModal, true);
    // 最小化和关闭按钮
    connect(ui->minBtn, &QPushButton::clicked, this, &QWidget::showMinimized);
    connect(ui->quitBtn, &QPushButton::clicked, this, &QWidget::close);
    //音量调节窗口
    connect(ui->volumeBtn,&QPushButton::clicked,this,&PlayerPage::onVolumeBtnClicked);
    //倍数调节按钮
    connect(ui->speedBtn,&QPushButton::clicked,this,&PlayerPage::onSpeedBtnClicked);
    // 点赞
    connect(ui->likeImageBtn, &QPushButton::clicked, this,&PlayerPage::onLkeImageBtnClcked);
}

PlayerPage::~PlayerPage()
{
    delete ui;
}

void PlayerPage::mousePressEvent(QMouseEvent *event)
{
    LOG()<<"dianji";
    QPoint point=event->position().toPoint();

    if(ui->playHead->geometry().contains(point))
    {
        if(event->button()==Qt::LeftButton)
        {
            dragPos=event->globalPosition().toPoint()-geometry().topLeft();
            return;
        }
    }
    QWidget::mousePressEvent(event);
}

void PlayerPage::mouseMoveEvent(QMouseEvent *event)
{
    QPoint point=event->position().toPoint();
    LOG()<<"滑动";
    if(ui->playHead->geometry().contains(point))
    {
        if(event->buttons()==Qt::LeftButton)
        {
            move(event->globalPosition().toPoint()-dragPos);
            return;
        }
    }
    QWidget::mouseMoveEvent(event);
}

void PlayerPage::onVolumeBtnClicked()
{
    moveVolumeWindows(mapToGlobal(QPoint(0,0)));
    volume->show();
}

void PlayerPage::onSpeedBtnClicked()
{
    movePlaySpeedWindows(mapToGlobal(QPoint(0, 0)));
    playSpeed->show();
}

void PlayerPage::onLkeImageBtnClcked()
{
    // 检测用户是否登录，登录时才能点赞
    Login* login = new Login();
    login->show();

    Toast::showMessage("提示");
}

void PlayerPage::moveVolumeWindows(const QPoint &point)
{

    QPoint newPoint = point + QPoint(this->width() - volume->width() - 13,533);

    volume->move(newPoint);
}

void PlayerPage::movePlaySpeedWindows(const QPoint &point)
{
    QPoint newPoint = point + QPoint(this->width() - playSpeed->width()-72, 563);

    playSpeed->move(newPoint);
}
