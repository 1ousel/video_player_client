#ifndef VOLUME_H
#define VOLUME_H

#include <QWidget>
#include <QPoint>
namespace Ui {
class Volume;
}

class Volume : public QWidget
{
    Q_OBJECT

public:
    explicit Volume(QWidget *parent = nullptr);
    ~Volume();
    // 拦截鼠标按下、移动、释放事件
    bool eventFilter(QObject *watched, QEvent *event);
    // 更新圆球按钮位置 以及 outLine的尺寸并更新
    void calcVolume();
private:
    Ui::Volume *ui;
};

#endif // VOLUME_H
