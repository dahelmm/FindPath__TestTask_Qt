#ifndef CUSTOMGRAPHICSSCENE_H
#define CUSTOMGRAPHICSSCENE_H

#include <QObject>
#include <QGraphicsScene>

class CustomGraphicsScene : public QGraphicsScene
{
  Q_OBJECT
public:
  explicit CustomGraphicsScene();
  ~CustomGraphicsScene();

signals:
  void choosePoint(QPointF);
protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // CUSTOMGRAPHICSSCENE_H
