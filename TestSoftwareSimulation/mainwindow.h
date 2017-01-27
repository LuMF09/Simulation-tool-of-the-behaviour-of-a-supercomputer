#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "windowparam.h"

namespace Ui {
class MainWindow;
}
struct setOfParameter{
    int nbStudentSETC,nbStudentEnergy,nbStudentPhdAero,nbResearcherDefense,nbResearcherAero,nbResearcherEnv,nbIT, nbWeek;
    double amountSETC,amountEnergy,amountPhdAero,amountDefense,amountAeroResearch,amountEnv;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_run_clicked();

    void on_pushButton_reset_clicked();

    void on_pushButton_param_clicked();

    void on_pushButton_max_clicked();

private:
    Ui::MainWindow *ui;
    windowParam windowParameter;
    setOfParameter set1;
};

#endif // MAINWINDOW_H
