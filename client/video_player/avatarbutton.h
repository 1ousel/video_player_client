#ifndef AVATARBUTTON_H
#define AVATARBUTTON_H

#include <QWidget>
#include<QPushButton>
#include<QLabel>
class AvatarButton : public QPushButton
{
    Q_OBJECT
public:
    explicit AvatarButton(QWidget *parent = nullptr);
    void changeMode(bool showmask);
    void enterEvent(QEnterEvent*event) override;
    void leaveEvent(QEvent*event) override;
    QLabel*mask;
    bool showMask;
};

#endif // AVATARBUTTON_H
