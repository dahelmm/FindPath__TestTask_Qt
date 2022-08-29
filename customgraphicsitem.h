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
  Q_PROPERTY(int number READ getNumber WRITE setNumber)
  Q_PROPERTY(QVector<int> neighbors READ getNeighbors WRITE setNeighbors)
  Q_PROPERTY(int parentInGraph READ getParentInGraph WRITE setParentInGraph)
public:
  explicit CustomGraphicsItem(QObject *parent = nullptr);
      ~CustomGraphicsItem();

  bool getObstacle() const;
  int getNumber() const;
  QVector<int> getNeighbors() const;
  int getParentInGraph() const;

public slots:
  void setObstacle(bool obstacle);
  void setNumber(int number);
  void setNeighbors(QVector<int> neighbors);
  void setParentInGraph(int parentInGraph);

private:

  bool m_obstacle;
  int m_number = 0;
  QVector<int> m_neighbors;

  int m_width;
  int m_height;
  int m_parentInGraph;
};

Q_DECLARE_METATYPE(QList<CustomGraphicsItem*>)

#endif // CUSTOMGRAPHICSITEM_H
