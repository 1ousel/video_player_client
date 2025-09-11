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

    // 点击上传头像按钮
    void uploadAvatarBtnClicked();

    void InitUi();
private slots:
    void on_settingBtn_clicked();

private:
    Ui::MyselfWidget *ui;
};

#endif // MYSELFWIDGET_H
