#ifndef WINDOWPARAM_H
#define WINDOWPARAM_H

#include <QDialog>

namespace Ui {
class windowParam;
}

class windowParam : public QDialog
{
    Q_OBJECT

public:
    explicit windowParam(QWidget *parent = 0);
    ~windowParam();

private slots:
    void on_pushButton_clicked();

private:
    Ui::windowParam *ui;
};

#endif // WINDOWPARAM_H
