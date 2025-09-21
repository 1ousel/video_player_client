#ifndef MYSELFWIDGET_H
#define MYSELFWIDGET_H

#include <QWidget>

namespace Ui {
class MyselfWidget;
}

class MyselfWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyselfWidget(QWidget *parent = nullptr);
    ~MyselfWidget();

    // 上传视频按钮槽函数
    void uploadViewBtnClicked();

    // 点击上传头像按钮
    void uploadAvatarBtnClicked();

    void InitUi();
private slots:
    void on_settingBtn_clicked();

signals:
    // 切换到上传视频窗口
    void switchUploadVideoPage(int pageIndex);
    // ...
private:
    Ui::MyselfWidget *ui;
};

#endif // MYSELFWIDGET_H
