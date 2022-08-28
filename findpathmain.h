#ifndef FINDPATHMAIN_H
#define FINDPATHMAIN_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QMap>
#include <QVector>
#include <QThread>

#include "customgraphicsscene.h"
#include "customgraphicsitem.h"
#include "findpathworker.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FindPathMain; }
QT_END_NAMESPACE

class FindPathMain : public QMainWindow
{
  Q_OBJECT

public:
  explicit FindPathMain(QWidget *parent = nullptr);
  ~FindPathMain();

signals:

private slots:
  void on_pB_generate_clicked();
  void on_pB_findPath_clicked();
  void choosePoint(QPointF point);
  void findParhFinished(const QList<CustomGraphicsItem*>& data);


private:
  void randFillFields(int width, int height);
  void fillSosedi();

private:
  Ui::FindPathMain *ui;
//  QGraphicsScene *scene;
  CustomGraphicsScene *scene;
  FindPathWorker*worker;
  QThread *threadWorker;

  CustomGraphicsItem * m_startField;
  CustomGraphicsItem * m_finishField;

  QMultiMap<int, QMap<int,CustomGraphicsItem*>> m_itemsScene;
  QMap<int, CustomGraphicsItem*> m_mapItemsScene;
  int m_width;
  int m_height;

  int m_stepHeight;
  int m_stepWidth;

  bool m_pointStartExists;
  bool m_pointFinishExists;

};

#endif // FINDPATHMAIN_H
