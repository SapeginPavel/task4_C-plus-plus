//
// Created by user on 02.06.2024.
//

#include "GraphWidget.h"
#include "GraphWidget.h"
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>
#include <QPainter>
#include <cmath>
#include <valarray>

GraphWidget::GraphWidget(QWidget *parent)
        : QGraphicsView(parent), scene(new QGraphicsScene(this)) {
    setScene(scene);
}

void GraphWidget::setGraph(const QMap<int, QList<int>> &graph, QGraphicsView *qGraphicsView) {
    resetDrawing();

    int radius = 200;
    int nodeRadius = 20;
    int nodeCount = graph.size();
    int i = 0;
    for (int node : graph.keys()) {
        double angle = (2 * M_PI / nodeCount) * i;
        int x = radius * cos(angle);
        int y = radius * sin(angle);

        QGraphicsEllipseItem *ellipseItem = scene->addEllipse(x, y, nodeRadius*2, nodeRadius*2);
        QGraphicsTextItem *textItem = scene->addText(QString::number(node));

        QFont font = textItem->font();
        font.setPointSize(14);
        textItem->setFont(font);

        textItem->setPos(x + nodeRadius - textItem->boundingRect().width() / 2, y + nodeRadius - textItem->boundingRect().height() / 2);

        nodeItems[node] = ellipseItem;
        ++i;
    }

    for (int node : graph.keys()) {
        for (int neighbor : graph[node]) {
            if (nodeItems.contains(neighbor)) {
                QGraphicsLineItem *lineItem = scene->addLine(nodeItems[node]->rect().center().x(), nodeItems[node]->rect().center().y(),
                                                             nodeItems[neighbor]->rect().center().x(), nodeItems[neighbor]->rect().center().y());
            }
        }
    }
    drawGraph(qGraphicsView);
}

void GraphWidget::drawBackground(QPainter *painter, const QRectF &rect) {
    QGraphicsView::drawBackground(painter, rect);
}

void GraphWidget::drawGraph(QGraphicsView *qGraphicsView) {
    qGraphicsView->setScene(scene);
    scene->update();
}

void GraphWidget::resetDrawing() {
    scene->clear();
    nodeItems.clear();
}
