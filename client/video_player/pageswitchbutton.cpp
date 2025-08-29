#include "pageswitchbutton.h"
#include<util.h>
PageSwitchButton::PageSwitchButton(QWidget *parent)
    : QPushButton{parent}
{
    //设置按钮大小
    setFixedSize(48,46);

    btnImage=new QLabel(this);
    btnImage->setGeometry((48-24)/2,0,24,24);

    btnTittle =new QLabel(this);
    btnTittle->setGeometry(0,30,48,16);
    btnTittle->setAlignment(Qt::AlignCenter);

    //去掉按钮边框
    setStyleSheet("border:none;");
}

void PageSwitchButton::mousePressEvent(QMouseEvent *event)
{
    (void*)event;
    LOG()<<"按钮"<<pageId<<"点击了";
    setTextColor("#000000");
    emit switchPage(pageId);

}

void PageSwitchButton::setImageAndText(const QString &imagePath, const QString &text,int pageid)
{
    btnImage->setPixmap(QPixmap(imagePath));
    btnTittle->setText(text);
    btnTittle->setStyleSheet("color: black; background-color: white;");
    //btnTittle->move((48-text.size()*12)/2,30);//文字居中
    pageId=pageid;
}

void PageSwitchButton::setTextColor(const QString &textColor)
{
    btnTittle->setStyleSheet("font-family:微软雅黑;"
                             "font-size:12px;"
                             "font-weight:bold;"
                             "color:"+textColor+";");
}

int PageSwitchButton::getPageId()
{
    return pageId;
}

void PageSwitchButton::setImage(const QString &imagePath)
{
    btnImage->setPixmap(QPixmap(imagePath));
}
