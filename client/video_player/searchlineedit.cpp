#include "searchlineedit.h"
#include<QLabel>
#include<QPushButton>
#include<QHBoxLayout>
#include "util.h"

searchlineedit::searchlineedit(QWidget *parent)
    : QWidget{parent}
{
    auto* searchEdit = new QLineEdit(this);
    searchEdit->setObjectName("search");
    searchEdit->setPlaceholderText("请搜索你感兴趣的视频");
    searchEdit->setFixedHeight(36);
    searchEdit->setTextMargins(33, 0, 0, 0);
    searchEdit->setStyleSheet("QLineEdit#search {"
                              "background-color: #FFFFFF;"
                              "border-radius: 18px;"
                              "border: 1px solid #3ECEFE;"
                              "font-family: 'Microsoft YaHei';"
                              "font-size: 14px;"
                              "color:#000000;"
                              "font-style: normal;}");

    QLabel* searchImg = new QLabel(this);
    searchImg->setFixedSize(16, 16);
    searchImg->setPixmap(QPixmap(":/images/homePage/sousuo.png"));

    QPushButton* searchBtn = new QPushButton("搜索", this);
    searchBtn->setFixedSize(62, 32);
    searchBtn->setStyleSheet("background-color: #3ECEFE;"
                             "border-radius: 16px;"
                             "font-family: 'Microsoft YaHei';"
                             "font-size: 14px;"
                             "color: #FFFFFF;"
                             "font-style: normal;");

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(searchImg);
    layout->addWidget(searchEdit);
    layout->addWidget(searchBtn);
    layout->setContentsMargins(11, 0, 2, 0);

    //绑定搜索按钮的槽函数
    connect(searchBtn,&QPushButton::clicked,this,&searchlineedit::onSearchBtnClicked);



    // QLabel* searchImg = new QLabel(this);
    // searchImg->setFixedSize(16, 16);
    // searchImg->setPixmap(QPixmap(":/images/homePage/sousuo.png"));
    // // 搜索框按钮
    // QPushButton* searchBtn = new QPushButton(this);
    // searchBtn->setText("搜索");
    // searchBtn->setFixedSize(62, 32);
    // searchBtn->setCursor(QCursor(Qt::ArrowCursor));
    // searchBtn->setStyleSheet("background-color : #3ECEFE;"
    //                          "border-radius : 16px;"
    //                          "font-family : 'Microsoft YaHei';"
    //                          "font-size : 14px;"
    //                          "color : #FFFFFF;"
    //                          "font-style : normal;");
    // this->setPlaceholderText("请搜索你感兴趣的视频");
    // this->setFixedWidth(320);
    // this->setFixedHeight(36);
    // setObjectName("search");
    // this->setStyleSheet("#search{background-color : #FFFFFF;"
    //                     "border-radius : 18px;"
    //                     "border : 1px solid #3ECEFE;"
    //                     "font-family : 'Microsoft YaHei';"
    //                     "font-size : 14px;"
    //                     "color:#000000;"
    //                     "font-style : normal;}");
    // this->setTextMargins(33, 0, 0, 0); // 左 上 右 下
    // QHBoxLayout* hLayout = new QHBoxLayout(this);
    // hLayout->addWidget(searchImg);
    // hLayout->addStretch();
    // hLayout->addWidget(searchBtn);
    // hLayout->setContentsMargins(11, 0, 2, 0); // 左 上 右 下


    // //LOG()<<"搜索框初始化";
    // setFixedSize(320,36);
    // setPlaceholderText("请搜索你感兴趣的视频");
    // setTextMargins(33,0,0,0);
    // setObjectName("search");

    // setStyleSheet("QLineEdit#search{"
    //               "background-color:#FFFFFF;"
    //               "border-radius:18px;"
    //               "border:1px solid #3ECEFE;"
    //               "font-family:微软雅黑;"
    //               "font-size:14px;"
    //               "font-style:normal;}");
    // //搜索图片
    // QLabel* searchImage=new QLabel(this);
    // searchImage->setFixedSize(16,16);
    // searchImage->setPixmap(QPixmap(":/image/homePage/sousuo.png"));


    // //搜索按钮
    // QPushButton*searchBtn=new QPushButton(this);
    // searchBtn->setText("搜索");
    // searchBtn->setFixedSize(62,32);
    // searchBtn->setStyleSheet("background-color : #3ECEFE;"
    //                          "border-radius : 16px;"
    //                          "font-family :微软雅黑;"
    //                          "font-size : 14px;"
    //                          "color : #FFFFFF;"
    //                          "font-style : normal;");
    // //将图片和按钮放到水平布局器中
    // QHBoxLayout*layout=new QHBoxLayout(this);
    // layout->addWidget(searchImage);
    // layout->addStretch();
    // layout->addWidget(searchBtn);
    // layout->setContentsMargins(11, 0, 2, 0);
}

void searchlineedit::onSearchBtnClicked()
{
    LOG()<<"搜索按钮点击，搜索视频";
}
