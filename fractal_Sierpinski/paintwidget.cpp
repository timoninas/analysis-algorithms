#include "paintwidget.h"

unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__("rdtsc" : "=A" (d));
    return d;
}

paintwidget::paintwidget(QWidget *parent) : QWidget(parent)
{
    int image_height = 600;
    int image_width = 640;
    my_image = QImage(image_width, image_height, QImage::Format_RGB32);
}

void draw_rect(QPainter &painter, double x1, double y1, double x2, double y2);



void paintwidget::nkov(QPainter &painter, double A, double B, double C, double D, int n)
{
    double A1, C1, B1, D1;
    QStack<fract_type> stck;

    stck.push({A, B, C, D, n});

    while (!stck.isEmpty()) {
        fract_type tmp = stck.pop();
        if (delay) {
            QTime end = QTime::currentTime().addMSecs(1);
            while(QTime::currentTime() < end)
                QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);
            repaint();
        }

        draw_rect(painter, tmp.A, tmp.B, tmp.C, tmp.D);\
        if (tmp.n > 0) {
            A1 = 2 * tmp.A / 3 + tmp.C / 3;
            C1 = tmp.A / 3 + 2 * tmp.C / 3;
            B1 = 2 * tmp.B / 3 + tmp.D / 3;
            D1 = tmp.B / 3 + 2 * tmp.D / 3;

            int x1 = A1, y1 = B1, x2 = C1, y2 = D1;

            int miny = std::min(y1, y2);
            int maxy = std::max(y1, y2);

            for (int i = miny; i < maxy; i++) {
                painter.drawLine(x1, i, x2, i);
            }

            stck.push({C1, D1, tmp.C, tmp.D, tmp.n - 1});
            stck.push({A1, D1, C1, tmp.D, tmp.n - 1});
            stck.push({tmp.A, D1, A1, tmp.D, tmp.n - 1});
            stck.push({C1, B1, tmp.C, D1, tmp.n - 1});
            stck.push({tmp.A, B1, A1, D1, tmp.n - 1});
            stck.push({C1, tmp.B, tmp.C, B1, tmp.n - 1});
            stck.push({A1, tmp.B, C1, B1, tmp.n - 1});
            stck.push({tmp.A, tmp.B, A1, B1, tmp.n - 1});
        }
    }
}

void paintwidget::kov(QPainter &painter, double A, double B, double C, double D, int n)
{
    if (delay) {
        QTime end = QTime::currentTime().addMSecs(1);
        while(QTime::currentTime() < end)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);
        repaint();
    }

    draw_rect(painter, A, B, C, D);

    double A1, B1, C1, D1;
           if(n > 0) {
              A1 = 2 * A / 3 + C / 3;
              C1 = A / 3 + 2 * C / 3;
              B1 = 2 * B / 3 + D / 3;
              D1 = B / 3 + 2 * D / 3;

              int x1 = A1, y1 = B1, x2 = C1, y2 = D1;
              //painter.drawRect(A1, B1, C1, D1);


              int miny = std::min(y1, y2);
              int maxy = std::max(y1, y2);

              for (int i = miny; i < maxy; i++) {
                  painter.drawLine(x1, i, x2, i);
              }

              kov(painter, A, B, A1, B1, n-1);
              kov(painter, A1, B, C1, B1, n-1);
              kov(painter, C1, B, C, B1, n-1);
              kov(painter, A, B1, A1, D1, n-1);
              kov(painter, C1, B1, C, D1, n-1);
              kov(painter, A, D1, A1, D, n-1);
              kov(painter, A1, D1, C1, D, n-1);
              kov(painter, C1, D1, C, D, n-1);
           }
}

void draw_rect(QPainter &painter, double x1, double y1, double x2, double y2)
{
    painter.drawLine(x1, y1, x2, y1);
    painter.drawLine(x1, y2, x2, y2);
    painter.drawLine(x1, y1, x1, y2);
    painter.drawLine(x2, y1, x2, y2);
}

void paintwidget::draw_fractal()
{
    double x1 = 20, y1 = 20;
    double x2 = 580, y2 = 580;

    QPainter painter(&my_image);
    QPen pen1(QColor(144, 0, 32));
    painter.setPen(pen1);

    nkov(painter, x1, y1, x2, y2, 5);

    this->repaint();
    painter.end();

}

void paintwidget::draw_fractal_rec()
{
    double x1 = 20, y1 = 20;
    double x2 = 580, y2 = 580;

    QPainter painter(&my_image);
    QPen pen(QColor(0, 49, 83));
    painter.setPen(pen);

    kov(painter, x1, y1, x2, y2, 5);

    this->repaint();
    painter.end();
}

void paintwidget::clear()
{
    QPainter painter(&my_image);
    QPen pen(QColor(255, 255, 255));
    painter.setPen(pen);
    for (int i = 0; i < 600; i++) {
        painter.drawLine(0, i, 640, i);
    }

    this->repaint();
    painter.end();
}

void paintwidget::set_delay()
{
    delay = 1;
}

void paintwidget::reset_delay()
{
    delay = 0;
}

unsigned long long paintwidget::test()
{
    reset_delay();

    unsigned long int tb, te;
    unsigned long int answer = 0;

    double x1 = 20, y1 = 20;
    double x2 = 580, y2 = 580;

    QPainter painter(&my_image);

    for (int i = 0; i < 10; i++) {
        tb = tick();
        nkov(painter, x1, y1, x2, y2, 5);
        te = tick();
        answer += (te - tb)/10;
    }

    this->repaint();
    painter.end();
    clear();
    return answer;
}

unsigned long long paintwidget::test_rec()
{
    reset_delay();

    unsigned long int tb, te;
    unsigned long int answer = 0;

    double x1 = 20, y1 = 20;
    double x2 = 580, y2 = 580;

    QPainter painter(&my_image);

    for (int i = 0; i < 10; i++) {
        tb = tick();
        kov(painter, x1, y1, x2, y2, 5);
        te = tick();
        answer += (te - tb)/10;
    }

    this->repaint();
    painter.end();

    clear();

    return (te - tb);
}

void paintwidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0, 0, my_image);
}
