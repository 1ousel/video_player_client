#include "volume.h"
#include "ui_volume.h"

Volume::Volume(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Volume)
{
    ui->setupUi(this);

    ui->VolumeBox->installEventFilter(this);

    setWindowFlag(Qt::Popup);
}

Volume::~Volume()
{
    delete ui;
}

bool Volume::eventFilter(QObject *watched, QEvent *event)
{
    if(ui->VolumeBox == watched){
        // 鼠标按下事件
        if(event->type() == QEvent::MouseButtonPress){
            calcVolume();
        }else if(event->type() == QEvent::MouseButtonRelease){
            // 鼠标释放
            ;
        }else if(event->type() == QEvent::MouseMove){
            calcVolume();
        }
        return true;
    }
    return QObject::eventFilter(watched, event);
}

void Volume::calcVolume()
{
    // 获取鼠标点击时的 y 坐标, QCursor().pos()鼠标点击时的位置，该位置是基于屏幕的全局坐标
        int y = ui->VolumeBox->mapFromGlobal(QCursor().pos()).y();
    // 验证y的正确性，y的范围在[5, 150]之间
    y = y < 5? 5 : y;
    y = y > 150? 150 : y;
    // 更新outLine的高度
    ui->outLine->setGeometry(ui->outLine->x(), y, ui->outLine->width(), 150 - y);
    // 更新volumeBox的位置
        int volumeBtnY = ui->outLine->y() - ui->VolumeBtn->height()/2;
    // 为了防当outLine的y坐标为150时，按钮的一半显示不出来的问题
    if(volumeBtnY > 140){
        volumeBtnY = 140;
    }
    ui->VolumeBtn->move(ui->VolumeBtn->x(), volumeBtnY);

}
