#include "myselfwidget.h"
#include "ui_myselfwidget.h"
#include<QFileDialog>
#include"util.h"
#include"videobox.h"
#include"util.h"
#include<QPainter>
#include<QPainterPath>
#include<video_player.h>
#include<modifymyselfdialog.h>
MyselfWidget::MyselfWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyselfWidget)
{
    ui->setupUi(this);
    InitUi();
}

MyselfWidget::~MyselfWidget()
{
    delete ui;
}

void MyselfWidget::uploadViewBtnClicked()
{
    // 1. 弹出打开文件对话框，让用户选择要上传的视频文件
    QString videoFilePath = QFileDialog::getOpenFileName(nullptr, "上传视频",
                                                         "",
                                                         "Videos (*.mp4 *.rmvb *.avi *.mov)");
        if(!videoFilePath.isEmpty()){
        // 视频大小限制，上限为4G
        QFileInfo fileInfo(videoFilePath);
        int64_t fileSize = fileInfo.size();
        LOG()<<fileSize;
        if(fileSize > 4LL*1024*1024*1024){
            LOG()<<"视频⽂件必须⼩于4G";
            return;
        }
        emit switchUploadVideoPage(UploadPage);
    }
}

// 读写文件操作.
// 从指定文件中, 读取所有的二进制内容. 得到一个 QByteArray
static inline QByteArray loadFileToByteArray(const QString& path) {
    QFile file(path);
    bool ok = file.open(QFile::ReadOnly);
    if (!ok) {
        LOG() << "⽂件打开失败!";
        return QByteArray();
    }
    QByteArray content = file.readAll();
    file.close();
    return content;
}

static inline void writeByteArrayToFile(const QString& path, const QByteArray&content) {
    QFile file(path);
    bool ok = file.open(QFile::WriteOnly);
    if (!ok) {
        LOG() << "⽂件打开失败!";
        return;
    }
    file.write(content);
    file.flush();
    file.close();
}
// // 根据 QByteArray, 转成 QIcon
// static inline QIcon makeIcon(const QByteArray& byteArray) {
//     QPixmap pixmap;
//     pixmap.loadFromData(byteArray);
//     QIcon icon(pixmap);
//     return icon;
// }
static inline QIcon makeCircleIcon(const QByteArray& byteArray, int radius) {
//test use
#define scaledSize 1

    QPixmap pixmap;
    pixmap.loadFromData(byteArray);
    if (pixmap.isNull()) {
        return QIcon();
    }
    // 把 pixmap 缩放到指定的 2*radius 大小. IgnoreAspectRatio 忽略长宽比;
    // SmoothTransformation 平滑缩放, 获得更高的图片质量, 但是会牺牲一定速度.

    LOG() << "Original size:" << pixmap.size();
    pixmap = pixmap.scaled(scaledSize*2*radius, scaledSize*2*radius, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    LOG() << "Scaled size:" << pixmap.size();

    // 构造绘图设置，可以理解成画图的画布
    QPixmap output = QPixmap(pixmap.size());
    output.fill(Qt::transparent); // 设置透明背景
    QPainter painter(&output);
    painter.setRenderHint(QPainter::Antialiasing);
    // 创建圆形路径
    QPainterPath path;
    path.addEllipse(0, 0, scaledSize*2*radius, scaledSize*2*radius);
    // 设置裁剪路径，裁剪路径的作用是限制绘图操作的范围，只有在裁剪路径内的区域才会被裁剪
    painter.setClipPath(path);
    // 绘制圆形图径
    painter.drawPixmap(0, 0, pixmap);
    // 结束绘制：end()内部会释放与绘图设备相关的资源，确保绘图命令都能够被正确执行
    painter.end();
    LOG() << "output size:" << output.size();
    // QIcon icon(output);
    // // QIcon icon(pixmap);
    return QIcon(output);
}
void MyselfWidget::uploadAvatarBtnClicked()
{
    // 1. 弹出对话框, 选择文件
    QString fileName = QFileDialog::getOpenFileName(nullptr, "选择头像", "","Image Files (*.jpg *.png)");
        if (fileName.isEmpty()) {
        LOG() << "取消选择头像";
        return;
    }
    QByteArray fileData = loadFileToByteArray(fileName);
    if (fileData.isEmpty()) {
        LOG() << "头像⽂件读取失败";
        return;
    }
    ui->avatarBtn->setIcon(makeCircleIcon(fileData, ui->avatarBtn->width()/2));
    //就算在makeCircleIcon设置好了尺寸，此处也还要设置icon显示尺寸，因为无论尺寸是多少，默认16*16；
    ui->avatarBtn->setIconSize(QSize(ui->avatarBtn->width(), ui->avatarBtn->width()));
}

void MyselfWidget::InitUi()
{
    ui->attentionBtn->hide();

    // 头像按钮绑定槽函数
    connect(ui->avatarBtn, &AvatarButton::clicked, this,
            &MyselfWidget::uploadAvatarBtnClicked);
    //修改个人信息按钮槽函数
    connect(ui->settingBtn, &QPushButton::clicked, this,
            &MyselfWidget::on_settingBtn_clicked);
    connect(ui->uploadVideoBtn,&QPushButton::clicked,this,
           &MyselfWidget::uploadViewBtnClicked);
    //添加videoBox；
    for(int i=0;i<16;i++)
    {
        // VideoBox*video=new VideoBox();
        // ui->Layout->addWidget(video,i/4,i%4);
    }
}

void MyselfWidget::on_settingBtn_clicked()
{

    ModifyMyselfDialog* dialog = new ModifyMyselfDialog();
    dialog->exec();
    delete dialog;

}

