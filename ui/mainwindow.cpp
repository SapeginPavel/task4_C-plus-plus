//
// Created by user on 02.06.2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include "GraphWidget.h"
#include <string>
#include <fstream>
#include <QFileDialog>
#include <QMessageBox>
#include <QMapIterator>
#include <QTextStream>
#include <queue>
#include <set>
#include <QList>
#include <regex>

QMap<int, QList<int>> graph;
QMap<int, QList<int>> spanningTree;

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QWidget(parent),
    ui(new Ui::MainWindow),
    graphWidget(new GraphWidget(this)),
    treeSpanningWidget(new GraphWidget(this))
{
    ui->setupUi(this);

    connect(ui->resetGraphsButton, SIGNAL(clicked()), this, SLOT(resetGraphsClick()));
    connect(ui->findSpanningTreeButton, SIGNAL(clicked()), this, SLOT(findSpanningTreeClick()));
    connect(ui->saveSpanningTreeButton, SIGNAL(clicked()), this, SLOT(saveSpanningTreeClick()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_loadGraphButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName();
    readGraphFromFile(fileName.toStdString());
}

void MainWindow::readGraphFromFile(std::string fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        QMessageBox::critical(this, tr("Ошибка"), tr("Невозможно открыть файл"));
        return;
    }

    graph.clear();

    string numV;
    getline(file, numV);
    int numVertices = stoi(numV);

    QString line;
    string lineStr;
    regex pattern("\\s\\n");

    for (int i = 0; i < numVertices; ++i) {
        getline(file, lineStr);
        lineStr = regex_replace(lineStr, pattern, "\n");
        line = QString::fromStdString(lineStr);

        QStringList parts = line.split(' ');

        int vertex = parts[0].toInt();
        QList<int> neighbors;

        for (int j = 1; j < parts.size(); ++j) {
            neighbors.append(parts[j].toInt());
        }

        graph[vertex] = neighbors;
    }

    graphWidget->setGraph(graph, ui->graphicsViewForLoadedGraph);
}

void MainWindow::findSpanningTree() {

    if (graph.empty()) {
        QMessageBox::critical(this, tr("Ошибка"), tr("Граф не был загружен"));
        return;
    }

    spanningTree.clear();

    std::set<int> visited;
    std::queue<int> toVisit;

    int startVertex = graph.firstKey();
    toVisit.push(startVertex);
    visited.insert(startVertex);

    while (!toVisit.empty()) {
        int current = toVisit.front();
        toVisit.pop();

        for (int neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                toVisit.push(neighbor);
                spanningTree[current].append(neighbor);
                spanningTree[neighbor].append(current);
            }
        }
    }

    treeSpanningWidget->setGraph(spanningTree, ui->graphicsViewForSpanningTree);
}


void MainWindow::findSpanningTreeClick() {
    findSpanningTree();
}

void MainWindow::resetGraphsClick() {
    graph.clear();
    spanningTree.clear();
    graphWidget->resetDrawing();
    if (treeSpanningWidget != nullptr) {
        treeSpanningWidget->resetDrawing();
    }
}

void MainWindow::saveSpanningTreeClick() {
    if (spanningTree.empty()) {
        QMessageBox::critical(this, tr("Ошибка"), tr("Остовное дерево ещё не было найдено"));
        return;
    }
    QString fileName = QFileDialog::getOpenFileName();
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, tr("Ошибка"), tr("Невозможно открыть файл"));
        return;
    }
    QTextStream out(&file);
    QMapIterator<int, QList<int>> it(spanningTree);
    out << spanningTree.count();
    out << Qt::endl;
    while (it.hasNext()) {
        it.next();
        out << it.key();

        const QList<int>& neighbors = it.value();
        for (int i = 0; i < neighbors.size(); ++i) {
            out << " " << neighbors[i];
        }

        if (it.hasNext()) {
            out << Qt::endl;
        }
    }
}
