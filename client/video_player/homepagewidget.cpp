#include "homepagewidget.h"
#include "ui_homepagewidget.h"
#include "util.h"
#include "videobox.h"

HomePageWidget::HomePageWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HomePageWidget)
{
    ui->setupUi(this);

    initKindAndTag();

    initRefreshAndTopBtn();

    initVideos();
}

HomePageWidget::~HomePageWidget()
{
    delete ui;
}

void HomePageWidget::initKindAndTag()
{
    //分类
   kinds = {"历史", "美⻝", "游戏", "科技", "运动", "动物", "旅⾏", "电影"};

    //创建分类按钮
    QPushButton* kindBtn=buildSelectBtn(ui->classifys,"#3ECEFF","分类");
    ui->classifysLayout->addWidget(kindBtn);
    //具体的分类按钮
    for(auto&kind:kinds)
    {
        QPushButton*kindItemBtn=buildSelectBtn(ui->classifys,"#222222",kind);
        ui->classifysLayout->addWidget(kindItemBtn);

        //给分类按钮绑定槽函数
        connect(kindItemBtn,&QPushButton::clicked,this,[=](){
            onKindBtnClicked(kindItemBtn);
        });
    }
    ui->classifysLayout->setSpacing(8);
    //标签
    tags = {
        {"历史", {"中国史", "世界史", "历史⼈物", "艺术", "⽂化", "奇闻"}},
        {"美⻝", {"美⻝测评", "美⻝制作", "美⻝攻略", "美⻝记录", "探店", "⽔果", "海鲜"}},
        {"游戏", {"游戏攻略", "单机游戏", "电⼦竞技", "⼿机游戏", "⽹络游戏", "游戏赛事","桌游棋牌"}},
        {"科技", {"数码", "软件应⽤", "智能家居", "⼿机", "电脑", "⼈⼯智能", "基础设施"}},
        {"运动", {"篮球", "⾜球", "乒乓球", "⽻⽑球", "健⾝", "竞技体育", "运动装备"}},
        {"动物", {"喵星⼈", "汪星⼈", "宠物知识", "动物资讯", "野⽣动物", "动物世界", "萌宠"}},
        {"旅⾏", {"旅游攻略", "旅⾏Vlog", "⾃驾游", "交通", "环球旅⾏", "露营", "野外⽣存"}},
        {"电影", {"电影解说", "电影推荐", "电影剪辑", "搞笑", "吐槽", "悬疑", "经典"}}
    };
    resetTags(tags[kinds[0]]);
}

QPushButton* HomePageWidget::buildSelectBtn(QWidget *parent, const QString &color, const QString &text)
{
    QPushButton*btn =new QPushButton(text,parent);
    btn->setStyleSheet("color:"+color);
    btn->setMinimumHeight(26);
    //文本到按钮边界的距离
    btn->setFixedWidth(text.size()*16+18+18);
    return btn;
}

void HomePageWidget::resetTags(const QList<QString> &tags)
{
    QPushButton* tag=buildSelectBtn(ui->labels,"#3ECEFF","标签");
    ui->labelsLayout->addWidget(tag);

    //创建具体每个标签
    for(auto&tagText:tags)
    {
        QPushButton*tagItem=buildSelectBtn(ui->labels,"#666666",tagText);
        ui->labelsLayout->addWidget(tagItem);

        connect(tagItem,&QPushButton::clicked,this,[=](){
            onTagBtnClicked(tagItem);
        });
    }
    ui->labelsLayout->setSpacing(4);
}

void HomePageWidget::initRefreshAndTopBtn()
{
    QWidget* refreshandtopwidget=new QWidget(this);
    refreshandtopwidget->setFixedSize(42,94);
    refreshandtopwidget->setStyleSheet("QPushButton:hover{background-color:#666666}"
                                        "QPushButton{"
                                        "background-color : #DDDDDD;"
                                        "border-radius : 21px;"
                                        "border : none;}");
    QVBoxLayout* layout=new QVBoxLayout(refreshandtopwidget);

    //刷新按钮
    QPushButton* refreshBtn=new QPushButton(refreshandtopwidget);
    refreshBtn->setFixedSize(42,42);
    refreshBtn->setStyleSheet("border-image :url(:/images/homePage/shuaxin.png);");

    // 置顶按钮
    QPushButton* topBtn = new QPushButton(refreshandtopwidget);
    topBtn->setFixedSize(42, 42);
    topBtn->setStyleSheet("border-image : url(:/images/homePage/zhiding.png)");

    //添加到垂直布局器中
    layout->addWidget(refreshBtn);
    layout->addWidget(topBtn);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(10);

    refreshandtopwidget->move(1278,618);
    refreshandtopwidget->show();


    connect(refreshBtn, &QPushButton::clicked, this,&HomePageWidget::onRefreshBtnClicked);
    connect(topBtn, &QPushButton::clicked, this,&HomePageWidget::onTopBtnClicked);
}

void HomePageWidget::initVideos()
{
    for(int i=0;i<2;i++)
    {
        VideoBox*video=new VideoBox(this);


        ui->videoGLayout->addWidget(video,i/4,i%4);

    }
}

void HomePageWidget::onKindBtnClicked(QPushButton *clickedKindBtn)
{
    //设置被点击分类按钮高亮显示
    clickedKindBtn->setStyleSheet("background-color:#F1FDFF;"
                                  "color:#3ECEFF;");

    //清除之前点击过的分类按钮上的高亮显示
    //获取分类按钮
    QList<QPushButton*> kindBtns=ui->classifys->findChildren<QPushButton*>();
    for(auto kindBtn:kindBtns)
    {
        if(kindBtn!=clickedKindBtn)
        {
            kindBtn->setStyleSheet("color:#222222");
        }
    }
    //删除分类布局器的所有分类
    QList<QPushButton*>tagBtns=ui->labels->findChildren<QPushButton*>();
    for(auto tagBtn:tagBtns){
        ui->labelsLayout->removeWidget(tagBtn);
        delete tagBtn;
    }
    //重新添加当前点击分类标签的所有分类
    resetTags(tags[clickedKindBtn->text()]);
}

void HomePageWidget::onTagBtnClicked(QPushButton *clickedTagBtn)
{
    clickedTagBtn->setStyleSheet("background-color:#F1FDFF;"
                                "color:#3ECEFF");

    QList<QPushButton*>tagBtns=ui->labels->findChildren<QPushButton*>();
    for(auto tagBtn:tagBtns)
    {
        if(tagBtn!=clickedTagBtn)
        {
            tagBtn->setStyleSheet("color:#666666;");
        }
    }
}

void HomePageWidget::onRefreshBtnClicked()
{
    LOG()<<"刷新按钮点击";
}

void HomePageWidget::onTopBtnClicked()
{
    LOG()<<"置顶按钮点击";
}
