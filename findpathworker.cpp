#include "findpathworker.h"

FindPathWorker::FindPathWorker(QObject *parent) :
  QObject(parent),
  m_stepWidth(0),
  m_stepHeight(0)
{
//  qRegisterMetaType<customTypeMultiMap>();

}

FindPathWorker::~FindPathWorker()
{

}

void FindPathWorker::process(QPointF p)
{

}

int FindPathWorker::getStepWidth() const
{
  return m_stepWidth;
}

int FindPathWorker::getStepHeight() const
{
  return m_stepHeight;
}

void FindPathWorker::setStepWidth(int stepWidth)
{
  m_stepWidth = stepWidth;
}

void FindPathWorker::setStepHeight(int stepHeight)
{
  m_stepHeight = stepHeight;
}

void FindPathWorker::setStartParameters(const QMultiMap<int, QMap<int,CustomGraphicsItem*>> &itemsScene)
{
  m_itemsScene = itemsScene;
}

