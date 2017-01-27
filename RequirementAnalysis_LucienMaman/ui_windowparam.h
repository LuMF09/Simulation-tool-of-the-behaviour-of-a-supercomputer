/********************************************************************************
** Form generated from reading UI file 'windowparam.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWPARAM_H
#define UI_WINDOWPARAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_windowParam
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_5;
    QPushButton *pushButton;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;

    void setupUi(QDialog *windowParam)
    {
        if (windowParam->objectName().isEmpty())
            windowParam->setObjectName(QStringLiteral("windowParam"));
        windowParam->resize(486, 272);
        verticalLayoutWidget = new QWidget(windowParam);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 184, 110));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        pushButton = new QPushButton(windowParam);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 230, 93, 28));
        label_6 = new QLabel(windowParam);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 150, 231, 16));
        label_7 = new QLabel(windowParam);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(160, 170, 161, 21));
        label_8 = new QLabel(windowParam);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(260, 150, 191, 16));
        label_9 = new QLabel(windowParam);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(160, 200, 191, 16));
        verticalLayoutWidget_2 = new QWidget(windowParam);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(220, 20, 242, 110));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(verticalLayoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_2->addWidget(label_10);

        label_11 = new QLabel(verticalLayoutWidget_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_2->addWidget(label_11);

        label_12 = new QLabel(verticalLayoutWidget_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_2->addWidget(label_12);

        label_13 = new QLabel(verticalLayoutWidget_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_2->addWidget(label_13);

        label_14 = new QLabel(verticalLayoutWidget_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_2->addWidget(label_14);


        retranslateUi(windowParam);

        QMetaObject::connectSlotsByName(windowParam);
    } // setupUi

    void retranslateUi(QDialog *windowParam)
    {
        windowParam->setWindowTitle(QApplication::translate("windowParam", "Informations", 0));
        label->setText(QApplication::translate("windowParam", "Cost for a short job : 250", 0));
        label_4->setText(QApplication::translate("windowParam", "Cost for an interactive job : 250", 0));
        label_3->setText(QApplication::translate("windowParam", "Cost for a medium job : 350", 0));
        label_2->setText(QApplication::translate("windowParam", "Cost for a large job : 450", 0));
        label_5->setText(QApplication::translate("windowParam", "Cost for a huge job : 500", 0));
        pushButton->setText(QApplication::translate("windowParam", "OK", 0));
        label_6->setText(QApplication::translate("windowParam", "The price paid by the user will be these", 0));
        label_7->setText(QApplication::translate("windowParam", "hours requested by the job.", 0));
        label_8->setText(QApplication::translate("windowParam", "costs multiplied by the number of ", 0));
        label_9->setText(QApplication::translate("windowParam", "1 week of simulation last 1.68s", 0));
        label_10->setText(QApplication::translate("windowParam", "Operating cost for a short job : 500", 0));
        label_11->setText(QApplication::translate("windowParam", "Operating cost for an interactive job : 500", 0));
        label_12->setText(QApplication::translate("windowParam", "Operating cost for a medium job : 600", 0));
        label_13->setText(QApplication::translate("windowParam", "Operating cost for a large job : 700", 0));
        label_14->setText(QApplication::translate("windowParam", "Operating cost for a huge job : 800", 0));
    } // retranslateUi

};

namespace Ui {
    class windowParam: public Ui_windowParam {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWPARAM_H
