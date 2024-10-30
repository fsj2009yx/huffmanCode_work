#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "huffmanTree.h"
#include "huffmanDecode.h"

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
    bool isFileWritten=huffman.writeToFile(outPutFileName,text);
    qint64 elapsed = timer.elapsed();//获取压缩的运行时间（单位为ms）
    if(isFileWritten){
        QMessageBox::information(nullptr,"Success","Written Successful",QMessageBox::Ok);
        ui->textEdit->clear();
        QString huffmanTime=QString::number(elapsed)+"ms";
        ui->huffmanTime->setText(huffmanTime);
    }else{
        QMessageBox::critical(nullptr,"Error","Failed to open file for writing.",QMessageBox::Ok);
    }
}

void MainWindow::on_encodeFileButton_clicked()
{
    QString fileName=QFileDialog::getOpenFileName(this,QStringLiteral("选择文件"),QString(),QStringLiteral("Text Files (*.txt)"));
    if(fileName.isEmpty()){
        qDebug()<<"Failed to find the file";
    }else{
        ifstream ifs;
        QString text;
        ifs.open(fileName.toStdString(), ios::in);
        if (!ifs.is_open())
        {
            qDebug() << "Failed to open the file.";
            return;
        }
        else
        {
            qDebug() << "File opened successfully.";
            string buf;
            while (getline(ifs, buf))
            {
                text += buf+"\n";
            }
            ifs.close();
            ui->textEdit->setPlainText(text);
        }
    }
}


void MainWindow::on_lz4Button_clicked()
{

}


void MainWindow::on_zipCodeButton_clicked()
{

}


void MainWindow::on_decodeFileButton_clicked()
{
    QString filePath=QFileDialog::getOpenFileName(this,QStringLiteral("选择文件"),QString(),QStringLiteral("Encoded Files (*.zzz *.zip)"));
    qDebug()<<filePath;
}

