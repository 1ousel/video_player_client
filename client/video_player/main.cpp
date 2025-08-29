#include "video_player.h"
#include "startuppage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //启动UI
    StartupPage sup;
    sup.StartTimer();
    sup.exec();

    //主界面
    video_player w;
    w.show();
    return a.exec();
}
