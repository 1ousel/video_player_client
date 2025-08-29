#ifndef SEARCHLINEEDIT_H
#define SEARCHLINEEDIT_H

#include <QLineEdit>
#include<QWidget>
class searchlineedit : public QWidget
{
    Q_OBJECT
public:
    explicit searchlineedit(QWidget *parent = nullptr);

private slots:
    void onSearchBtnClicked();
signals:
};

#endif // SEARCHLINEEDIT_H
