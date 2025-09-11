#ifndef PLAYERPAGE_H
#define PLAYERPAGE_H

#include <QWidget>
#include<QPoint>
#include<QMouseEvent>
#include"Volume.h"
#include"PlaySpeed.h"
namespace Ui {
class PlayerPage;
}

class PlayerPage : public QWidget
{
    Q_OBJECT

public:
    explicit PlayerPage(QWidget *parent = nullptr);
    ~PlayerPage();
private:
    Ui::PlayerPage *ui;
    void mousePressEvent(QMouseEvent *event);

    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);

    void onVolumeBtnClicked();

    void onSpeedBtnClicked();

    void moveVolumeWindows(const QPoint& point);

    void movePlaySpeedWindows(const QPoint& point);
    QPoint dragPos;
    Volume* volume;
    PlaySpeed* playSpeed;
};

#endif // PLAYERPAGE_H
