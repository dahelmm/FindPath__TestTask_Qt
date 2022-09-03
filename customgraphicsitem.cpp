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

QVector<int> CustomGraphicsItem::getNeighbors() const
{
  return m_neighbors;
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

void CustomGraphicsItem::setNeighbors(QVector<int> neighbors)
{
  m_neighbors = neighbors;
}

void CustomGraphicsItem::setParentInGraph(int parentInGraph)
{
  m_parentInGraph = parentInGraph;
}



