#include "paintscene.h"

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent) {
  this->setBackgroundBrush(QBrush(QColor(0, 0, 0)));
}

PaintScene::~PaintScene() {}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  addEllipse(event->scenePos().x() - 30, event->scenePos().y() - 30, 60, 60,
             QPen(Qt::white, 0, Qt::SolidLine, Qt::RoundCap),
             QBrush(Qt::white));
  previousPoint = event->scenePos();
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
  addLine(previousPoint.x(), previousPoint.y(), event->scenePos().x(),
          event->scenePos().y(),
          QPen(Qt::white, 60, Qt::SolidLine, Qt::RoundCap));
  previousPoint = event->scenePos();
}
