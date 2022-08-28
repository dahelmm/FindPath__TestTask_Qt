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

int CustomGraphicsItem::getNumber() const
{
  return m_number;
}

QVector<int> CustomGraphicsItem::getSosedi() const
{
  return m_sosedi;
}

int CustomGraphicsItem::getParentInGraph() const
{
  return m_parentInGraph;
}



void CustomGraphicsItem::setObstacle(bool obstacle)
{
  m_obstacle = obstacle;
}

void CustomGraphicsItem::setNumber(int number)
{
  m_number = number;
}

void CustomGraphicsItem::setSosedi(QVector<int> sosedi)
{
  m_sosedi = sosedi;
}

void CustomGraphicsItem::setParentInGraph(int parentInGraph)
{
  m_parentInGraph = parentInGraph;
}



