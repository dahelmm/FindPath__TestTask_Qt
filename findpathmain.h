#ifndef FINDPATHMAIN_H
#define FINDPATHMAIN_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QMap>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class FindPathMain; }
QT_END_NAMESPACE

class FindPathMain : public QMainWindow
{
  Q_OBJECT

public:
  explicit FindPathMain(QWidget *parent = nullptr);
  ~FindPathMain();

private slots:
  void on_pB_generate_clicked();

private:
  void randFillFields(int width, int height);
private:
  Ui::FindPathMain *ui;
  QGraphicsScene *scene;

  QMultiMap<int, QMap<int,QGraphicsRectItem*>> m_itemsScene;
  int m_width;
  int m_height;

};
#endif // FINDPATHMAIN_H
