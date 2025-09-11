#ifndef BARRAGEEDIT_H
#define BARRAGEEDIT_H

#include <QLineEdit>
#include<QWidget>
#include<QPushButton>

class BarrageEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit BarrageEdit(QWidget *parent = nullptr);
private:
    QPushButton*sendBSBtn;
    void onsendBSBtn();
signals:
};

#endif // BARRAGEEDIT_H
