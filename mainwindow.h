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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void numberOfProcessesChanged(int n);
    void FCFSToggled(bool isChecked);
    void SJFToggled(bool isChecked);
    void priorityToggled(bool isChecked);
    void roundRobinToggled(bool isChecked);
};

#endif // MAINWINDOW_H
