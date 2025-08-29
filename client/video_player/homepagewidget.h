#ifndef HOMEPAGEWIDGET_H
#define HOMEPAGEWIDGET_H

#include <QWidget>
#include <QPushButton>
namespace Ui {
class HomePageWidget;
}

class HomePageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HomePageWidget(QWidget *parent = nullptr);
    ~HomePageWidget();

private:
    void initKindAndTag();
    QPushButton* buildSelectBtn(QWidget* parent,const QString&color,const QString&text);
    void resetTags(const QList<QString>&tags);

    void initRefreshAndTopBtn();

    void initVideos();
private slots:
    //分类按钮点击
    void onKindBtnClicked(QPushButton*clickedKindBtn);

    //标签按钮点击
    void onTagBtnClicked(QPushButton*clickedTagBtn);

    //刷新按钮槽函数
    void onRefreshBtnClicked();

    //顶部按钮槽函数
    void onTopBtnClicked();
private:
    Ui::HomePageWidget *ui;
    QHash<QString, QList<QString>> tags;
    QList<QString> kinds;
};

#endif // HOMEPAGEWIDGET_H
