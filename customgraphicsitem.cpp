#include "customgraphicsitem.h"

CustomGraphicsItem::CustomGraphicsItem(QObject *parent) :
  QObject(parent),
  QGraphicsRectItem(),
  m_obstacle(false),
  m_isStart(false),
  m_isFinish(false),
  m_visited(false)
{

}

CustomGraphicsItem::~CustomGraphicsItem()
{

}

bool CustomGraphicsItem::getObstacle() const
{
  return m_obstacle;
}

bool CustomGraphicsItem::getIsStart() const
{
  return m_isStart;
}

bool CustomGraphicsItem::getIsFinish() const
{
  return m_isFinish;
}

QPointF CustomGraphicsItem::getPointStart() const
{
  return m_pointStart;
}

QPointF CustomGraphicsItem::getPointFinish() const
{
  return m_pointFinish;
}

bool CustomGraphicsItem::getVisited() const
{
  return m_visited;
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

void CustomGraphicsItem::setIsStart(bool isStart)
{
  m_isStart = isStart;
}

void CustomGraphicsItem::setIsFinish(bool isFinish)
{
  m_isFinish = isFinish;
}

void CustomGraphicsItem::setPointStart(QPointF pointStart)
{
  m_pointStart = pointStart;
}

void CustomGraphicsItem::setPointFinish(QPointF pointFinish)
{
  m_pointFinish = pointFinish;
}

void CustomGraphicsItem::setVisited(bool visited)
{
  m_visited = visited;
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



