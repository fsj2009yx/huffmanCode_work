#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "huffmanTree.h"
#include "huffmanDecode.h"
#include "zlibzip.h"

uLong Size;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_huffmanCodeButton_clicked()
{
    string text=ui->textEdit->toPlainText().toStdString();
    HaffmanCode huffman(text);
    string outPutFileName="encoded.data.zzz";
    QElapsedTimer timer;
    timer.start();
    int huffmanSize=huffman.writeToFile(outPutFileName,text);
    qint64 elapsed = timer.elapsed();//获取压缩的运行时间（单位为ms）
    if(huffmanSize){
        QMessageBox::information(nullptr,"Success","Written Successful",QMessageBox::Ok);
        ui->textEdit->clear();
        QString huffmanTime=QString::number(elapsed)+"ms";
        ui->huffmanTime->setText(huffmanTime);
        ui->huffmanSize->setText(QString::number(huffmanSize)+"KB");
    }else{
        QMessageBox::critical(nullptr,"Error","Failed to open file for writing.",QMessageBox::Ok);
    }
}

void MainWindow::on_encodeFileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, QStringLiteral("选择文件"), QString(), QStringLiteral("Text Files (*.txt)"));
    if (fileName.isEmpty())
    {
        qDebug() << "Failed to find the file";
    }
    else
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Failed to open the file.";
            return;
        }
        else
        {
            qDebug() << "File opened successfully.";

            Size=file.size();//获取文件原始数据
            int sizeKB=static_cast<int>(qFloor(static_cast<double>(Size)/1024.0));//转为KB
            ui->originalSize->setText(QString::number(sizeKB)+"KB");

            QString text = file.readAll(); // 读取所有文本
            file.close();

            ui->textEdit->setPlainText(text);
        }
    }

}


void MainWindow::on_zipCodeButton_clicked()
{
    QString text=ui->textEdit->toPlainText();
    QString outputFile="zlibEncoded.zlib";
    zlibZip zs;//创建zlibzip对象
    QElapsedTimer timer;
    timer.start();
    int zlibSize=zs.compressFile(text,outputFile,Size);
    qint64 elapsed=timer.elapsed();
    if(zlibSize){
        QMessageBox::information(nullptr,"Success","Written Successful",QMessageBox::Ok);
        ui->textEdit->clear();
        QString zlibTime=QString::number(elapsed)+"ms";
        ui->zipTime->setText(zlibTime);
        ui->zlibSize->setText(QString::number(zlibSize)+"KB");
    }else{
        QMessageBox::critical(nullptr,"Error","Failed to open file for writing.",QMessageBox::Ok);
    }
}


void MainWindow::on_decodeFileButton_clicked()
{
    QString filePath=QFileDialog::getOpenFileName(this,QStringLiteral("选择文件"),QString(),QStringLiteral("Encoded Files (*.zzz *.zlib)"));
    qDebug()<<filePath;
    if(!filePath.isEmpty())
    {
        static QRegularExpression pattern(R"(\.(\w+)$)");
        QRegularExpressionMatch match = pattern.match(filePath);
        if (match.hasMatch())
        {
            QString fileUtils=match.captured(1); // 捕获组1是后缀名
            if(fileUtils=="zzz")
            {
                QMessageBox::StandardButton result=QMessageBox::question(this,"","识别到文件扩展名为.zzz，是否进行哈夫曼解码？",QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes);
                if(result==QMessageBox::Yes)
                {
                    string decodedText =decodeFromFile(filePath.toStdString());
                    ui->textEdit_2->setText(QString::fromStdString(decodedText));
                }
            }
            else if(fileUtils=="zlib")
            {
                QMessageBox::StandardButton result=QMessageBox::question(this,"","识别到文件扩展名为.zlib，是否进行zlib解压？",QMessageBox::Yes | QMessageBox::No,QMessageBox::Yes);
                if(result==QMessageBox::Yes)
                {
                    zlibZip zs;
                    QString decodedText=zs.decompressFile(filePath);
                    ui->textEdit_2->setText(decodedText);
                }
            }
            else
            {
                QMessageBox::critical(this,"Error","没有识别到有效文件",QMessageBox::Ok);
            }
        }
        else
        {
            QMessageBox::critical(this,"Error","没有识别到有效文件",QMessageBox::Ok);
        }
    }
}

