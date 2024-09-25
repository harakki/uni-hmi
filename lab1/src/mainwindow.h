#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "areacalc.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showAuthor();
    void calculate();
    void clear();
    void changeFigureType(int index);

private:
    Ui::MainWindow *ui;
    AreaCalc calculator;
};

#endif // MAINWINDOW_H
