#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->spnBox_noOfPrcs, SIGNAL(valueChanged(int)), this, SLOT(numberOfProcessesChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberOfProcessesChanged(int n) {
    int lastRow   = ui->tblWdt_process->rowCount() - 1;
    int loopCount = n - lastRow - 1;

    qDebug() << lastRow;
    qDebug() << loopCount;

    for (int i = 0; i < abs(loopCount); i++) {
        if (loopCount < 0)
            ui->tblWdt_process->removeRow(lastRow--);
        else
            ui->tblWdt_process->insertRow(++lastRow);

    }
}
