#include "zlibzip.h"

QByteArray zlibZip::compressData(const QByteArray &data)//编码
{
    uLongf compressedSize = compressBound(data.size());
    QByteArray compressedData(compressedSize, '\0');

    if (compress(reinterpret_cast<Bytef*>(compressedData.data()), &compressedSize,
                 reinterpret_cast<const Bytef*>(data.constData()), data.size()) != Z_OK) {
        qDebug() << "Compression failed.";
        return QByteArray(); // 压缩失败，返回空字节数组
    }

    compressedData.resize(compressedSize); // 调整压缩数据大小
    return compressedData;
}

QByteArray zlibZip::decompressData(const QByteArray &compressedData,uLong &originalSize)//解码
{
    QByteArray decompressedData(originalSize, '\0');
    if (uncompress(reinterpret_cast<Bytef*>(decompressedData.data()), &originalSize,
                   reinterpret_cast<const Bytef*>(compressedData.constData()), compressedData.size()) != Z_OK) {
        qDebug() << "Decompression failed.";
        return QByteArray(); // 解压失败，返回空字节数组
    }
    return decompressedData;
}

int zlibZip::compressFile(const QString &text,const QString &outputFilePath,uLong &originalSize)//压缩文件
{
    QByteArray inputData = text.toUtf8();//QString转QByteArray

    QByteArray compressedData = compressData(inputData);
    if (compressedData.isEmpty()) {
        return -1; // 压缩失败
    }

    QFile outputFile(outputFilePath);
    if (!outputFile.open(QIODevice::WriteOnly)) {
        qDebug() << "Failed to open output file.";
        return -1;
    }

    QDataStream out(&outputFile);
    out.setByteOrder(QDataStream::LittleEndian);//设置小端序
    out<<static_cast<quint64>(originalSize);
    out.writeRawData(compressedData.data(),compressedData.size());

    uLong Size=outputFile.size();
    int sizeKB=static_cast<int>(qFloor(static_cast<double>(Size)/1024.0));//转为KB
    outputFile.close();

    return sizeKB;
}

QString zlibZip::decompressFile(const QString &inputFilePath)//解压缩文件
{
    QFile inputFile(inputFilePath);//.zlib文件路径
    if (!inputFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open input file.";
        return QString();
    }

    QDataStream in(&inputFile);
    in.setByteOrder(QDataStream::LittleEndian);

    quint64 size;
    in>>size;
    uLong originalSize=static_cast<uLong>(size);

    QByteArray compressedData=inputFile.readAll();
    inputFile.close();

    QString decompressedString = QString::fromUtf8(decompressData(compressedData,originalSize));

    return decompressedString;
}
