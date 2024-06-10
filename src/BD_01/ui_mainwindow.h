/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *buttonExit;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *buttonEnter;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_4;
    QLabel *imgRegist;
    QPushButton *buttonRegist;
    QLineEdit *linePassword;
    QLabel *label;
    QLineEdit *lineLogin;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_3;
    QLabel *labelStatus;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_10;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(411, 460);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 255, 255)"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 3, 0, 1, 1);

        buttonExit = new QPushButton(centralwidget);
        buttonExit->setObjectName("buttonExit");
        buttonExit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 1px solid #005870;\n"
"     border-radius: 2px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #b8f0ff, stop: 1 #57d5f7);\n"
"\n"
"     min-width: 80px;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #005870, stop: 1 #00c8ff);\n"
" }"));

        gridLayout->addWidget(buttonExit, 8, 2, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 8, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 8, 3, 1, 1);

        buttonEnter = new QPushButton(centralwidget);
        buttonEnter->setObjectName("buttonEnter");
        buttonEnter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 1px solid #005870;\n"
"     border-radius: 2px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #b8f0ff, stop: 1 #57d5f7);\n"
"\n"
"     min-width: 80px;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #005870, stop: 1 #00c8ff);\n"
" }"));

        gridLayout->addWidget(buttonEnter, 5, 2, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 3, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 6, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 5, 3, 1, 1);

        imgRegist = new QLabel(centralwidget);
        imgRegist->setObjectName("imgRegist");
        imgRegist->setPixmap(QPixmap(QString::fromUtf8("C:/Users/user/Desktop/icons8-\320\262\321\205\320\276\320\264-\320\262-\321\201\320\270\321\201\321\202\320\265\320\274\321\203,-\320\262-\320\272\321\200\321\203\320\266\320\272\320\265,-\321\201\321\202\321\200\320\265\320\273\320\272\320\260-\320\262\320\277\321\200\320\260\320\262\320\276-100.png")));

        gridLayout->addWidget(imgRegist, 2, 2, 1, 1, Qt::AlignHCenter);

        buttonRegist = new QPushButton(centralwidget);
        buttonRegist->setObjectName("buttonRegist");
        buttonRegist->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 1px solid #005870;\n"
"     border-radius: 2px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #b8f0ff, stop: 1 #57d5f7);\n"
"\n"
"     min-width: 80px;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #005870, stop: 1 #00c8ff);\n"
" }"));

        gridLayout->addWidget(buttonRegist, 6, 2, 1, 1);

        linePassword = new QLineEdit(centralwidget);
        linePassword->setObjectName("linePassword");
        linePassword->setStyleSheet(QString::fromUtf8("border: 1px solid #005870;\n"
"     border-radius: 2px;\n"
"     padding: 1px;\n"
"     background: rgb(255, 255, 255);\n"
"     selection-background-color: rgb(0, 0, 255);"));
        linePassword->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(linePassword, 4, 2, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 1, 1, 3);

        lineLogin = new QLineEdit(centralwidget);
        lineLogin->setObjectName("lineLogin");
        lineLogin->setStyleSheet(QString::fromUtf8("border: 1px solid #005870;\n"
"     border-radius: 2px;\n"
"     padding: 1px;\n"
"     background: rgb(255, 255, 255);\n"
"     selection-background-color: rgb(0, 0, 255);"));

        gridLayout->addWidget(lineLogin, 3, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 6, 3, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 4, 1, 1, 1);

        labelStatus = new QLabel(centralwidget);
        labelStatus->setObjectName("labelStatus");

        gridLayout->addWidget(labelStatus, 7, 1, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 5, 1, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 3, 4, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 411, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        buttonExit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        buttonEnter->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"justify\">\320\233\320\276\320\263\320\270\320\275</p></body></html>", nullptr));
        imgRegist->setText(QString());
        buttonRegist->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:24pt; font-weight:700; color:#000000;\">\320\222\321\205\320\276\320\264 \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\321\203</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        labelStatus->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">\321\201\321\202\320\260\321\202\321\203\321\201 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\320\270</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
