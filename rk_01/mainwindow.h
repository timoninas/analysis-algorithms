#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "paintwidget.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void change_widget_color(QWidget *wid, QColor color);
    void add_point(QPoint &p);
    void close_poly();
    ~MainWindow();

private slots:

    void on_buttonFractal_clicked();

    void on_buttonResetDelay_clicked();

    void on_buttonSetDelay_clicked();

    void on_buttonTestFractal_clicked();

    void on_buttonTestFractalRec_clicked();

    void on_buttonClear_clicked();

    void on_buttonFractalRec_clicked();

private:
    Ui::MainWindow *ui;
    paintwidget *myscene;
    bool new_bound;
    bool shift_pressed;


};
#endif // MAINWINDOW_H
