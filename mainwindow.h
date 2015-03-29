#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private slots:
    void numberOfProcessesChanged(int n);
    void FCFSToggled(bool isChecked);
    void SJFToggled(bool isChecked);
    void priorityToggled(bool isChecked);
    void roundRobinToggled(bool isChecked);
};

#endif // MAINWINDOW_H
