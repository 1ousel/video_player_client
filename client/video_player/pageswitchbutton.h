#ifndef PAGESWITCHBUTTON_H
#define PAGESWITCHBUTTON_H

#include <QPushButton>
#include<QLabel>
class PageSwitchButton : public QPushButton
{
    Q_OBJECT
public:
    explicit PageSwitchButton(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event);
    void setImageAndText(const QString&imagePath,const QString&text,int pageid);
    void setTextColor(const QString&textColor);
    int getPageId();
    void setImage(const QString&imagePath);
private:
    QLabel*btnImage;
    QLabel*btnTittle;

    int pageId;
signals:
    void switchPage(int pageId);
};

#endif // PAGESWITCHBUTTON_H
