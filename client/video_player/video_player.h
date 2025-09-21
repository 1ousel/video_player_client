#ifndef VIDEO_PLAYER_H
#define VIDEO_PLAYER_H

#include <QWidget>
#include"uploadvideopage.h"
QT_BEGIN_NAMESPACE
namespace Ui { class video_player; }
QT_END_NAMESPACE

enum StackedWidgetPage{
    HomePage,MyselfPage,AdminPage,UploadPage
};

class video_player : public QWidget
{
    Q_OBJECT

public:

    ~video_player();
    static video_player* getInstance();
private slots:
    void  onSwitchPage(int pageId);
private:
    video_player(QWidget *parent = nullptr);
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

    //添加单项实例
    static video_player* instance;
    Ui::video_player *ui;
};





#endif // VIDEO_PLAYER_H
