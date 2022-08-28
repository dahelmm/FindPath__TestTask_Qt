#ifndef FINDPATHWORKER_H
#define FINDPATHWORKER_H

#include <QObject>
#include <QPointF>
#include <QQueue>

#include "customgraphicsitem.h"

class FindPathWorker : public QObject
{
  Q_OBJECT

  Q_PROPERTY(int stepWidth READ getStepWidth WRITE setStepWidth)
  Q_PROPERTY(int stepHeight READ getStepHeight WRITE setStepHeight)

signals:
  void findPathFinished(int);

private:
  void findPath();
  void DFS();
public:
  explicit FindPathWorker(QObject *parent = nullptr);
  ~FindPathWorker();

  void process();

  int getStepWidth() const;
  int getStepHeight() const;

public slots:
  void setStepWidth(int stepWidth);
  void setStepHeight(int stepHeight);
  void setStartParameters(const QMultiMap<int, QMap<int,CustomGraphicsItem*>> &itemsScene);

private:
  CustomGraphicsItem *m_startItem;
  CustomGraphicsItem *m_finishItem;
  QQueue<CustomGraphicsItem*> m_queue;

  QList<CustomGraphicsItem*> m_path;
  int m_stepWidth;
  int m_stepHeight;
  QMultiMap<int, QMap<int,CustomGraphicsItem*>> m_itemsScene;
};

#endif // FINDPATHWORKER_H
