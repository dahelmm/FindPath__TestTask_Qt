#ifndef FINDPATHWORKER_H
#define FINDPATHWORKER_H

#include <QObject>
#include <QPointF>

#include "customgraphicsitem.h"

class FindPathWorker : public QObject
{
  Q_OBJECT

  Q_PROPERTY(int stepWidth READ getStepWidth WRITE setStepWidth)
  Q_PROPERTY(int stepHeight READ getStepHeight WRITE setStepHeight)

public:
  explicit FindPathWorker(QObject *parent = nullptr);
  ~FindPathWorker();

  void process(QPointF p);

  int getStepWidth() const;
  int getStepHeight() const;

public slots:
  void setStepWidth(int stepWidth);
  void setStepHeight(int stepHeight);
  void setStartParameters(const QMultiMap<int, QMap<int,CustomGraphicsItem*>> &itemsScene);

private:

  int m_stepWidth;
  int m_stepHeight;
  QMultiMap<int, QMap<int,CustomGraphicsItem*>> m_itemsScene;
};

#endif // FINDPATHWORKER_H
