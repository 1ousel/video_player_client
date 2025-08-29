#ifndef UTIL_H
#define UTIL_H


#include<QString>
#include<QFileInfo>
#include<QDebug>
static inline QString getFileName(const QString&filePath){
    QFileInfo fileinfo(filePath);
    return fileinfo.fileName();
}

#define TAG QString("[%1:%2]").arg(getFileName(__FILE__),QString::number(__LINE__))

//默认情况下qDebug输出字符串时会自动为字符串加上“”，有时可能干扰调试
//noquete调用后不会自动为字符串加引号
#define LOG() qDebug().noquote()<<TAG

#endif // UTIL_H
