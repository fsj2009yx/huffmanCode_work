#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFileDialog>
#include<QMessageBox>
#include<QElapsedTimer>
#include <QRegularExpression>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_huffmanCodeButton_clicked();

    void on_encodeFileButton_clicked();

    void on_zipCodeButton_clicked();

    void on_decodeFileButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
