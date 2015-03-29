#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->spnBox_noOfPrcs, SIGNAL(valueChanged(int)), this, SLOT(numberOfProcessesChanged(int)));

    connect(ui->radioBtn_FCFS, SIGNAL(toggled(bool)), this, SLOT(FCFSToggled(bool)));
    connect(ui->radioBtn_SJF, SIGNAL(toggled(bool)), this, SLOT(SJFToggled(bool)));
    connect(ui->radioBtn_Priority, SIGNAL(toggled(bool)), this, SLOT(priorityToggled(bool)));
    connect(ui->radioBtn_RoundRobin, SIGNAL(toggled(bool)), this, SLOT(roundRobinToggled(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberOfProcessesChanged(int n) {
    int lastRow   = ui->tblWdt_process->rowCount() - 1;
    int loopCount = n - lastRow - 1;

    for (int i = 0; i < abs(loopCount); i++) {
        if (loopCount < 0)
            ui->tblWdt_process->removeRow(lastRow--);
        else
            ui->tblWdt_process->insertRow(++lastRow);

    }
}

void MainWindow::FCFSToggled(bool isChecked) {

}

void MainWindow::SJFToggled(bool isChecked) {
    if (isChecked)
        ui->chkBox_preemption->setEnabled(true);
    else
        ui->chkBox_preemption->setEnabled(false);
}

void MainWindow::priorityToggled(bool isChecked) {
    if (isChecked)
        ui->chkBox_preemption->setEnabled(true);
    else
        ui->chkBox_preemption->setEnabled(false);
}

void MainWindow::roundRobinToggled(bool isChecked) {
    if (isChecked)
        ui->dblSpinBox_quantum->setEnabled(true);
    else
        ui->dblSpinBox_quantum->setEnabled(false);
}
