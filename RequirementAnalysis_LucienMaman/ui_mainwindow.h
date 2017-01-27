/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_HowManyProfile;
    QLabel *label_student;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_SETC;
    QSpinBox *spinBox_nbStudent_MscSETC;
    QLabel *label_amount1;
    QDoubleSpinBox *doubleSpinBox_amount_MscSETC;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Energy;
    QSpinBox *spinBox_nbStudent_MscSEnergy;
    QLabel *label_amount2;
    QDoubleSpinBox *doubleSpinBox_amount_MscEnergy;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_phdAPS;
    QSpinBox *spinBox_nbStudent_PhdAPS;
    QLabel *label_amount3;
    QDoubleSpinBox *doubleSpinBox_amount_PhdAerospace;
    QLabel *label_researcher;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_Defense;
    QSpinBox *spinBox_nbResearcher_Defense;
    QLabel *label_amount4;
    QDoubleSpinBox *doubleSpinBox_amount_Defense;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_Aerospace;
    QSpinBox *spinBox_nbResearcher_Aerospace;
    QLabel *label_amount5;
    QDoubleSpinBox *doubleSpinBox_amount_AeroResearch;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_Environment;
    QSpinBox *spinBox_nbResearcher_Environment;
    QLabel *label_amount6;
    QDoubleSpinBox *doubleSpinBox_amount_Env;
    QLabel *label_blank_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_IT;
    QSpinBox *spinBox_nbIT;
    QLabel *label_blank_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_howManyWeek;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_nbWeek;
    QSpinBox *spinBox_nbWeek;
    QPushButton *pushButton_run;
    QPushButton *pushButton_reset;
    QPushButton *pushButton_param;
    QPushButton *pushButton_max;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(554, 537);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 491, 387));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_HowManyProfile = new QLabel(verticalLayoutWidget);
        label_HowManyProfile->setObjectName(QStringLiteral("label_HowManyProfile"));
        label_HowManyProfile->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_HowManyProfile);

        label_student = new QLabel(verticalLayoutWidget);
        label_student->setObjectName(QStringLiteral("label_student"));

        verticalLayout->addWidget(label_student);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_SETC = new QLabel(verticalLayoutWidget);
        label_SETC->setObjectName(QStringLiteral("label_SETC"));

        horizontalLayout_2->addWidget(label_SETC);

        spinBox_nbStudent_MscSETC = new QSpinBox(verticalLayoutWidget);
        spinBox_nbStudent_MscSETC->setObjectName(QStringLiteral("spinBox_nbStudent_MscSETC"));
        spinBox_nbStudent_MscSETC->setMaximum(5000);
        spinBox_nbStudent_MscSETC->setSingleStep(100);
        spinBox_nbStudent_MscSETC->setValue(1000);

        horizontalLayout_2->addWidget(spinBox_nbStudent_MscSETC);

        label_amount1 = new QLabel(verticalLayoutWidget);
        label_amount1->setObjectName(QStringLiteral("label_amount1"));

        horizontalLayout_2->addWidget(label_amount1);

        doubleSpinBox_amount_MscSETC = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_amount_MscSETC->setObjectName(QStringLiteral("doubleSpinBox_amount_MscSETC"));
        doubleSpinBox_amount_MscSETC->setMaximum(5000);
        doubleSpinBox_amount_MscSETC->setSingleStep(100);
        doubleSpinBox_amount_MscSETC->setValue(1000);

        horizontalLayout_2->addWidget(doubleSpinBox_amount_MscSETC);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_Energy = new QLabel(verticalLayoutWidget);
        label_Energy->setObjectName(QStringLiteral("label_Energy"));

        horizontalLayout_3->addWidget(label_Energy);

        spinBox_nbStudent_MscSEnergy = new QSpinBox(verticalLayoutWidget);
        spinBox_nbStudent_MscSEnergy->setObjectName(QStringLiteral("spinBox_nbStudent_MscSEnergy"));
        spinBox_nbStudent_MscSEnergy->setMaximum(5000);
        spinBox_nbStudent_MscSEnergy->setSingleStep(100);
        spinBox_nbStudent_MscSEnergy->setValue(1000);

        horizontalLayout_3->addWidget(spinBox_nbStudent_MscSEnergy);

        label_amount2 = new QLabel(verticalLayoutWidget);
        label_amount2->setObjectName(QStringLiteral("label_amount2"));

        horizontalLayout_3->addWidget(label_amount2);

        doubleSpinBox_amount_MscEnergy = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_amount_MscEnergy->setObjectName(QStringLiteral("doubleSpinBox_amount_MscEnergy"));
        doubleSpinBox_amount_MscEnergy->setMaximum(5000);
        doubleSpinBox_amount_MscEnergy->setSingleStep(100);
        doubleSpinBox_amount_MscEnergy->setValue(1000);

        horizontalLayout_3->addWidget(doubleSpinBox_amount_MscEnergy);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_phdAPS = new QLabel(verticalLayoutWidget);
        label_phdAPS->setObjectName(QStringLiteral("label_phdAPS"));

        horizontalLayout_6->addWidget(label_phdAPS);

        spinBox_nbStudent_PhdAPS = new QSpinBox(verticalLayoutWidget);
        spinBox_nbStudent_PhdAPS->setObjectName(QStringLiteral("spinBox_nbStudent_PhdAPS"));
        spinBox_nbStudent_PhdAPS->setMaximum(5000);
        spinBox_nbStudent_PhdAPS->setSingleStep(100);
        spinBox_nbStudent_PhdAPS->setValue(1000);

        horizontalLayout_6->addWidget(spinBox_nbStudent_PhdAPS);

        label_amount3 = new QLabel(verticalLayoutWidget);
        label_amount3->setObjectName(QStringLiteral("label_amount3"));

        horizontalLayout_6->addWidget(label_amount3);

        doubleSpinBox_amount_PhdAerospace = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_amount_PhdAerospace->setObjectName(QStringLiteral("doubleSpinBox_amount_PhdAerospace"));
        doubleSpinBox_amount_PhdAerospace->setMaximum(5000);
        doubleSpinBox_amount_PhdAerospace->setSingleStep(100);
        doubleSpinBox_amount_PhdAerospace->setValue(1000);

        horizontalLayout_6->addWidget(doubleSpinBox_amount_PhdAerospace);


        verticalLayout_3->addLayout(horizontalLayout_6);


        verticalLayout->addLayout(verticalLayout_3);

        label_researcher = new QLabel(verticalLayoutWidget);
        label_researcher->setObjectName(QStringLiteral("label_researcher"));

        verticalLayout->addWidget(label_researcher);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_Defense = new QLabel(verticalLayoutWidget);
        label_Defense->setObjectName(QStringLiteral("label_Defense"));

        horizontalLayout_7->addWidget(label_Defense);

        spinBox_nbResearcher_Defense = new QSpinBox(verticalLayoutWidget);
        spinBox_nbResearcher_Defense->setObjectName(QStringLiteral("spinBox_nbResearcher_Defense"));
        spinBox_nbResearcher_Defense->setMaximum(5000);
        spinBox_nbResearcher_Defense->setSingleStep(100);
        spinBox_nbResearcher_Defense->setValue(1000);

        horizontalLayout_7->addWidget(spinBox_nbResearcher_Defense);

        label_amount4 = new QLabel(verticalLayoutWidget);
        label_amount4->setObjectName(QStringLiteral("label_amount4"));

        horizontalLayout_7->addWidget(label_amount4);

        doubleSpinBox_amount_Defense = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_amount_Defense->setObjectName(QStringLiteral("doubleSpinBox_amount_Defense"));
        doubleSpinBox_amount_Defense->setMaximum(5000);
        doubleSpinBox_amount_Defense->setSingleStep(100);
        doubleSpinBox_amount_Defense->setValue(1000);

        horizontalLayout_7->addWidget(doubleSpinBox_amount_Defense);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_Aerospace = new QLabel(verticalLayoutWidget);
        label_Aerospace->setObjectName(QStringLiteral("label_Aerospace"));

        horizontalLayout_8->addWidget(label_Aerospace);

        spinBox_nbResearcher_Aerospace = new QSpinBox(verticalLayoutWidget);
        spinBox_nbResearcher_Aerospace->setObjectName(QStringLiteral("spinBox_nbResearcher_Aerospace"));
        spinBox_nbResearcher_Aerospace->setMaximum(5000);
        spinBox_nbResearcher_Aerospace->setSingleStep(100);
        spinBox_nbResearcher_Aerospace->setValue(1000);

        horizontalLayout_8->addWidget(spinBox_nbResearcher_Aerospace);

        label_amount5 = new QLabel(verticalLayoutWidget);
        label_amount5->setObjectName(QStringLiteral("label_amount5"));

        horizontalLayout_8->addWidget(label_amount5);

        doubleSpinBox_amount_AeroResearch = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_amount_AeroResearch->setObjectName(QStringLiteral("doubleSpinBox_amount_AeroResearch"));
        doubleSpinBox_amount_AeroResearch->setMaximum(5000);
        doubleSpinBox_amount_AeroResearch->setSingleStep(100);
        doubleSpinBox_amount_AeroResearch->setValue(1000);

        horizontalLayout_8->addWidget(doubleSpinBox_amount_AeroResearch);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_Environment = new QLabel(verticalLayoutWidget);
        label_Environment->setObjectName(QStringLiteral("label_Environment"));

        horizontalLayout_9->addWidget(label_Environment);

        spinBox_nbResearcher_Environment = new QSpinBox(verticalLayoutWidget);
        spinBox_nbResearcher_Environment->setObjectName(QStringLiteral("spinBox_nbResearcher_Environment"));
        spinBox_nbResearcher_Environment->setMaximum(5000);
        spinBox_nbResearcher_Environment->setSingleStep(100);
        spinBox_nbResearcher_Environment->setValue(1000);

        horizontalLayout_9->addWidget(spinBox_nbResearcher_Environment);

        label_amount6 = new QLabel(verticalLayoutWidget);
        label_amount6->setObjectName(QStringLiteral("label_amount6"));

        horizontalLayout_9->addWidget(label_amount6);

        doubleSpinBox_amount_Env = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_amount_Env->setObjectName(QStringLiteral("doubleSpinBox_amount_Env"));
        doubleSpinBox_amount_Env->setMaximum(5000);
        doubleSpinBox_amount_Env->setSingleStep(100);
        doubleSpinBox_amount_Env->setValue(1000);

        horizontalLayout_9->addWidget(doubleSpinBox_amount_Env);


        verticalLayout_4->addLayout(horizontalLayout_9);


        verticalLayout->addLayout(verticalLayout_4);

        label_blank_3 = new QLabel(verticalLayoutWidget);
        label_blank_3->setObjectName(QStringLiteral("label_blank_3"));

        verticalLayout->addWidget(label_blank_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_IT = new QLabel(verticalLayoutWidget);
        label_IT->setObjectName(QStringLiteral("label_IT"));

        horizontalLayout->addWidget(label_IT);

        spinBox_nbIT = new QSpinBox(verticalLayoutWidget);
        spinBox_nbIT->setObjectName(QStringLiteral("spinBox_nbIT"));
        spinBox_nbIT->setMinimum(1);
        spinBox_nbIT->setMaximum(100);
        spinBox_nbIT->setValue(1);

        horizontalLayout->addWidget(spinBox_nbIT);


        verticalLayout->addLayout(horizontalLayout);

        label_blank_2 = new QLabel(verticalLayoutWidget);
        label_blank_2->setObjectName(QStringLiteral("label_blank_2"));

        verticalLayout->addWidget(label_blank_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_howManyWeek = new QLabel(verticalLayoutWidget);
        label_howManyWeek->setObjectName(QStringLiteral("label_howManyWeek"));
        label_howManyWeek->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_howManyWeek);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_nbWeek = new QLabel(verticalLayoutWidget);
        label_nbWeek->setObjectName(QStringLiteral("label_nbWeek"));

        horizontalLayout_5->addWidget(label_nbWeek);

        spinBox_nbWeek = new QSpinBox(verticalLayoutWidget);
        spinBox_nbWeek->setObjectName(QStringLiteral("spinBox_nbWeek"));
        spinBox_nbWeek->setMinimum(1);
        spinBox_nbWeek->setMaximum(53);
        spinBox_nbWeek->setValue(1);

        horizontalLayout_5->addWidget(spinBox_nbWeek);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout->addLayout(verticalLayout_2);

        pushButton_run = new QPushButton(centralWidget);
        pushButton_run->setObjectName(QStringLiteral("pushButton_run"));
        pushButton_run->setGeometry(QRect(190, 460, 141, 28));
        pushButton_reset = new QPushButton(centralWidget);
        pushButton_reset->setObjectName(QStringLiteral("pushButton_reset"));
        pushButton_reset->setGeometry(QRect(190, 410, 151, 28));
        pushButton_param = new QPushButton(centralWidget);
        pushButton_param->setObjectName(QStringLiteral("pushButton_param"));
        pushButton_param->setGeometry(QRect(360, 410, 141, 28));
        pushButton_max = new QPushButton(centralWidget);
        pushButton_max->setObjectName(QStringLiteral("pushButton_max"));
        pushButton_max->setGeometry(QRect(20, 410, 151, 28));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 554, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Simulation tool", 0));
        label_HowManyProfile->setText(QApplication::translate("MainWindow", "How many profile will be created to simulate ? ", 0));
        label_student->setText(QApplication::translate("MainWindow", "Number of student:", 0));
        label_SETC->setText(QApplication::translate("MainWindow", "MSc SETC", 0));
        label_amount1->setText(QApplication::translate("MainWindow", "Amount:", 0));
        label_Energy->setText(QApplication::translate("MainWindow", "MSc Energy", 0));
        label_amount2->setText(QApplication::translate("MainWindow", "Amount:", 0));
        label_phdAPS->setText(QApplication::translate("MainWindow", "Phd Aerospace", 0));
        label_amount3->setText(QApplication::translate("MainWindow", "Amount:", 0));
        label_researcher->setText(QApplication::translate("MainWindow", "Number of researcher:", 0));
        label_Defense->setText(QApplication::translate("MainWindow", "Defense and security", 0));
        label_amount4->setText(QApplication::translate("MainWindow", "Amount:", 0));
        label_Aerospace->setText(QApplication::translate("MainWindow", "Aerospace", 0));
        label_amount5->setText(QApplication::translate("MainWindow", "Amount:", 0));
        label_Environment->setText(QApplication::translate("MainWindow", "Environment", 0));
        label_amount6->setText(QApplication::translate("MainWindow", "Amount:", 0));
        label_blank_3->setText(QString());
        label_IT->setText(QApplication::translate("MainWindow", "Number of IT support profiles:", 0));
        label_blank_2->setText(QString());
        label_howManyWeek->setText(QApplication::translate("MainWindow", "How many week will last the simulation ? ", 0));
        label_nbWeek->setText(QApplication::translate("MainWindow", "Number of week (1 to 53): ", 0));
        pushButton_run->setText(QApplication::translate("MainWindow", "Run simulation", 0));
        pushButton_reset->setText(QApplication::translate("MainWindow", "Reset parameters", 0));
        pushButton_param->setText(QApplication::translate("MainWindow", "Informations", 0));
        pushButton_max->setText(QApplication::translate("MainWindow", "Maximum parameters", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
