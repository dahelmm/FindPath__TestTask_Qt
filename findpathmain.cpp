#include "findpathmain.h"
#include "ui_findpathmain.h"

FindPathMain::FindPathMain(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::FindPathMain)
{
  ui->setupUi(this);
}

FindPathMain::~FindPathMain()
{
  delete ui;
}

