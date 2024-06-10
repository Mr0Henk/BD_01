/********************************************************************************
** Form generated from reading UI file 'adminroom.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINROOM_H
#define UI_ADMINROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_AdminRoom
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *dellAdmin;
    QSpacerItem *horizontalSpacer_5;
    QTableView *tableView;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *redAdmin;
    QPushButton *addAdmin;
    QLabel *label;

    void setupUi(QDialog *AdminRoom)
    {
        if (AdminRoom->objectName().isEmpty())
            AdminRoom->setObjectName("AdminRoom");
        AdminRoom->resize(424, 313);
        AdminRoom->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 255, 255)"));
        gridLayout = new QGridLayout(AdminRoom);
        gridLayout->setObjectName("gridLayout");
        pushButton_5 = new QPushButton(AdminRoom);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(pushButton_5, 3, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 0, 1, 1);

        dellAdmin = new QPushButton(AdminRoom);
        dellAdmin->setObjectName("dellAdmin");
        dellAdmin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(dellAdmin, 2, 3, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 4, 1, 1);

        tableView = new QTableView(AdminRoom);
        tableView->setObjectName("tableView");
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"	border: 2px solid #005870;\n"
"     border-radius: 2px;\n"
"     background-color: white;\n"
"     selection-background-color: rgb(0, 85, 255);\n"
" }\n"
"QTableView QTableCornerButton::section {\n"
"     background: #0040ff;\n"
"     border: 2px outset #0004ff;\n"
" }"));

        gridLayout->addWidget(tableView, 1, 0, 1, 5);

        pushButton_4 = new QPushButton(AdminRoom);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(pushButton_4, 3, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 2, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 4, 1, 1);

        redAdmin = new QPushButton(AdminRoom);
        redAdmin->setObjectName("redAdmin");
        redAdmin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     border: 1px solid #005870;\n"
"     border-radius: 2px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #b8f0ff, stop: 1 #57d5f7);\n"
"\n"
"     min-width: 90px;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #005870, stop: 1 #00c8ff);\n"
" }"));

        gridLayout->addWidget(redAdmin, 2, 2, 1, 1);

        addAdmin = new QPushButton(AdminRoom);
        addAdmin->setObjectName("addAdmin");
        addAdmin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(addAdmin, 2, 1, 1, 1);

        label = new QLabel(AdminRoom);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 5);


        retranslateUi(AdminRoom);

        QMetaObject::connectSlotsByName(AdminRoom);
    } // setupUi

    void retranslateUi(QDialog *AdminRoom)
    {
        AdminRoom->setWindowTitle(QCoreApplication::translate("AdminRoom", "Dialog", nullptr));
        pushButton_5->setText(QCoreApplication::translate("AdminRoom", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        dellAdmin->setText(QCoreApplication::translate("AdminRoom", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_4->setText(QCoreApplication::translate("AdminRoom", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
        redAdmin->setText(QCoreApplication::translate("AdminRoom", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        addAdmin->setText(QCoreApplication::translate("AdminRoom", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("AdminRoom", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:700;\">\320\241\320\277\320\270\321\201\320\276\320\272 \320\267\320\260\321\200\320\265\320\263\320\265\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\321\205 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265\320\271</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminRoom: public Ui_AdminRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINROOM_H
