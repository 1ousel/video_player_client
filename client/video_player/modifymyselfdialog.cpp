#include "modifymyselfdialog.h"
#include "ui_modifymyselfdialog.h"
#include"util.h"
#include"newpassworddialog.h"
ModifyMyselfDialog::ModifyMyselfDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ModifyMyselfDialog)
{
    ui->setupUi(this);
    setWindowFlag(Qt::FramelessWindowHint);
    ui->passwordWidget->hide();
    connect(ui->submitBtn, &QPushButton::clicked, this,
            &ModifyMyselfDialog::onSubmitBtnClicked);
    connect(ui->cancelBtn, &QPushButton::clicked, this,
            &ModifyMyselfDialog::onCancelBtnClicked);
    connect(ui->passwordBtn, &QPushButton::clicked, this,
            &ModifyMyselfDialog::showPasswordDlg);
    connect(ui->changePasswordBtn, &QPushButton::clicked, this,
            &ModifyMyselfDialog::showPasswordDlg);
}

ModifyMyselfDialog::~ModifyMyselfDialog()
{
    delete ui;
}

void ModifyMyselfDialog::onSubmitBtnClicked()
{
    LOG()<<"提交";
}

void ModifyMyselfDialog::onCancelBtnClicked()
{
    LOG()<<"关闭修改窗口";
    close();
}

void ModifyMyselfDialog::showPasswordDlg()
{
    LOG()<<"show password dlg";
}

void ModifyMyselfDialog::showPasswordWidget()
{
    // 显示再次修改密码对话框, 用主窗口作为对话框的父窗口.
    NewPasswordDialog* dialog = new NewPasswordDialog();
    dialog->exec();
    // 获取修改后密码
    // 引一个个临时变量 currentPassword, 为了解决这样的问题:
    // 1. 用户点击修改密码, 弹出修改密码对话框, 输入密码, 确定.
    // 2. 用户再次点击修改密码, 弹出修改密码对话框, 输入密码, 取消.
    // 如果是直接把从修改密码对话框读出的密码设置到 newPassword,
    // 那么随着第二次次的取消动作, 就会使第一次修改的值也被取消掉了.
    QString currentPassword = dialog->getNewPassword();
    if (currentPassword.isEmpty()) {
        LOG() << "取消修改密码";
        return;
    }
    LOG() << "新密码已设置: " << currentPassword;
    // 隐藏修改密码按钮, 显示已修改
    ui->passwordBtn->hide();
    ui->passwordWidget->show();
    // 释放对话框
    delete dialog;
}
