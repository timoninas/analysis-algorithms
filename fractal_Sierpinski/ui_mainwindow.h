/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *draw_widget;
    QPushButton *buttonFractalRec;
    QPushButton *buttonClear;
    QPushButton *buttonFractal;
    QPushButton *buttonSetDelay;
    QPushButton *buttonResetDelay;
    QPushButton *buttonTestFractal;
    QPushButton *buttonTestFractalRec;
    QLabel *test;
    QLabel *testRec;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(950, 620);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        draw_widget = new QWidget(centralWidget);
        draw_widget->setObjectName(QString::fromUtf8("draw_widget"));
        draw_widget->setGeometry(QRect(10, 10, 640, 600));
        buttonFractalRec = new QPushButton(centralWidget);
        buttonFractalRec->setObjectName(QString::fromUtf8("buttonFractalRec"));
        buttonFractalRec->setGeometry(QRect(660, 260, 121, 41));
        buttonClear = new QPushButton(centralWidget);
        buttonClear->setObjectName(QString::fromUtf8("buttonClear"));
        buttonClear->setGeometry(QRect(660, 310, 161, 41));
        buttonFractal = new QPushButton(centralWidget);
        buttonFractal->setObjectName(QString::fromUtf8("buttonFractal"));
        buttonFractal->setGeometry(QRect(660, 210, 121, 41));
        buttonSetDelay = new QPushButton(centralWidget);
        buttonSetDelay->setObjectName(QString::fromUtf8("buttonSetDelay"));
        buttonSetDelay->setGeometry(QRect(780, 210, 101, 41));
        QFont font;
        font.setPointSize(10);
        buttonSetDelay->setFont(font);
        buttonResetDelay = new QPushButton(centralWidget);
        buttonResetDelay->setObjectName(QString::fromUtf8("buttonResetDelay"));
        buttonResetDelay->setGeometry(QRect(780, 260, 101, 41));
        buttonResetDelay->setFont(font);
        buttonTestFractal = new QPushButton(centralWidget);
        buttonTestFractal->setObjectName(QString::fromUtf8("buttonTestFractal"));
        buttonTestFractal->setGeometry(QRect(880, 210, 61, 41));
        buttonTestFractal->setFont(font);
        buttonTestFractalRec = new QPushButton(centralWidget);
        buttonTestFractalRec->setObjectName(QString::fromUtf8("buttonTestFractalRec"));
        buttonTestFractalRec->setGeometry(QRect(880, 260, 61, 41));
        buttonTestFractalRec->setFont(font);
        test = new QLabel(centralWidget);
        test->setObjectName(QString::fromUtf8("test"));
        test->setGeometry(QRect(830, 180, 101, 31));
        testRec = new QLabel(centralWidget);
        testRec->setObjectName(QString::fromUtf8("testRec"));
        testRec->setGeometry(QRect(830, 310, 101, 31));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        buttonFractalRec->setText(QApplication::translate("MainWindow", "\321\204\321\200\320\260\320\272\321\202\320\260\320\273 \321\200\320\265\320\272.", nullptr));
        buttonClear->setText(QApplication::translate("MainWindow", "\320\276\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        buttonFractal->setText(QApplication::translate("MainWindow", "\321\204\321\200\320\260\320\272\321\202\320\260\320\273", nullptr));
        buttonSetDelay->setText(QApplication::translate("MainWindow", "\321\203\321\201\321\202. \320\267\320\260\320\264\320\265\321\200\320\266\320\272\321\203", nullptr));
        buttonResetDelay->setText(QApplication::translate("MainWindow", "\321\201\320\261\321\200. \320\267\320\260\320\264\320\265\321\200\320\266\320\272\321\203", nullptr));
        buttonTestFractal->setText(QApplication::translate("MainWindow", "\321\202\320\265\321\201\321\202", nullptr));
        buttonTestFractalRec->setText(QApplication::translate("MainWindow", "\321\202\320\265\321\201\321\202", nullptr));
        test->setText(QString());
        testRec->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
