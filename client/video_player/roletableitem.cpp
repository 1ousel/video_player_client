#include "roletableitem.h"
#include "ui_roletableitem.h"
#include"edituserdialog.h"
RoleTableItem::RoleTableItem(QWidget *parent,int seqNumber)
    : QWidget(parent)
    , ui(new Ui::RoleTableItem)
{
    ui->setupUi(this);
    // 编辑按钮点击
    connect(ui->editBtn, &QPushButton::clicked, this,
            &RoleTableItem::onEditBtnClicked);

    // 更新界面UI
    updateUI(seqNumber);

}

RoleTableItem::~RoleTableItem()
{
    delete ui;
}

void RoleTableItem::updateUI(int seqNumber)
{
    ui->idLabel->setText(QString::number(seqNumber));
}

void RoleTableItem::onEditBtnClicked()
{
    EditUserDialog* editUserDlg = new EditUserDialog(nullptr, "编辑后台⽤⼾");
    editUserDlg->exec();
    delete editUserDlg;
}
