#include "findpathmain.h"
#include "ui_findpathmain.h"

#include <QMessageBox>

FindPathMain::FindPathMain(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::FindPathMain)
  , m_width(0)
  , m_height(0)
  , m_pointStartExists(false)
  , m_pointFinishExists(false)
{
  ui->setupUi(this);
  scene = new CustomGraphicsScene();
  ui->gV_field->setScene(scene);
  connect(scene, &CustomGraphicsScene::choosePoint, this, &FindPathMain::choosePoint);
}

FindPathMain::~FindPathMain()
{
  delete ui;
}

void FindPathMain::on_pB_generate_clicked()
{
  QMap<int, CustomGraphicsItem*> rowItems;
  if(ui->lE_width->text().toUInt() && ui->lE_height->text().toUInt())
  {
    m_width = ui->lE_width->text().toUInt();
    m_height = ui->lE_height->text().toUInt();
  }
  else
  {
    QMessageBox::critical(this, "Ошибка", "Введите значения ширины и высоты");
    return;
  }
  scene->clear();
  m_itemsScene.clear();
  m_stepHeight = ui->gV_field->height() / m_height;
  m_stepWidth = ui->gV_field->width() / m_width;
  QPen pen(Qt::SolidLine);
  QBrush brush(QColor(255,255,255));
  for(int i = 0; i < m_height; i++)
  {
    for(int j = 0; j < m_width; j++)
    {

      CustomGraphicsItem *item = static_cast<CustomGraphicsItem*>(scene->addRect(QRect(j*m_stepWidth, i*m_stepHeight, m_stepWidth, m_stepHeight),pen, brush));
      item->setObstacle(false);
      rowItems.insert(j, item);
    }
    m_itemsScene.insert(i,rowItems);
  }
  randFillFields(m_width,m_height);

}

void FindPathMain::randFillFields(int width, int height)
{
  int countSquare = width + height;
  QPen pen(Qt::SolidLine);

  for(int i = 0; i < countSquare; i++)
  {
    CustomGraphicsItem *item = m_itemsScene.value(rand()%m_height).value(rand()%m_width);
    item->setObstacle(true);
    item->setBrush(QColor(155,155,155));
  }
}

void FindPathMain::on_pB_findPath_clicked()
{
  threadWorker = new QThread(this);
  worker = new FindPathWorker;
  worker->setStartParameters(m_itemsScene);
//  worker->moveToThread(threadWorker);
  //connect

  //  threadWorker->start();
}

void FindPathMain::choosePoint(QPointF point)
{
  if(!m_pointStartExists)
  {
    CustomGraphicsItem *item = m_itemsScene.value(point.y()/m_stepHeight).value(point.x()/m_stepWidth);
    if(item->getObstacle())
    {
      QMessageBox::critical(this, "Ошибка", "Недопустимая точка, выберите другую");
      return;
    }
    item->setBrush(QColor(Qt::red));
    m_pointStartExists = true;
  }
  else if(!m_pointFinishExists)
  {
    CustomGraphicsItem *item = m_itemsScene.value(point.y()/m_stepHeight).value(point.x()/m_stepWidth);
    if(item->getObstacle())
    {
      QMessageBox::critical(this, "Ошибка", "Недопустимая точка, выберите другую");
      return;
    }
    item->setBrush(QColor(153,56,0));
    m_pointFinishExists = true;
  }
  else
  {
    QMessageBox::information(this, "Ошибка", "Все точки заданы, нажмите \"Найти путь\"");
  }
}
