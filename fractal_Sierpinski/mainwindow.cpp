#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColor>
#include <QColorDialog>
#include <QKeyEvent>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myscene = new paintwidget(ui->draw_widget);
    myscene->setMinimumSize(640, 600);

    myscene->clear(); //without this string the window will be without background
    new_bound = true;

    shift_pressed = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonFractal_clicked()
{
    myscene->draw_fractal();
}

void MainWindow::on_buttonSetDelay_clicked()
{
    myscene->set_delay();
}

void MainWindow::on_buttonResetDelay_clicked()
{
    myscene->reset_delay();
}

void MainWindow::on_buttonTestFractal_clicked()
{
    auto answer = myscene->test();
    ui->test->setText(QString::number(answer));
}

void MainWindow::on_buttonTestFractalRec_clicked()
{
    auto answer = myscene->test_rec();
    ui->testRec->setText(QString::number(answer));
}

void MainWindow::on_buttonClear_clicked()
{
    myscene->clear();
}

void MainWindow::on_buttonFractalRec_clicked()
{
    myscene->draw_fractal_rec();
}
