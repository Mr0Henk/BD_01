/********************************************************************************
** Form generated from reading UI file 'addbuilds.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBUILDS_H
#define UI_ADDBUILDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_AddBuilds
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineName;
    QPushButton *canButton;
    QSpacerItem *verticalSpacer;
    QPushButton *okButton;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *AddBuilds)
    {
        if (AddBuilds->objectName().isEmpty())
            AddBuilds->setObjectName("AddBuilds");
        AddBuilds->resize(190, 170);
        gridLayout = new QGridLayout(AddBuilds);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(AddBuilds);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineName = new QLineEdit(AddBuilds);
        lineName->setObjectName("lineName");

        gridLayout->addWidget(lineName, 2, 0, 1, 1);

        canButton = new QPushButton(AddBuilds);
        canButton->setObjectName("canButton");

        gridLayout->addWidget(canButton, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        okButton = new QPushButton(AddBuilds);
        okButton->setObjectName("okButton");

        gridLayout->addWidget(okButton, 4, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 0, 1, 1);


        retranslateUi(AddBuilds);

        QMetaObject::connectSlotsByName(AddBuilds);
    } // setupUi

    void retranslateUi(QDialog *AddBuilds)
    {
        AddBuilds->setWindowTitle(QCoreApplication::translate("AddBuilds", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddBuilds", "\320\224\320\260\320\271\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\320\261\320\276\321\200\320\272\320\265", nullptr));
        canButton->setText(QCoreApplication::translate("AddBuilds", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        okButton->setText(QCoreApplication::translate("AddBuilds", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddBuilds: public Ui_AddBuilds {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBUILDS_H
