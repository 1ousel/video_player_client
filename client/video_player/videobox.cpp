#include "videobox.h"
#include "ui_videobox.h"
#include "util.h"

VideoBox::VideoBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::VideoBox)
{
    ui->setupUi(this);

    playPage=new PlayerPage();
    ui->delVideoBtn->hide();

    ui->imageBox->installEventFilter(this);
    ui->videoTittle->installEventFilter(this);
}

VideoBox::~VideoBox()
{
    delete ui;
}

bool VideoBox::eventFilter(QObject *watched, QEvent *event)
{
    if(ui->imageBox==watched||ui->videoTittle==watched)
    {
        if(event->type()==QEvent::MouseButtonPress)
        {
            LOG()<<"用户点击了视频，打开播放窗口";
            onPlayBtnClicked();
            return true;
        }
    }

    return QObject::eventFilter(watched,event);
}

void VideoBox::onPlayBtnClicked()
{
    playPage->show();
}
