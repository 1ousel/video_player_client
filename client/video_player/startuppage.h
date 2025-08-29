#ifndef STARTUPPAGE_H
#define STARTUPPAGE_H

#include <QDialog>

class StartupPage : public QDialog
{
    Q_OBJECT
public:
    explicit StartupPage(QDialog *parent = nullptr);

    //开启定时器
    void StartTimer();
};

#endif // STARTUPPAGE_H
