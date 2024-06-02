//
// Created by user on 02.06.2024.
//

#ifndef TASK4_F_GRAPHWIDGET_H
#define TASK4_F_GRAPHWIDGET_H

#include <QGraphicsView>
#include <QMap>
#include <QList>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QGraphicsLineItem>


class GraphWidget : public QGraphicsView {
    Q_OBJECT

public:
    explicit GraphWidget(QWidget *parent = nullptr);
    void setGraph(const QMap<int, QList<int>> &graph, QGraphicsView *qGraphicsView);
    void resetDrawing();

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;

private:
    QGraphicsScene *scene;
    QMap<int, QGraphicsEllipseItem*> nodeItems;
    void drawGraph(QGraphicsView *qGraphicsView);
};


#endif //TASK4_F_GRAPHWIDGET_H
