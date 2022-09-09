#ifndef FINDPATHWORKER_H
#define FINDPATHWORKER_H

#include <QObject>
#include <QPointF>
#include <QQueue>
#include <QStack>
#include <QThread>
#include <QApplication>

#include "customgraphicsitem.h"

class FindPathWorker : public QObject
{
  Q_OBJECT

  Q_PROPERTY(int stepWidth READ getStepWidth WRITE setStepWidth)
  Q_PROPERTY(int stepHeight READ getStepHeight WRITE setStepHeight)

signals:
  void findPathFinished(const QList<CustomGraphicsItem*>&);
  void clearBlueFields(const QList<CustomGraphicsItem*>&);
  void findError();
  void findPathFinishedOnePoint();
  void started();
  void finished();

public:
  explicit FindPathWorker(QObject *parent = nullptr);
  ~FindPathWorker();
  int getStepWidth() const;
  int getStepHeight() const;

public slots:
  void findPath();
  void process();
  void start() { process(); }
  void exec() { m_running = true; emit started(); }
  void quit();
  bool isRunning() { return m_running; }
  void setStepWidth(int stepWidth);
  void setStepHeight(int stepHeight);
  void setStartParameters(QMap<int, CustomGraphicsItem *> &items, CustomGraphicsItem *start, CustomGraphicsItem *finish);

private:
  void helpFunction(CustomGraphicsItem *finishItem);

  CustomGraphicsItem *m_startItem;
  CustomGraphicsItem *m_finishItem;

  QQueue <CustomGraphicsItem*> m_queue;
  QList<CustomGraphicsItem*> m_viewed;
  QList<CustomGraphicsItem*> m_path;

  QList<CustomGraphicsItem*> m_fillFields;

  QQueue<int> m_queueInt;
  QList<int> m_viewedInt;
  QList<int> m_pathInt;

  int m_stepWidth;
  int m_stepHeight;
  QMap<int,CustomGraphicsItem*> m_itemsScene;

  bool m_running;
};

#endif // FINDPATHWORKER_H
