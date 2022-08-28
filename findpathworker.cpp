#include "findpathworker.h"

#include <QMessageBox>

void FindPathWorker::findPath()
{
  if(m_startItem->getPointStart() == m_finishItem->getPointFinish())
  {
    emit findPathFinished(0);
    return;
  }
  QPointF start = m_startItem->getPointStart();
  QPointF finish = m_finishItem->getPointFinish();
  m_startItem->setVisited(true);
  m_path.append(m_startItem);
  int resX = start.x()-finish.x();
  int resY = start.y()-finish.y();
  if(start.x()>=0 && start.y()>=0)
  {

  }
  CustomGraphicsItem *itemTmp;
//  if(m_itemsScene.contains(start.y(),QMap<start.x(),value(start.y()).value(start.x()-1))
//  itemTmp = ;
  if(!itemTmp->getObstacle())
    m_queue.append(itemTmp);
}

void FindPathWorker::DFS()
{

}

FindPathWorker::FindPathWorker(QObject *parent) :
  QObject(parent),
  m_stepWidth(0),
  m_stepHeight(0)
{

}

FindPathWorker::~FindPathWorker()
{

}

void FindPathWorker::process()
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
  QMap<int, CustomGraphicsItem*> itemsTmp;
  for(int i = 0; i < itemsScene.values().count(); i++)
  {
    itemsTmp = itemsScene.value(i);
    for(int j = 0; j < itemsTmp.count(); j++)
    {
      if(itemsTmp.value(j)->getIsStart())
      {
        m_startItem = itemsTmp.value(j);
        m_startItem->setPointStart(QPointF(j, i));
      }
      if(itemsTmp.value(j)->getIsFinish())
      {
        m_finishItem= itemsTmp.value(j);
        m_finishItem->setPointFinish(QPointF(j, i));
      }
    }
  }
}

