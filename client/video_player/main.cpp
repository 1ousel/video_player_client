#include "video_player.h"
#include "startuppage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //启动UI
    //StartupPage sup;
    //sup.StartTimer();
    //sup.exec();

    //主界面
    // BitPlayer实例通过getInstance获取
    video_player* bitPlayer =video_player::getInstance();
    bitPlayer->show();
    return a.exec();
}
