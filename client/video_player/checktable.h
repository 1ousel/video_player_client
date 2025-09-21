#ifndef CHECKTABLE_H
#define CHECKTABLE_H

#include <QWidget>
#include"paginator.h"
namespace Ui {
class CheckTable;
}

class CheckTable : public QWidget
{
    Q_OBJECT

    // 更新审核页面table
    void updateCheckTable();
    // 重置按钮点击槽函数
    void onResetBtnClicked();
    // 查询按钮点击槽函数
    void onQueryBtnClicked();
    // ...
public:
    explicit CheckTable(QWidget *parent = nullptr);
    ~CheckTable();

private:
    Paginator* paginator=nullptr;
    Ui::CheckTable *ui;
};

#endif // CHECKTABLE_H
