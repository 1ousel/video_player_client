#ifndef VIDEO_PLAYER_H
#define VIDEO_PLAYER_H

#include <QWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class video_player; }
QT_END_NAMESPACE

enum StackedWidgetPage{
    HomePage,MyselfPage,AdminPage
};

class video_player : public QWidget
{
    Q_OBJECT

public:
    video_player(QWidget *parent = nullptr);
    ~video_player();
private slots:
    void  onSwitchPage(int pageId);

private:

    //初始化UI函数
    void initUI();

    //绑定信号槽函数
    void connectSignalAndSlot();

    //重置页面切换按钮
    void resetswitchBtnInfo(int PageId);
    //鼠标点击事件
    void mousePressEvent(QMouseEvent *event);

    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);

    QPoint dragPos;
    // qlonglong movesize;
    // qlonglong presssize;
    Ui::video_player *ui;
};
#endif // VIDEO_PLAYER_H
