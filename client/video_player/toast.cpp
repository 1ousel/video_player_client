#include "toast.h"
#include <QApplication>
#include <QScreen>
#include <QVBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QThread>
#include"util.h"
// Toast::Toast(QWidget *parent)
//     : QDialog{parent}
// {}

Toast::Toast(const QString &text, QWidget *pWidget)
{
    initUI(text);
    // 2s 之后自动关闭.
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]() {
        timer->stop();
        this->close();
        this->deleteLater();
        if(pWidget){
            pWidget->show();
        }
    });
    timer->start(2000);
}

void Toast::initUI(const QString &text)
{
    // 1. 设置窗口的基本参数
    // 去掉窗口的标题栏
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    // 设置窗口背景透明
    this->setAttribute(Qt::WA_TranslucentBackground);
    setFixedSize(800, 60);
    // 2. QWidget: 实现背景+圆型
    // 布局管理器：让文本居中
    QWidget* qWidget = new QWidget(this);
    qWidget->setFixedSize(800, 60);
    qWidget->setStyleSheet("background-color : rgba(102, 102, 102, 0.5);"
                           "border-radius : 4px;");
    QVBoxLayout* layout = new QVBoxLayout(qWidget);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    qWidget->setLayout(layout);
    // 3. 创建显示文本的 Label
    QLabel* label = new QLabel();
    label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-family : 微软雅⿊;"
                         "font-size: 14px;"
                         "color : #000000;");
    label->setText(text);
    layout->addWidget(label);
    // 4. 设置窗口的位置：尽量在主屏幕的中间
    // 获取到整个屏幕的尺寸, 通过 primaryScreen 来获取.

    QScreen* screen = QApplication::primaryScreen();
    int width = screen->size().width();
    int height = screen->size().height();

    int x = (width - this->width()) / 2;
    int y = (height - this->height())/2 - 100; // 此处的 100 是窗口底边距离屏幕底边的间隔
        LOG()<<width<<" "<<height<<" "<<x<<" "<<y;
        this->move(x, y);
}
void Toast::showMessage(const QString &text, QWidget *pWidget){
    Toast* toast = new Toast(text, pWidget);
    toast->show();
}

Toast::Toast(const QString &text){
    initUI(text);
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]() {
        LOG()<<"time out";
        timer->stop();
        this->close();
        this->deleteLater();
    });
    timer->start(2000);
}
void Toast::showMessage(const QString &text){
    Toast* toast = new Toast(text);
    toast->show();
}
