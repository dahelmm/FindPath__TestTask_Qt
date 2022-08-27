#include "customgraphicsitem.h"

CustomGraphicsItem::CustomGraphicsItem(QObject *parent) :
  QObject(parent),
  QGraphicsRectItem(),
  m_obstacle(false)
{

}

CustomGraphicsItem::~CustomGraphicsItem()
{

}

bool CustomGraphicsItem::getObstacle() const
{
  return m_obstacle;
}

void CustomGraphicsItem::setObstacle(bool obstacle)
{
  m_obstacle = obstacle;
}
