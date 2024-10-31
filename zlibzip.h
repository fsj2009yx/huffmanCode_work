#ifndef ZLIBZIP_H
#define ZLIBZIP_H

#include<QtZlib/zlib.h>
#include <QByteArray>
#include <QString>
#include <QFile>
#include <QDebug>
#include<QDataStream>
#include<QMainWindow>

/*
zlib 基于 DEFLATE 压缩算法。DEFLATE 是一种无损压缩算法，它结合了 LZ77（Lempel-Ziv 1977）算法和霍夫曼编码（Huffman coding）
*/

class zlibZip
{
public:
    zlibZip() = default;

    int compressFile(const QString &text,const QString &outputFilePath,uLong &originalSize);
    QString decompressFile(const QString &inputFilePath);
private:
    QByteArray compressData(const QByteArray &data);
    QByteArray decompressData(const QByteArray &compressedData,uLong& originalSize);
};

#endif // ZLIBZIP_H
