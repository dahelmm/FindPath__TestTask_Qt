#ifndef CUSTOMGRAPHICSITEM_H
#define CUSTOMGRAPHICSITEM_H

#include <QObject>
#include <QGraphicsRectItem>

#include <QMetaType>

class CustomGraphicsItem : public QObject, public QGraphicsRectItem
{
  Q_OBJECT
  Q_PROPERTY(bool obstacle READ getObstacle WRITE setObstacle)
public:
  explicit CustomGraphicsItem(QObject *parent = nullptr);
      ~CustomGraphicsItem();


  bool getObstacle() const;

public slots:
  void setObstacle(bool obstacle);

private:
  bool m_obstacle;
};
//typedef QMultiMap<int, QMap<int, CustomGraphicsItem*>> customTypeMultiMap;

//Q_DECLARE_METATYPE(customTypeMultiMap);

#endif // CUSTOMGRAPHICSITEM_H
