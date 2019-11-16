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
    new_bound = true;
    shift_pressed = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    myscene->draw_fractal_rec();
}

void MainWindow::on_pushButton_3_clicked()
{
    myscene->clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    myscene->draw_fractal();
}

void MainWindow::on_pushButton_4_clicked()
{
    myscene->set_delay();
}

void MainWindow::on_pushButton_5_clicked()
{
    myscene->reset_delay();
}

void MainWindow::on_pushButton_6_clicked()
{
    auto answer = myscene->test();
    ui->test->setText(QString::number(answer));
}

void MainWindow::on_pushButton_7_clicked()
{
    auto answer = myscene->test_rec();
    ui->testRec->setText(QString::number(answer));
}
