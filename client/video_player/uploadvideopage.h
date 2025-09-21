#ifndef UPLOADVIDEOPAGE_H
#define UPLOADVIDEOPAGE_H


#include <QWidget>

namespace Ui {
class UploadVideoPage;
}

class UploadVideoPage : public QWidget
{
    Q_OBJECT

public:
    explicit UploadVideoPage(QWidget *parent = nullptr);
    ~UploadVideoPage();
    // 提交按钮槽函数
    void onCommitBtnClicked();
    // 标题QLineEdit::textChanged信号对应槽函数
    void onLineEditTextChanged(const QString& text);
    // 简介QPlainTextEdit::textChanged信号对应槽函数
    void onPlainEditTextChanged();
    //改变封面槽函数
    void onChangeBtnClicked();
signals:
    // 切换到我的页面信号
    void switchMySelfPage(int pageIndex);

private:
    Ui::UploadVideoPage *ui;
};

#endif // UPLOADVIDEOPAGE_H
