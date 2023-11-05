#include "paintscene.h"



PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{

}

PaintScene::~PaintScene()
{

}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    addEllipse(event->scenePos().x() -5,
               event->scenePos().y() -5,
               10,
               10,
               QPen(Qt::NoPen),
               QBrush(Qt::black));
    previousPoint = event->scenePos();
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(Qt::black,10,Qt::SolidLine,Qt::RoundCap));
    previousPoint = event->scenePos();
}
