#include "video_player.h"
#include "./ui_video_player.h"
#include<QGraphicsDropShadowEffect>
#include<QMouseEvent>
#include"uploadvideopage.h"
#include"util.h"
video_player::video_player(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::video_player)
{
    // movesize=0;
    // presssize=0;
    ui->setupUi(this);
    initUI();
    connectSignalAndSlot();
}
// 初始化实例指针，并获取实例
video_player* video_player::instance = nullptr;
video_player *video_player::getInstance()
{
    if (instance == nullptr) {
        instance = new video_player();
    }
    return instance;
}

video_player::~video_player()
{
    delete ui;
}

void video_player::onSwitchPage(int pageId)
{
    //此处有小bug，编号依次为0，1，2 homepage， syspage  ，myselfpage
    LOG()<<"pageId"<<pageId;
    //写死
    resetswitchBtnInfo(pageId);
    //这个if等修好了就删除
    if(pageId==1||pageId==2)
        pageId=pageId==1?2:1;

    ui->stackedWidget->setCurrentIndex(pageId);

}

void video_player::connectSignalAndSlot()
{
    //缩小按钮和关闭按钮
    connect(ui->quitBtn,&QPushButton::clicked,this,&QWidget::close);
    connect(ui->minBtn, &QPushButton::clicked, this, &QWidget::showMinimized);

    //页面切换按钮
    connect(ui->homePageBtn,&PageSwitchButton::switchPage,this,&video_player::onSwitchPage);
    connect(ui->myPageBtn,&PageSwitchButton::switchPage,this,&video_player::onSwitchPage);
    connect(ui->sysPageBtn,&PageSwitchButton::switchPage,this,&video_player::onSwitchPage);
    //上传视频按钮
    // ????
    connect(ui->myPage, &MyselfWidget::switchUploadVideoPage, this, [=](int pageId){
        LOG()<<"切换到上传视频⻚⾯";
        onSwitchPage(pageId);
    });

    // 视频上传页面切换到我的页面
    connect(ui->uploadPage, &UploadVideoPage::switchMySelfPage, this, [=]
            (int pageId){
                onSwitchPage(pageId);
            });

}

void video_player::resetswitchBtnInfo(int PageId)
{
    //设置按钮文本和图片的高亮
    //设置文本
    QList<PageSwitchButton*> switchBtns=findChildren<PageSwitchButton*>();
    for(auto switchBtn:switchBtns)
    {
        if(switchBtn->getPageId()!=PageId)
        {
            switchBtn->setTextColor("#999999");
        }
    }

    //设置图片
    if(PageId==HomePage)
    {
        ui->homePageBtn->setImage(":/images/homePage/shouyexuan.png");
        ui->myPageBtn->setImage(":/images/homePage/wode.png");
        ui->sysPageBtn->setImage(":/images/homePage/admin.png");
    }else if(PageId==MyselfPage)
    {
        ui->homePageBtn->setImage(":/images/homePage/shouye.png");
        ui->myPageBtn->setImage(":/images/homePage/wodexuan.png");
        ui->sysPageBtn->setImage(":/images/homePage/admin.png");
    }else if(PageId==AdminPage)
    {
        ui->homePageBtn->setImage(":/images/homePage/shouye.png");
        ui->myPageBtn->setImage(":/images/homePage/wode.png");
        ui->sysPageBtn->setImage(":/images/homePage/adminxuan.png");
    }else
    {
        qDebug()<<"暂不支持的页面";
    }
}

void video_player::mousePressEvent(QMouseEvent *event)
{
    QPoint point=event->position().toPoint();

    if(ui->head->geometry().contains(point))
    {
        if(event->button()==Qt::LeftButton)
        {
            // dragPos=point-geometry().topLeft();
            // qDebug()<<event->button();
            dragPos=event->globalPosition().toPoint()-geometry().topLeft();
            return;
        }
        if(event->button()==Qt::RightButton)
        {
            // qDebug()<<event->button();
            move(geometry().topLeft()+QPoint(5,5));
        }
    }

    QWidget::mousePressEvent(event);
}

void video_player::mouseMoveEvent(QMouseEvent *event)
{
    QPoint point=event->position().toPoint();

    if(ui->head->geometry().contains(point))
    {

        if(event->buttons()==Qt::LeftButton)
        {
            // if(++movesize%100==0)
            // {
            //     qDebug()<<"MouseMoveSize"<<movesize;
            // }
            move(event->globalPosition().toPoint()-dragPos);
            return ;
        }
    }

    QWidget::mouseMoveEvent(event);
}

void video_player::initUI()
{
    //去除窗口边框
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    //设置窗口图标
    setWindowIcon(QIcon(":/images/homePage/logo.png"));

    //添加窗口阴影效果
    QGraphicsDropShadowEffect* dropShadow =new QGraphicsDropShadowEffect(this);
    dropShadow->setColor(Qt::black);
    dropShadow->setBlurRadius(5);
    dropShadow->setOffset(0,0);
    ui->player_back_ground->setGraphicsEffect(dropShadow);

    //设置页面切换按钮的文本和图片
    ui->homePageBtn->setTextColor("#000000");
    ui->homePageBtn->setImageAndText(":/images/homePage/shouyexuan.png","首页",HomePage);
    ui->myPageBtn->setTextColor("#999999");
    ui->myPageBtn->setImageAndText(":/images/homePage/wode.png","我的",MyselfPage);
    ui->sysPageBtn->setTextColor("#999999");
    ui->sysPageBtn->setImageAndText(":/images/homePage/admin.png","系统",AdminPage);

}

