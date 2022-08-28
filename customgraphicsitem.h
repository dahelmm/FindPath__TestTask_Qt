#ifndef CUSTOMGRAPHICSITEM_H
#define CUSTOMGRAPHICSITEM_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QQueue>
#include <QMetaType>

class CustomGraphicsItem : public QObject, public QGraphicsRectItem
{
  Q_OBJECT
  Q_PROPERTY(bool obstacle READ getObstacle WRITE setObstacle)
  Q_PROPERTY(bool isStart READ getIsStart WRITE setIsStart)
  Q_PROPERTY(bool isFinish READ getIsFinish WRITE setIsFinish)
  Q_PROPERTY(QPointF pointStart READ getPointStart WRITE setPointStart)
  Q_PROPERTY(QPointF pointFinish READ getPointFinish WRITE setPointFinish)
  Q_PROPERTY(bool visited READ getVisited WRITE setVisited)
  Q_PROPERTY(int number READ getNumber WRITE setNumber)
  Q_PROPERTY(QVector<int> sosedi READ getSosedi WRITE setSosedi)
public:
  explicit CustomGraphicsItem(QObject *parent = nullptr);
      ~CustomGraphicsItem();

  bool getObstacle() const;
  bool getIsStart() const;
  bool getIsFinish() const;
  QPointF getPointStart() const;
  QPointF getPointFinish() const;
  bool getVisited() const;
  int getNumber() const;
  QVector<int> getSosedi() const;

public slots:
  void setObstacle(bool obstacle);
  void setIsStart(bool isStart);
  void setIsFinish(bool isFinish);
  void setPointStart(QPointF pointStart);
  void setPointFinish(QPointF pointFinish);
  void setVisited(bool visited);
  void setNumber(int number);
  void setSosedi(QVector<int> sosedi);

private:

  bool m_obstacle;
  bool m_isStart;
  bool m_isFinish;
  QPointF m_pointStart;
  QPointF m_pointFinish;
  bool m_visited;
  QList<CustomGraphicsItem*> m_neighbors;
  int m_number = 0;
  QVector<int> m_sosedi;

  int m_width;
  int m_height;
};


#endif // CUSTOMGRAPHICSITEM_H
