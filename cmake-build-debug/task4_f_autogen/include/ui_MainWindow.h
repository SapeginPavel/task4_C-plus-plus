/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionactionOpen;
    QPushButton *loadGraphButton;
    QGraphicsView *graphicsViewForLoadedGraph;
    QGraphicsView *graphicsViewForSpanningTree;
    QPushButton *findSpanningTreeButton;
    QPushButton *saveSpanningTreeButton;
    QPushButton *resetGraphsButton;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1203, 663);
        actionactionOpen = new QAction(MainWindow);
        actionactionOpen->setObjectName(QString::fromUtf8("actionactionOpen"));
        actionactionOpen->setCheckable(true);
        loadGraphButton = new QPushButton(MainWindow);
        loadGraphButton->setObjectName(QString::fromUtf8("loadGraphButton"));
        loadGraphButton->setGeometry(QRect(10, 10, 131, 28));
        graphicsViewForLoadedGraph = new QGraphicsView(MainWindow);
        graphicsViewForLoadedGraph->setObjectName(QString::fromUtf8("graphicsViewForLoadedGraph"));
        graphicsViewForLoadedGraph->setGeometry(QRect(10, 60, 581, 531));
        graphicsViewForSpanningTree = new QGraphicsView(MainWindow);
        graphicsViewForSpanningTree->setObjectName(QString::fromUtf8("graphicsViewForSpanningTree"));
        graphicsViewForSpanningTree->setGeometry(QRect(610, 60, 581, 531));
        findSpanningTreeButton = new QPushButton(MainWindow);
        findSpanningTreeButton->setObjectName(QString::fromUtf8("findSpanningTreeButton"));
        findSpanningTreeButton->setGeometry(QRect(160, 10, 151, 28));
        saveSpanningTreeButton = new QPushButton(MainWindow);
        saveSpanningTreeButton->setObjectName(QString::fromUtf8("saveSpanningTreeButton"));
        saveSpanningTreeButton->setGeometry(QRect(330, 10, 131, 28));
        resetGraphsButton = new QPushButton(MainWindow);
        resetGraphsButton->setObjectName(QString::fromUtf8("resetGraphsButton"));
        resetGraphsButton->setGeometry(QRect(480, 10, 121, 28));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionactionOpen->setText(QCoreApplication::translate("MainWindow", "actionOpen", nullptr));
#if QT_CONFIG(tooltip)
        actionactionOpen->setToolTip(QCoreApplication::translate("MainWindow", "actionOpen", nullptr));
#endif // QT_CONFIG(tooltip)
        loadGraphButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\263\321\200\320\260\321\204", nullptr));
        findSpanningTreeButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\276\321\201\321\202\320\276\320\262\320\275\320\276\320\265 \320\264\320\265\321\200\320\265\320\262\320\276", nullptr));
        saveSpanningTreeButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\264\320\265\321\200\320\265\320\262\320\276", nullptr));
        resetGraphsButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201\320\270\321\202\321\214 \320\263\321\200\320\260\321\204\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
