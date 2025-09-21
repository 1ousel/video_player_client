#include "avatarbutton.h"

AvatarButton::AvatarButton(QWidget *parent)
    : QPushButton{parent}
{
    mask = new QLabel(this);
    mask->setObjectName("mask");
    mask->setGeometry(0, 0, 60, 60);
    mask->setStyleSheet("#mask{"
                        "color:#FFFFFF;"
                        "background-color:rgba(0, 0, 0, 0.5);"
                        "border-radius: 30px;}");
    mask->setText("修改头像");
    mask->hide();
    // 让 mask 透传鼠标事件. 点击 mask 也会落到 mask 背后的按钮上.
    mask->setAttribute(Qt::WA_TransparentForMouseEvents);
}

void AvatarButton::changeMode(bool showmask)
{
    this->showMask = showmask;

}

void AvatarButton::enterEvent(QEnterEvent *event)
{
    if (showMask) {
        mask->show();
    }
}

void AvatarButton::leaveEvent(QEvent *event)
{
    mask->hide();
}
