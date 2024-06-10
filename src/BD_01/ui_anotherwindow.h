/********************************************************************************
** Form generated from reading UI file 'anotherwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANOTHERWINDOW_H
#define UI_ANOTHERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnotherWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_9;
    QLabel *labelName;
    QLabel *label_11;
    QLabel *labelRoll;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_5;
    QPushButton *fullGuild_2;
    QPushButton *fullInfo_2;
    QPushButton *fullExit_2;
    QSpacerItem *verticalSpacer_6;
    QPushButton *AdminButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *addPartGOST;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_13;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *upPart;
    QTableView *tableViewAudit;
    QLabel *S;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *delPart;
    QTableView *tableViewBuilds;
    QPushButton *delAudit;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_2;
    QTableView *tableViewGOST;
    QLineEdit *lineEditGOST;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *redParts;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *delParts;
    QPushButton *redBuilds;
    QPushButton *addPartLocal;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *redPArt;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *upBuilds;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *verticalSpacer_2;
    QPushButton *upAudit;
    QPushButton *addPart;
    QLabel *label;
    QPushButton *upParts;
    QPushButton *delBuilds;
    QLabel *label_6;
    QPushButton *addBuilds;
    QSpacerItem *horizontalSpacer_3;
    QTableView *tableViewParts;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AnotherWindow)
    {
        if (AnotherWindow->objectName().isEmpty())
            AnotherWindow->setObjectName("AnotherWindow");
        AnotherWindow->resize(1172, 581);
        AnotherWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 255, 255)"));
        centralwidget = new QWidget(AnotherWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        label_9 = new QLabel(frame);
        label_9->setObjectName("label_9");

        verticalLayout_2->addWidget(label_9);

        labelName = new QLabel(frame);
        labelName->setObjectName("labelName");

        verticalLayout_2->addWidget(labelName);

        label_11 = new QLabel(frame);
        label_11->setObjectName("label_11");

        verticalLayout_2->addWidget(label_11);

        labelRoll = new QLabel(frame);
        labelRoll->setObjectName("labelRoll");

        verticalLayout_2->addWidget(labelRoll);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");

        verticalLayout_2->addLayout(gridLayout_3);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        fullGuild_2 = new QPushButton(frame);
        fullGuild_2->setObjectName("fullGuild_2");
        fullGuild_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayout_2->addWidget(fullGuild_2);

        fullInfo_2 = new QPushButton(frame);
        fullInfo_2->setObjectName("fullInfo_2");
        fullInfo_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayout_2->addWidget(fullInfo_2);

        fullExit_2 = new QPushButton(frame);
        fullExit_2->setObjectName("fullExit_2");
        fullExit_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayout_2->addWidget(fullExit_2);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);

        AdminButton = new QPushButton(frame);
        AdminButton->setObjectName("AdminButton");
        AdminButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayout_2->addWidget(AdminButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout->addWidget(frame, 0, 7, 5, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_14, 6, 8, 1, 6);

        addPartGOST = new QPushButton(centralwidget);
        addPartGOST->setObjectName("addPartGOST");
        addPartGOST->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(addPartGOST, 6, 5, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 0, 0, 1, 7);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_13, 6, 6, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 3, 0, 1, 7);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_15, 5, 4, 1, 1);

        upPart = new QPushButton(centralwidget);
        upPart->setObjectName("upPart");
        upPart->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(upPart, 2, 12, 1, 1);

        tableViewAudit = new QTableView(centralwidget);
        tableViewAudit->setObjectName("tableViewAudit");
        tableViewAudit->setStyleSheet(QString::fromUtf8("QTableView {\n"
"	border: 2px solid #005870;\n"
"     border-radius: 2px;\n"
"     background-color: white;\n"
"     selection-background-color: rgb(0, 85, 255);\n"
" }\n"
"QTableView QTableCornerButton::section {\n"
"     background: #0040ff;\n"
"     border: 2px outset #0004ff;\n"
" }"));

        gridLayout->addWidget(tableViewAudit, 4, 8, 1, 6);

        S = new QLabel(centralwidget);
        S->setObjectName("S");

        gridLayout->addWidget(S, 8, 7, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(339, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 8, 8, 1, 6);

        delPart = new QPushButton(centralwidget);
        delPart->setObjectName("delPart");
        delPart->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(delPart, 2, 11, 1, 1);

        tableViewBuilds = new QTableView(centralwidget);
        tableViewBuilds->setObjectName("tableViewBuilds");
        tableViewBuilds->setStyleSheet(QString::fromUtf8("QTableView {\n"
"	border: 2px solid #005870;\n"
"     border-radius: 2px;\n"
"     background-color: white;\n"
"     selection-background-color: rgb(0, 85, 255);\n"
" }\n"
"QTableView QTableCornerButton::section {\n"
"     background: #0040ff;\n"
"     border: 2px outset #0004ff;\n"
" }"));

        gridLayout->addWidget(tableViewBuilds, 1, 0, 1, 7);

        delAudit = new QPushButton(centralwidget);
        delAudit->setObjectName("delAudit");
        delAudit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 1px solid #005870;\n"
"     border-radius: 2px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #b8f0ff, stop: 1 #57d5f7);\n"
"\n"
"     min-width: 100px;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #005870, stop: 1 #00c8ff);\n"
" }"));

        gridLayout->addWidget(delAudit, 5, 9, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(77, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 5, 8, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 8, 1, 6);

        tableViewGOST = new QTableView(centralwidget);
        tableViewGOST->setObjectName("tableViewGOST");
        tableViewGOST->setStyleSheet(QString::fromUtf8("QTableView {\n"
"	border: 2px solid #005870;\n"
"     border-radius: 2px;\n"
"     background-color: white;\n"
"     selection-background-color: rgb(0, 85, 255);\n"
" }\n"
"QTableView QTableCornerButton::section {\n"
"     background: #0040ff;\n"
"     border: 2px outset #0004ff;\n"
" }"));

        gridLayout->addWidget(tableViewGOST, 1, 8, 1, 6);

        lineEditGOST = new QLineEdit(centralwidget);
        lineEditGOST->setObjectName("lineEditGOST");
        lineEditGOST->setStyleSheet(QString::fromUtf8("border: 1px solid #005870;\n"
"     border-radius: 2px;\n"
"     padding: 1px;\n"
"     background: rgb(255, 255, 255);\n"
"     selection-background-color: rgb(0, 0, 255);"));

        gridLayout->addWidget(lineEditGOST, 6, 4, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(77, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 2, 8, 1, 1);

        redParts = new QPushButton(centralwidget);
        redParts->setObjectName("redParts");
        redParts->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(redParts, 5, 3, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(74, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 2, 13, 1, 1);

        delParts = new QPushButton(centralwidget);
        delParts->setObjectName("delParts");
        delParts->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(delParts, 5, 1, 1, 1);

        redBuilds = new QPushButton(centralwidget);
        redBuilds->setObjectName("redBuilds");
        redBuilds->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(redBuilds, 2, 2, 1, 2);

        addPartLocal = new QPushButton(centralwidget);
        addPartLocal->setObjectName("addPartLocal");
        addPartLocal->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(addPartLocal, 6, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(501, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 8, 0, 1, 7);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 5, 10, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 6, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 5, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(78, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 5, 6, 1, 1);

        redPArt = new QPushButton(centralwidget);
        redPArt->setObjectName("redPArt");
        redPArt->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(redPArt, 2, 10, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(74, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 5, 12, 1, 2);

        upBuilds = new QPushButton(centralwidget);
        upBuilds->setObjectName("upBuilds");
        upBuilds->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(upBuilds, 2, 5, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_12, 5, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 5, 7, 2, 1);

        upAudit = new QPushButton(centralwidget);
        upAudit->setObjectName("upAudit");
        upAudit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(upAudit, 5, 11, 1, 1);

        addPart = new QPushButton(centralwidget);
        addPart->setObjectName("addPart");
        addPart->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(addPart, 2, 9, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 3, 8, 1, 6);

        upParts = new QPushButton(centralwidget);
        upParts->setObjectName("upParts");
        upParts->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(upParts, 5, 5, 1, 1);

        delBuilds = new QPushButton(centralwidget);
        delBuilds->setObjectName("delBuilds");
        delBuilds->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(delBuilds, 2, 4, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 6, 2, 1, 2);

        addBuilds = new QPushButton(centralwidget);
        addBuilds->setObjectName("addBuilds");
        addBuilds->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(addBuilds, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(90, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 0, 1, 1);

        tableViewParts = new QTableView(centralwidget);
        tableViewParts->setObjectName("tableViewParts");
        tableViewParts->setStyleSheet(QString::fromUtf8("QTableView {\n"
"	border: 2px solid #005870;\n"
"     border-radius: 2px;\n"
"     background-color: white;\n"
"     selection-background-color: rgb(0, 85, 255);\n"
" }\n"
"QTableView QTableCornerButton::section {\n"
"     background: #0040ff;\n"
"     border: 2px outset #0004ff;\n"
" }"));

        gridLayout->addWidget(tableViewParts, 4, 0, 1, 7);

        AnotherWindow->setCentralWidget(centralwidget);
        frame->raise();
        label_4->raise();
        label_2->raise();
        tableViewBuilds->raise();
        tableViewGOST->raise();
        addBuilds->raise();
        redBuilds->raise();
        upBuilds->raise();
        addPart->raise();
        redPArt->raise();
        delPart->raise();
        upPart->raise();
        label_3->raise();
        label->raise();
        tableViewParts->raise();
        tableViewAudit->raise();
        upParts->raise();
        delAudit->raise();
        S->raise();
        delBuilds->raise();
        upAudit->raise();
        label_5->raise();
        addPartLocal->raise();
        delParts->raise();
        redParts->raise();
        label_6->raise();
        lineEditGOST->raise();
        addPartGOST->raise();
        menubar = new QMenuBar(AnotherWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1172, 22));
        AnotherWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AnotherWindow);
        statusbar->setObjectName("statusbar");
        AnotherWindow->setStatusBar(statusbar);

        retranslateUi(AnotherWindow);

        QMetaObject::connectSlotsByName(AnotherWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AnotherWindow)
    {
        AnotherWindow->setWindowTitle(QCoreApplication::translate("AnotherWindow", "MainWindow", nullptr));
        label_9->setText(QCoreApplication::translate("AnotherWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">\320\237\321\200\320\270\320\262\320\265\321\202\321\201\320\262\321\203\320\265\320\274!</span></p></body></html>", nullptr));
        labelName->setText(QCoreApplication::translate("AnotherWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">\320\270\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("AnotherWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">\320\222\321\213 \320\262\320\276\321\210\320\273\320\270 \321\201 \320\277\321\200\320\260\320\262\320\260\320\274\320\270:</span></p></body></html>", nullptr));
        labelRoll->setText(QCoreApplication::translate("AnotherWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt;\">\321\200\320\276\320\273\321\214</span></p></body></html>", nullptr));
        fullGuild_2->setText(QCoreApplication::translate("AnotherWindow", "\320\240\321\203\320\272\320\276\320\262\320\276\320\264\321\201\320\262\320\276", nullptr));
        fullInfo_2->setText(QCoreApplication::translate("AnotherWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        fullExit_2->setText(QCoreApplication::translate("AnotherWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        AdminButton->setText(QCoreApplication::translate("AnotherWindow", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200", nullptr));
        addPartGOST->setText(QCoreApplication::translate("AnotherWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("AnotherWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">\321\201\320\277\320\270\321\201\320\276\320\272 \321\201\320\261\320\276\321\200\320\276\320\272</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("AnotherWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">\320\240\320\265\320\264\320\260\320\272\321\202\320\276\321\200 \321\201\320\261\320\276\321\200\320\272\320\270</span></p></body></html>", nullptr));
        upPart->setText(QCoreApplication::translate("AnotherWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(tooltip)
        tableViewAudit->setToolTip(QCoreApplication::translate("AnotherWindow", "<html><head/><body><p>\321\201\320\277\320\270\321\201\320\276\320\272 \320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\271 \320\267\320\260 \320\262\321\201\321\221 \320\262\321\200\320\265\320\274\321\217</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        S->setText(QCoreApplication::translate("AnotherWindow", "<html><head/><body><p align=\"center\">\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265 \320\261\320\260\320\267\321\213 \320\264\320\260\320\275\320\275\321\213\321\205</p></body></html>", nullptr));
        delPart->setText(QCoreApplication::translate("AnotherWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(tooltip)
        tableViewBuilds->setToolTip(QCoreApplication::translate("AnotherWindow", "<html><head/><body><p>\321\201\320\277\320\270\321\201\320\276\320\272 \320\262\321\201\320\265\321\205 \321\201\320\261\320\276\321\200\320\276\320\272 \320\262 \321\201\320\270\321\201\321\202\320\265\320\274\320\265</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        delAudit->setText(QCoreApplication::translate("AnotherWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("AnotherWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">\320\250\320\260\320\261\320\273\320\276\320\275\320\275\321\213\320\265 \320\264\320\265\321\202\320\260\320\273\320\270</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        tableViewGOST->setToolTip(QCoreApplication::translate("AnotherWindow", "<html><head/><body><p>\321\201\320\277\320\270\321\201\320\276\320\272 \321\210\320\260\320\261\320\273\320\276\320\275\320\275\321\213\321\205 \320\264\320\265\321\202\320\260\320\273\320\265\320\271</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        lineEditGOST->setToolTip(QCoreApplication::translate("AnotherWindow", "<html><head/><body><p>\320\275\320\276\320\274\320\265\321\200 \320\223\320\236\320\241\320\242 \321\215\321\202\320\276 5 \321\206\321\213\321\204\321\200</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        lineEditGOST->setText(QCoreApplication::translate("AnotherWindow", "\320\223\320\236\320\241\320\242", nullptr));
        redParts->setText(QCoreApplication::translate("AnotherWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        delParts->setText(QCoreApplication::translate("AnotherWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        redBuilds->setText(QCoreApplication::translate("AnotherWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        addPartLocal->setText(QCoreApplication::translate("AnotherWindow", "\320\233\320\276\320\272\320\260\320\273\321\214\320\275\321\203\321\216", nullptr));
        redPArt->setText(QCoreApplication::translate("AnotherWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        upBuilds->setText(QCoreApplication::translate("AnotherWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("AnotherWindow", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\264\320\265\321\202\320\260\320\273\321\214:", nullptr));
        upAudit->setText(QCoreApplication::translate("AnotherWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        addPart->setText(QCoreApplication::translate("AnotherWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("AnotherWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700;\">\320\264\320\260\320\275\320\275\321\213\320\265 \320\260\321\203\320\264\320\270\321\202\320\260</span></p></body></html>", nullptr));
        upParts->setText(QCoreApplication::translate("AnotherWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        delBuilds->setText(QCoreApplication::translate("AnotherWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        label_6->setText(QCoreApplication::translate("AnotherWindow", "\320\277\320\276 \320\275\320\276\320\274\320\265\321\200\321\203 \320\223\320\236\320\241\320\242:", nullptr));
        addBuilds->setText(QCoreApplication::translate("AnotherWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(tooltip)
        tableViewParts->setToolTip(QCoreApplication::translate("AnotherWindow", "<html><head/><body><p>\321\200\320\265\320\264\320\260\320\272\321\202\320\276\321\200 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\320\276\320\271 \321\201\320\261\320\276\321\200\320\272\320\270</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class AnotherWindow: public Ui_AnotherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANOTHERWINDOW_H
