#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->author, SIGNAL(triggered()), this, SLOT(showAuthor()));
    connect(ui->quit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->calculate, SIGNAL(clicked()), this, SLOT(calculate()));
    connect(ui->clear, SIGNAL(clicked()), this, SLOT(clear()));
    connect(ui->figureType, SIGNAL(currentIndexChanged(int)), this, SLOT(changeFigureType(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showAuthor()
{
    QMessageBox::information(this, "Author", "Shipilov Dementiy, IP-215");
}

void MainWindow::calculate()
{
    double value1 = ui->spin1->value();
    double value2 = ui->spin2->value();
    double value3 = ui->spin3->value();

    double area = 0.0;

    QString figure = ui->figureType->currentText();
    if (figure == "Square") {
        area = calculator.calculateSquare(value1);
    } else if (figure == "Rectangle") {
        area = calculator.calculateRectangle(value1, value2);
    } else if (figure == "Parallelogram") {
        area = calculator.calculateParallelogram(value1, value2);
    } else if (figure == "Rhombus") {
        area = calculator.calculateRhombus(value1, value2);
    } else if (figure == "Triangle") {
        area = calculator.calculateTriangle(value1, value2);
    } else if (figure == "Trapezoid") {
        area = calculator.calculateTrapezoid(value1, value2, value3);
    } else if (figure == "Circle") {
        area = calculator.calculateCircle(value1);
    } else if (figure == "Sector") {
        area = calculator.calculateSector(value1, value2);
    }

    ui->result->setText("= " + QString::number(area));
}

void MainWindow::clear()
{
    ui->spin1->setValue(0);
    ui->spin2->setValue(0);
    ui->spin3->setValue(0);
    ui->result->setText("= " + QString::number(0));
}

void MainWindow::changeFigureType(int index)
{
    ui->spin2->hide();
    ui->spin3->hide();
    ui->spin1->show();
    ui->clear->show();
    ui->calculate->show();

    QString figure = ui->figureType->currentText();
    if (figure == "Square") {
    } else if (figure == "Rectangle") {
        ui->spin2->show();
    } else if (figure == "Parallelogram") {
        ui->spin2->show();
    } else if (figure == "Rhombus") {
        ui->spin2->show();
    } else if (figure == "Triangle") {
        ui->spin2->show();
    } else if (figure == "Trapezoid") {
        ui->spin2->show();
        ui->spin3->show();
    } else if (figure == "Circle") {
    } else if (figure == "Sector") {
        ui->spin2->show();
    } else if (figure == "Nothing") {
        ui->spin1->hide();
        ui->clear->hide();
        ui->calculate->hide();
    }

    QString imagePath = ":/img/" + ui->figureType->currentText().toLower() + ".png";
    QPixmap pixmap(imagePath);
    ui->picture->setPixmap(pixmap.scaled(250, 250, Qt::KeepAspectRatio));
}
