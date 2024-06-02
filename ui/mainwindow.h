//
// Created by user on 02.06.2024.
//

#ifndef TASK4_F_MAINWINDOW_H
#define TASK4_F_MAINWINDOW_H

#include <QWidget>
#include <iostream>
#include <string>
#include "GraphWidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    GraphWidget *graphWidget;
    GraphWidget *treeSpanningWidget;
    void readGraphFromFile(std::string fileName);
    void findSpanningTree();

private slots:
    void on_loadGraphButton_clicked();
    void findSpanningTreeClick();
    void resetGraphsClick();
    void saveSpanningTreeClick();
};


#endif //TASK4_F_MAINWINDOW_H
