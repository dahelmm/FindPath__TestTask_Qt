#ifndef FINDPATHMAIN_H
#define FINDPATHMAIN_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class FindPathMain; }
QT_END_NAMESPACE

class FindPathMain : public QMainWindow
{
  Q_OBJECT

public:
  FindPathMain(QWidget *parent = nullptr);
  ~FindPathMain();

private slots:
  void on_pB_generate_clicked();

private:
  Ui::FindPathMain *ui;
  QGraphicsScene *scene;

  int m_width;
  int m_height;

};
#endif // FINDPATHMAIN_H
