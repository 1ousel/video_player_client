#ifndef PAGINATOR_H
#define PAGINATOR_H

#include <QWidget>
#include <QLineEdit>
#include "pagebutton.h"
class Paginator : public QWidget
{
    Q_OBJECT
public:
    explicit Paginator(int count,QWidget *parent = nullptr);
private:
    void setBtnStyle(QPushButton* btn);
    void initSignalSlot();
    // 跳转到page页
    void jumpToPage(int page);
    // page <= 5 的情况
    void jumpToPageCase1(int page);
    // page >= pageCount - 4 的情况
    void jumpToPageCase2(int page);
    // page 在 5 到 pageCount - 4 之间
    void jumpToPageCase3(int page);
private slots:
    void prevPage();
    void nextPage();
    void clickPageBtn();
signals:
    // 跳转到指定页数的信号
    void pageChanged(int page);
private:
    int pageCount = 7; // 总页数
        int currentPage = 1; // 当前页数
    const int pageSize = 20; // 每页显示的条目数
    // 上一页和下一页按钮
    QPushButton* prevPageBtn;
    QPushButton* nextPageBtn;
    // 页面切换按钮集
    QList<PageButton*> pages;
    // 跳转值指定页
    QLineEdit* pageEdit;
signals:
};

#endif // PAGINATOR_H
