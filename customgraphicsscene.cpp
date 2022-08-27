#include "customgraphicsscene.h"

#include <QGraphicsSceneMouseEvent>
#include <QDebug>

CustomGraphicsScene::CustomGraphicsScene() :
  QGraphicsScene()
{

}

CustomGraphicsScene::~CustomGraphicsScene()
{

}

void CustomGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  if(event->button() == Qt::LeftButton)
  {
    emit choosePoint(event->scenePos());
  }
}
