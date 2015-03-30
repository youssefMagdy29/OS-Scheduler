#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    processes(new LinkedList<Process>)
{
    ui->setupUi(this);

    connect(ui->spnBox_noOfPrcs, SIGNAL(valueChanged(int)), this, SLOT(numberOfProcessesChanged(int)));

    connect(ui->btn_schedule, SIGNAL(clicked()), this, SLOT(scheduleButtonClicked()));

    connect(ui->radioBtn_FCFS, SIGNAL(toggled(bool)), this, SLOT(FCFSToggled(bool)));
    connect(ui->radioBtn_SJF, SIGNAL(toggled(bool)), this, SLOT(SJFToggled(bool)));
    connect(ui->radioBtn_Priority, SIGNAL(toggled(bool)), this, SLOT(priorityToggled(bool)));
    connect(ui->radioBtn_RoundRobin, SIGNAL(toggled(bool)), this, SLOT(roundRobinToggled(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//updating table when number of processes is changed
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

//FCFS check button state changed
void MainWindow::FCFSToggled(bool isChecked) {
    if (isChecked)
        currType = FCFS;
}

//SJF check button state changed
void MainWindow::SJFToggled(bool isChecked) {
    if (isChecked) {
        currType = SJF;
        ui->chkBox_preemption->setEnabled(true);
    }
    else
        ui->chkBox_preemption->setEnabled(false);
}

//Priority check button state changed
void MainWindow::priorityToggled(bool isChecked) {
    if (isChecked) {
        currType = PRIORITY;
        ui->chkBox_preemption->setEnabled(true);

        ui->tblWdt_process->insertColumn(3);
        ui->tblWdt_process->setHorizontalHeaderItem(3, new QTableWidgetItem(QString("Priority")));
        ui->tblWdt_process->horizontalHeader()->setDefaultSectionSize(118);
    }
    else {
        ui->chkBox_preemption->setEnabled(false);


        ui->tblWdt_process->removeColumn(3);
        ui->tblWdt_process->horizontalHeader()->setDefaultSectionSize(158);
    }
}

//Round Robin  check button state changed
void MainWindow::roundRobinToggled(bool isChecked) {
    if (isChecked) {
        currType = ROUND_ROBIN;

        ui->dblSpinBox_quantum->setEnabled(true);
    }
    else
        ui->dblSpinBox_quantum->setEnabled(false);
}

void MainWindow::scheduleButtonClicked() {
    int rows = ui->tblWdt_process->rowCount();
    int cols = ui->tblWdt_process->columnCount();

    for (int i = 0; i < rows; i++) {
        std::string name = ui->tblWdt_process->item(i, 0)->text().toStdString();
        int arrival_time = ui->tblWdt_process->item(i, 1)->text().toInt();
        int burst_time   = ui->tblWdt_process->item(i, 2)->text().toInt();
        int priority     = (cols > 3 ? ui->tblWdt_process->item(i, 3)->text().toInt() : -1);

        qDebug() << QString(name.c_str()) << arrival_time << burst_time << priority;

        processes->push_back(Process(name, arrival_time, burst_time, priority));
    }
}
