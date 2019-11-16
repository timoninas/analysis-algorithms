#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QColor>
#include <QPainter>
#include <QStack>
#include <math.h>
#include <QTime>
#include <QCoreApplication>
#include <stdio.h>
#include <ctime>

#define SEP_X 320
#define DELAY_TIME 50

struct fract_type {
    double A;
    double B;
    double C;
    double D;
    int n;
};


class paintwidget : public QWidget
{
    Q_OBJECT
private:
    QImage my_image;
    bool delay = 0;

public:
    explicit paintwidget(QWidget *parent = nullptr);

    void clear();

    void draw_fractal();

    void draw_fractal_rec();

    void kov(QPainter &painter, double A, double B, double C, double D, int n);

    void nkov(QPainter &painter, double A, double B, double C, double D, int n);

    void set_delay();

    void reset_delay();

    unsigned long long test_rec();

    unsigned long long test();

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // PAINTWIDGET_H
