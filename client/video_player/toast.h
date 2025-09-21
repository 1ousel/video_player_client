#ifndef TOAST_H
#define TOAST_H

#include <QWidget>
#include<QDialog>

class Toast : public QDialog
{
    Q_OBJECT
public:
    // 此处不需要指定父窗口. Toast一般是在整个桌面上显示的
    Toast(const QString& text, QWidget *pWidget);
    Toast(const QString& text);
    // 并不需要手动来 new 这个对象, 都是通过 showMessage 来弹出窗口
    static void showMessage(const QString& text);
    static void showMessage(const QString& text, QWidget *pWidget);
private:
    void initUI(const QString& text);
};

#endif // TOAST_H
