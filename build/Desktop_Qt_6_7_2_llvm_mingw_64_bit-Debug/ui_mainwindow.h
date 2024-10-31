/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *originalSize;
    QLabel *huffmanTime;
    QLabel *zipTime;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_1;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QLabel *huffmanSize;
    QLabel *zlibSize;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *encodeFileButton;
    QTextEdit *textEdit;
    QVBoxLayout *_2;
    QPushButton *zipCodeButton;
    QPushButton *huffmanCodeButton;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QPushButton *decodeFileButton;
    QTextEdit *textEdit_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(582, 511);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setObjectName("gridLayout_4");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        originalSize = new QLabel(tab_3);
        originalSize->setObjectName("originalSize");

        verticalLayout_4->addWidget(originalSize);

        huffmanTime = new QLabel(tab_3);
        huffmanTime->setObjectName("huffmanTime");

        verticalLayout_4->addWidget(huffmanTime);

        zipTime = new QLabel(tab_3);
        zipTime->setObjectName("zipTime");

        verticalLayout_4->addWidget(zipTime);


        gridLayout_4->addLayout(verticalLayout_4, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(tab_3);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label);

        label_1 = new QLabel(tab_3);
        label_1->setObjectName("label_1");
        label_1->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_1);

        label_2 = new QLabel(tab_3);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout->addWidget(label_2);


        gridLayout_4->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_5 = new QLabel(tab_3);
        label_5->setObjectName("label_5");

        verticalLayout_2->addWidget(label_5);

        huffmanSize = new QLabel(tab_3);
        huffmanSize->setObjectName("huffmanSize");

        verticalLayout_2->addWidget(huffmanSize);

        zlibSize = new QLabel(tab_3);
        zlibSize->setObjectName("zlibSize");

        verticalLayout_2->addWidget(zlibSize);


        gridLayout_4->addLayout(verticalLayout_2, 0, 2, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        encodeFileButton = new QPushButton(tab);
        encodeFileButton->setObjectName("encodeFileButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(encodeFileButton->sizePolicy().hasHeightForWidth());
        encodeFileButton->setSizePolicy(sizePolicy);
        encodeFileButton->setMinimumSize(QSize(111, 41));

        horizontalLayout->addWidget(encodeFileButton);

        textEdit = new QTextEdit(tab);
        textEdit->setObjectName("textEdit");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
        textEdit->setMinimumSize(QSize(300, 400));

        horizontalLayout->addWidget(textEdit);

        _2 = new QVBoxLayout();
        _2->setObjectName("_2");
        _2->setContentsMargins(5, -1, -1, -1);
        zipCodeButton = new QPushButton(tab);
        zipCodeButton->setObjectName("zipCodeButton");
        sizePolicy.setHeightForWidth(zipCodeButton->sizePolicy().hasHeightForWidth());
        zipCodeButton->setSizePolicy(sizePolicy);
        zipCodeButton->setMinimumSize(QSize(111, 41));

        _2->addWidget(zipCodeButton);

        huffmanCodeButton = new QPushButton(tab);
        huffmanCodeButton->setObjectName("huffmanCodeButton");
        sizePolicy.setHeightForWidth(huffmanCodeButton->sizePolicy().hasHeightForWidth());
        huffmanCodeButton->setSizePolicy(sizePolicy);
        huffmanCodeButton->setMinimumSize(QSize(111, 41));

        _2->addWidget(huffmanCodeButton);


        horizontalLayout->addLayout(_2);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setObjectName("gridLayout_3");
        decodeFileButton = new QPushButton(tab_2);
        decodeFileButton->setObjectName("decodeFileButton");
        sizePolicy.setHeightForWidth(decodeFileButton->sizePolicy().hasHeightForWidth());
        decodeFileButton->setSizePolicy(sizePolicy);
        decodeFileButton->setMinimumSize(QSize(111, 41));

        gridLayout_3->addWidget(decodeFileButton, 0, 0, 1, 1);

        textEdit_2 = new QTextEdit(tab_2);
        textEdit_2->setObjectName("textEdit_2");

        gridLayout_3->addWidget(textEdit_2, 0, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 582, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        originalSize->setText(QCoreApplication::translate("MainWindow", "0KB", nullptr));
        huffmanTime->setText(QCoreApplication::translate("MainWindow", "0ms", nullptr));
        zipTime->setText(QCoreApplication::translate("MainWindow", "0ms", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\216\237\345\247\213\346\226\207\344\273\266\345\244\247\345\260\217\357\274\232", nullptr));
        label_1->setText(QCoreApplication::translate("MainWindow", "\345\223\210\345\244\253\346\233\274\347\274\226\347\240\201\350\200\227\346\227\266/\345\244\247\345\260\217\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "zilb\345\216\213\347\274\251\350\200\227\346\227\266/\345\244\247\345\260\217\357\274\232", nullptr));
        label_5->setText(QString());
        huffmanSize->setText(QCoreApplication::translate("MainWindow", "0KB", nullptr));
        zlibSize->setText(QCoreApplication::translate("MainWindow", "0KB", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\350\200\227\346\227\266\345\210\206\346\236\220", nullptr));
        encodeFileButton->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266\357\274\210.txt\357\274\211", nullptr));
        zipCodeButton->setText(QCoreApplication::translate("MainWindow", "zlib\345\216\213\347\274\251", nullptr));
        huffmanCodeButton->setText(QCoreApplication::translate("MainWindow", "\345\223\210\345\244\253\346\233\274\347\274\226\347\240\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\347\274\226\347\240\201", nullptr));
        decodeFileButton->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\350\247\243\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
