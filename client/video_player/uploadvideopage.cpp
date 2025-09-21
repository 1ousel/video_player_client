#include "uploadvideopage.h"
#include "ui_uploadvideopage.h"
#include"video_player.h"
#include"util.h"
#include <QFileDialog>

UploadVideoPage::UploadVideoPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UploadVideoPage)
{
    ui->setupUi(this);
    // 提交按钮

    ui->imageLabel->setAttribute(Qt::WA_TransparentForMouseEvents);

    connect(ui->commitBtn, &QPushButton::clicked, this,&UploadVideoPage::onCommitBtnClicked);
    // QLineEdit::textChanged信号槽绑定
    connect(ui->videoTitle, &QLineEdit::textChanged, this,
            &UploadVideoPage::onLineEditTextChanged);
    // QPlainTextEdit::textChanged信号槽绑定
    connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, this,
            &UploadVideoPage::onPlainEditTextChanged);
    //改变封面槽函数
    connect(ui->changeBtn, &QPushButton::clicked, this,
            &UploadVideoPage::onChangeBtnClicked);

}

UploadVideoPage::~UploadVideoPage()
{
    delete ui;
}

void UploadVideoPage::onCommitBtnClicked()
{
    // 视频上传成功，切换到我的页面
    emit switchMySelfPage(MyselfPage);
}

void UploadVideoPage::onLineEditTextChanged(const QString &text)
{
    // 获取已经输入的文本
    QString leftWord = ui->leftWord->text();
    int wordCount = text.size();
    // 从界面截取出能容纳的总字数: 9/80, 截取到的就是80
    int linePos = leftWord.indexOf('/');
    QString totalWords = leftWord.mid(linePos+1);
    // 如果字数不够上限，继续输入
    if(totalWords.toInt() - wordCount >= 0){
        ui->leftWord->setText(QString::number(wordCount) + "/" + totalWords);
    }else{
        // TODO: 确认下是否需要提示
        LOG()<<"超出文本上限";
    }
}

void UploadVideoPage::onPlainEditTextChanged()
{
    // 获取已经输入的文本
    QString text = ui->plainTextEdit->toPlainText();
    int wordCount = text.size();
    // 从界面截取出能容纳的总字数: 27/1000, 截取到的就是27
    QString leftWord = ui->briefLeftWord->text();
    int linePos = leftWord.indexOf('/');
    QString totalWords = leftWord.mid(linePos+1);
    // 如果字数不够上限，继续输入
    if(totalWords.toInt() - wordCount >= 0){
        ui->briefLeftWord->setText(QString::number(wordCount) + "/" +
                                   totalWords);
    }else{
        // TODO: 确认下是否需要提示
        ui->plainTextEdit->setPlainText(text.mid(0, totalWords.toInt()));
        // 设置滚动条一直处于底部
        // textCursor: 获取当前光标的位置
        // movePosition: 移动光标位置，QTextCursor::End移动到文本的末尾
        // QTextCursor::MoveAnchor表示移动光标时，光标的位置是固定的，
        // 不会创建一个选区（即不会选中文本）
        QTextCursor textCursor = ui->plainTextEdit->textCursor();
        textCursor.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
        ui->plainTextEdit->setTextCursor(textCursor);
    }
}


void UploadVideoPage::onChangeBtnClicked()
{
    // 如果上传多个封面，使用最新的封面
    QString coverImagePath = QFileDialog::getOpenFileName(nullptr, "选择视频封⾯图", "",
                                                        "Images (*.png *.xpm *.jpg)");
        if(!coverImagePath.isEmpty()){
        // 将获取到的视频封面图显示到界面
        QPixmap pixmap(coverImagePath);
        pixmap = pixmap.scaled(ui->imageLabel->size(), Qt::IgnoreAspectRatio,
                               Qt::SmoothTransformation);
        ui->imageLabel->setPixmap(pixmap);
        repaint();
    }
}

