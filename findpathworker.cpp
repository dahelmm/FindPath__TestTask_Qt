#include "findpathworker.h"

#include <QMessageBox>
#include <QDebug>


FindPathWorker::FindPathWorker(QObject *parent) :
  QObject(parent),
  m_stepWidth(0),
  m_stepHeight(0)
{
  m_queue.clear();
  m_path.clear();
  m_viewed.clear();
}

FindPathWorker::~FindPathWorker()
{
  qRegisterMetaType<QList<CustomGraphicsItem*>>();

}



void FindPathWorker::findPath()
{
  if(m_startItem == m_finishItem)
  {
    emit findPathFinishedOnePoint();
    return;
  }
  m_queue.append(m_startItem);
  QVector<int> neighbors;
  while(!m_queue.isEmpty())
  {
    QThread::msleep(50);
    qApp->processEvents();
    neighbors.clear();
    CustomGraphicsItem * itemTmp = m_queue.dequeue();
    if(itemTmp == m_finishItem)
    {
      helpFunction(itemTmp);
      return;
    }
    neighbors = itemTmp->getNeighbors();
    for(int i =0; i<neighbors.count(); i++)
    {
      CustomGraphicsItem *item = m_itemsScene.value(neighbors[i]);
      if(!m_viewed.contains(item) && !m_queue.contains(item))
      {
        item->setParentInGraph(itemTmp->getNumber());
        m_fillFields.append(item);
        item->setBrush(QColor(Qt::blue));
        m_queue.enqueue(item);
      }
    }

    m_viewed.append(itemTmp);
  }
  emit findError();
}

void FindPathWorker::helpFunction(CustomGraphicsItem * currentItem)
{
  if(currentItem->getParentInGraph() != m_startItem->getNumber())
  {
    m_path.append(m_itemsScene.value(currentItem->getParentInGraph()));
    helpFunction(m_itemsScene.value(currentItem->getParentInGraph()));
  }
  else
  {
    emit clearBlueFields(m_fillFields);
    emit findPathFinished(m_path);
  }
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

void FindPathWorker::setStartParameters(QMap<int, CustomGraphicsItem *> &items, CustomGraphicsItem *start, CustomGraphicsItem *finish)
{
  m_itemsScene = items;
  m_startItem = start;
  m_finishItem = finish;
}


