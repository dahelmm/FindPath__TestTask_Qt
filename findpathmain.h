#ifndef FINDPATHMAIN_H
#define FINDPATHMAIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class FindPathMain; }
QT_END_NAMESPACE

class FindPathMain : public QMainWindow
{
  Q_OBJECT

public:
  FindPathMain(QWidget *parent = nullptr);
  ~FindPathMain();

private:
  Ui::FindPathMain *ui;
};
#endif // FINDPATHMAIN_H
