#include "findpathmain.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  FindPathMain w;
  w.show();
  return a.exec();
}
