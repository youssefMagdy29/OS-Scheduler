#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "linkedlist.h"
#include "process.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static enum TYPE {
        FCFS,
        SJF,
        PRIORITY,
        ROUND_ROBIN
    } TYPE;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int currType;
    LinkedList<Process> *processes;

private slots:
    void numberOfProcessesChanged(int n);
    void scheduleButtonClicked();
    void FCFSToggled(bool isChecked);
    void SJFToggled(bool isChecked);
    void priorityToggled(bool isChecked);
    void roundRobinToggled(bool isChecked);
};

#endif // MAINWINDOW_H
