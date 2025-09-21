#include "roletable.h"
#include "ui_roletable.h"
#include"util.h"
#include<QRegularExpressionValidator>
#include"roletableitem.h"
#include"edituserdialog.h"


RoleTable::RoleTable(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RoleTable)
{
    ui->setupUi(this);

    // 初始化重置和查询按钮的样式
    initStyleSheet();
    // ...
    // 创建分页器并显示
    paginator = new Paginator(10, ui->paginatorArea);
    paginator->move(0, 20);
    paginator->show();
    // ...
    // ...
    // 点击新增按钮
    connect(ui->insertBtn, &QPushButton::clicked, this,&RoleTable::onInsertBtnClicked);

    connect(ui->resetBtn,&QPushButton::clicked,this,&RoleTable::onResetBtnClicked);

    connect(ui->queryBtn,&QPushButton::clicked,this,&RoleTable::onQueryBtnClicked);


    ui->userStatus->addItem("全部分类");
    ui->userStatus->addItem("启⽤");
    ui->userStatus->addItem("停⽤");
    ui->userStatus->setCurrentIndex(0);


    // 限制编辑框只能输手机机号
    QRegularExpression regExp("^1\\d{10}$");
    QValidator* validator = new QRegularExpressionValidator(regExp, this);
    ui->phone->setValidator(validator);
    // ...
    updateRoleTable();
}

void RoleTable::updateRoleTable()
{
    // 添加RoleTableItem到表中
    for (int i = 0; i < 2; i++) {
        RoleTableItem* item = new RoleTableItem(this, i+1);
        ui->layout->addWidget(item);
    }
}
RoleTable::~RoleTable()
{
    delete ui;
}



void RoleTable::onResetBtnClicked()
{
    // 设置按钮样式
    ui->resetBtn->setStyleSheet(styleSheet["选中"]);
    ui->queryBtn->setStyleSheet(styleSheet["未选中"]);
    ui->phone->setText("");
    ui->userStatus->setCurrentIndex(0);
    LOG()<<"重置按钮点击...";
}

void RoleTable::onQueryBtnClicked()
{
    // 设置按钮样式
    ui->queryBtn->setStyleSheet(styleSheet["选中"]);
    ui->resetBtn->setStyleSheet(styleSheet["未选中"]);
    LOG()<<"查询按钮点击...";
}

void RoleTable::onInsertBtnClicked()
{
    // 显示新增对后台用户对话框
    EditUserDialog* editUserDlg = new EditUserDialog(nullptr, "新增后台⽤⼾");
    editUserDlg->exec();
    delete editUserDlg;
}

void RoleTable::initStyleSheet()
{
    styleSheet.insert("选中", "background-color:#3ECEFF;"
                              "border-radius:4px;"
                              "font-family:微软雅⿊;"
                              "font-size:14px;"
                              "color:#FFFFFF;");
        styleSheet.insert("未选中", "background:#FFFFFF;"
                                    "border-radius:4px;"
                                    "border:1px solid #DCDEE0;"
                                    "font-family:微软雅⿊;"
                                    "font-size:14px;"
                                    "color:#222222;");
}
