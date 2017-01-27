#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scheduler.h"
#include "iostream"
#include "dividezero.h"
#include "unknowtypejob.h"
#include "docopen.h"
#include "badinput.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),set1({0,0,0,0,0,0,0,0,0,0,0,0,0,0}),
  windowParameter(this)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_run_clicked()
{       //If no users are created
    if(ui->spinBox_nbStudent_MscSETC->value()
            +ui->spinBox_nbStudent_MscSEnergy->value()
            +ui->spinBox_nbStudent_PhdAPS->value()
            +ui->spinBox_nbResearcher_Aerospace->value()
            +ui->spinBox_nbResearcher_Defense->value()
            +ui->spinBox_nbResearcher_Environment->value()==0)
    {
            QMessageBox::information(this, "No users","Please choose at least one user!");
    }
    else
    {
    this->hide();// The user can't do anything after pushing the run button

    //gather data
    set1.nbStudentSETC=ui->spinBox_nbStudent_MscSETC->value();
    set1.nbStudentEnergy=ui->spinBox_nbStudent_MscSEnergy->value();
    set1.nbStudentPhdAero=ui->spinBox_nbStudent_PhdAPS->value();

    set1.amountSETC=ui->doubleSpinBox_amount_MscSETC->value();
    set1.amountEnergy=ui->doubleSpinBox_amount_MscEnergy->value();
    set1.amountPhdAero=ui->doubleSpinBox_amount_PhdAerospace->value();

    set1.nbResearcherAero=ui->spinBox_nbResearcher_Aerospace->value();
    set1.nbResearcherDefense=ui->spinBox_nbResearcher_Defense->value();
    set1.nbResearcherEnv=ui->spinBox_nbResearcher_Environment->value();

    set1.amountAeroResearch=ui->doubleSpinBox_amount_AeroResearch->value();
    set1.amountDefense=ui->doubleSpinBox_amount_Defense->value();
    set1.amountEnv=ui->doubleSpinBox_amount_Env->value();

    set1.nbIT=ui->spinBox_nbIT->value();

    set1.nbWeek=ui->spinBox_nbWeek->value();

    //START SIMULATION
    try
    {
        Scheduler run(set1);
        run.startScheduler(set1.nbWeek);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    close();//end
    }
}

void MainWindow::on_pushButton_reset_clicked()
{
    //RESET PARAMETERS

    ui->spinBox_nbStudent_MscSETC->setValue(1000);
    ui->spinBox_nbStudent_MscSEnergy->setValue(1000);
    ui->spinBox_nbStudent_PhdAPS->setValue(1000);

    ui->doubleSpinBox_amount_MscEnergy->setValue(1000.00);
    ui->doubleSpinBox_amount_MscSETC->setValue(1000.00);
    ui->doubleSpinBox_amount_PhdAerospace->setValue(1000.00);

    ui->spinBox_nbResearcher_Defense->setValue(1000);
    ui->spinBox_nbResearcher_Environment->setValue(1000);
    ui->spinBox_nbResearcher_Aerospace->setValue(1000);

    ui->doubleSpinBox_amount_AeroResearch->setValue(1000.00);
    ui->doubleSpinBox_amount_Defense->setValue(1000.00);
    ui->doubleSpinBox_amount_Env->setValue(1000.00);

    ui->spinBox_nbIT->setValue(1);

    ui->spinBox_nbWeek->setValue(1);
}

void MainWindow::on_pushButton_param_clicked()
{
    windowParameter.show();
}

void MainWindow::on_pushButton_max_clicked()
{
    //SET ALL PARAMETERS AT THE MAXIMUM AUTHORIZED

    ui->spinBox_nbStudent_MscSETC->setValue(5000);
    ui->spinBox_nbStudent_MscSEnergy->setValue(5000);
    ui->spinBox_nbStudent_PhdAPS->setValue(5000);

    ui->doubleSpinBox_amount_MscEnergy->setValue(5000.00);
    ui->doubleSpinBox_amount_MscSETC->setValue(5000.00);
    ui->doubleSpinBox_amount_PhdAerospace->setValue(5000.00);

    ui->spinBox_nbResearcher_Defense->setValue(5000);
    ui->spinBox_nbResearcher_Environment->setValue(5000);
    ui->spinBox_nbResearcher_Aerospace->setValue(5000);

    ui->doubleSpinBox_amount_AeroResearch->setValue(5000.00);
    ui->doubleSpinBox_amount_Defense->setValue(5000.00);
    ui->doubleSpinBox_amount_Env->setValue(5000.00);

    ui->spinBox_nbIT->setValue(100);

    ui->spinBox_nbWeek->setValue(53);
}
