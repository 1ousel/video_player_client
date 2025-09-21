#ifndef ROLETABLEITEM_H
#define ROLETABLEITEM_H

#include <QWidget>

namespace Ui {
class RoleTableItem;
}

class RoleTableItem : public QWidget
{
    Q_OBJECT

public:
    // 添加int参数
    explicit RoleTableItem(QWidget *parent = nullptr, int seqNumber = 1);
    ~RoleTableItem();
    // 更新界面元素
    void updateUI(int seqNumber);
    // 编辑按钮点击
    void onEditBtnClicked();


private:
    Ui::RoleTableItem *ui;
};

#endif // ROLETABLEITEM_H
