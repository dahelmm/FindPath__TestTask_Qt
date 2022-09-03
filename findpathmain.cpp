#include "findpathmain.h"
#include "ui_findpathmain.h"

#include <QMessageBox>
#include <QGraphicsSimpleTextItem>


FindPathMain::FindPathMain(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::FindPathMain)
  , m_width(0)
  , m_height(0)
  , m_pointStartExists(false)
  , m_pointFinishExists(false)
{
  qRegisterMetaType<QList<CustomGraphicsItem*>>();
  ui->setupUi(this);
  scene = new CustomGraphicsScene();
  ui->gV_field->setScene(scene);
  connect(scene, &CustomGraphicsScene::choosePoint, this, &FindPathMain::choosePoint);
}

FindPathMain::~FindPathMain()
{
  delete scene;
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
  CustomGraphicsItem *item;
  scene->clear();
  m_itemsScene.clear();
  m_pointStartExists = false;
  m_pointFinishExists = false;
  m_stepHeight = ui->gV_field->height() / m_height;
  m_stepWidth = ui->gV_field->width() / m_width;
  QPen pen(Qt::SolidLine);
  QBrush brush(QColor(255,255,255));
  for(int i = 0; i < m_height; i++)
  {
    for(int j = 0; j < m_width; j++)
    {
      item = new CustomGraphicsItem;
      item->setRect(j*m_stepWidth, i*m_stepHeight, m_stepWidth, m_stepHeight);
      item->setNumber((i*m_width)+(j+1));
      item->setObstacle(false);
      rowItems.insert(j, item);
      m_mapItemsScene.insert((i*m_width)+(j+1), item);
      scene->addItem(item);
    }
    m_itemsScene.insert(i,rowItems);
  }
  randFillFields(m_width,m_height);
  fillSosedi();
}

void FindPathMain::randFillFields(int width, int height)
{
  int countSquare = (width + height)*4;
  QPen pen(Qt::SolidLine);

  for(int i = 0; i < countSquare; i++)
  {
    CustomGraphicsItem *item = m_itemsScene.value(rand()%m_height).value(rand()%m_width);
    item->setObstacle(true);
    item->setBrush(QColor(155,155,155));
  }
}

//функция для создания графа из заполненного поля. Создана мной, не оптимизированна. Сделана по принципу "лишь бы работало"
void FindPathMain::fillSosedi()
{
  CustomGraphicsItem *itemUP;
  CustomGraphicsItem *itemLeft;
  CustomGraphicsItem *itemRight;
  CustomGraphicsItem *itemDown;
  QVector<int> neighbors;

  for(int i = 0; i < m_height; i++)
  {
    for(int j = 0; j < m_width; j++)
    {
      CustomGraphicsItem *item = m_itemsScene.value(i).value(j);
      neighbors.clear();

      if(item->getObstacle())
        continue;
      if(j != m_width-1)
        itemRight = m_itemsScene.value(i).value(j+1);
      if(j != 0)
        itemLeft = m_itemsScene.value(i).value(j-1);
      if(i != m_height-1)
        itemDown = m_itemsScene.value(i+1).value(j);
      if(i != 0)
        itemUP = m_itemsScene.value(i-1).value(j);

      if(i==0)
      {
        if(j==0)
        {
          if(!itemRight->getObstacle())
            neighbors.append(itemRight->getNumber());
          if(!itemDown->getObstacle())
            neighbors.append(itemDown->getNumber());
          item->setNeighbors(neighbors);
          continue;
        }
        if(j != m_width-1)
        {
          if(!itemRight->getObstacle())
            neighbors.append(itemRight->getNumber());
          if(!itemDown->getObstacle())
            neighbors.append(itemDown->getNumber());
          if(!itemLeft->getObstacle())
            neighbors.append(itemLeft->getNumber());
          item->setNeighbors(neighbors);
          continue;
        }
        if(!itemDown->getObstacle())
          neighbors.append(itemDown->getNumber());
        if(!itemLeft->getObstacle())
          neighbors.append(itemLeft->getNumber());
        item->setNeighbors(neighbors);
        continue;
      }
      else
      {
        if(i != m_height-1)
        {
          if(j == 0)
          {
            if(!itemRight->getObstacle())
              neighbors.append(itemRight->getNumber());
            if(!itemDown->getObstacle())
              neighbors.append(itemDown->getNumber());
            if(!itemUP->getObstacle())
              neighbors.append(itemUP->getNumber());
            item->setNeighbors(neighbors);
            continue;
          }
          if(j == m_width - 1)
          {
            if(!itemLeft->getObstacle())
              neighbors.append(itemLeft->getNumber());
            if(!itemDown->getObstacle())
              neighbors.append(itemDown->getNumber());
            if(!itemUP->getObstacle())
              neighbors.append(itemUP->getNumber());
            item->setNeighbors(neighbors);
            continue;
          }
          if(!itemRight->getObstacle())
            neighbors.append(itemRight->getNumber());
          if(!itemDown->getObstacle())
            neighbors.append(itemDown->getNumber());
          if(!itemLeft->getObstacle())
            neighbors.append(itemLeft->getNumber());
          if(!itemUP->getObstacle())
            neighbors.append(itemUP->getNumber());
          item->setNeighbors(neighbors);
          continue;
        }
        else
        {
          if(j == 0)
          {
            if(!itemRight->getObstacle())
              neighbors.append(itemRight->getNumber());
            if(!itemUP->getObstacle())
              neighbors.append(itemUP->getNumber());
            item->setNeighbors(neighbors);
            continue;
          }
          if(j == m_width - 1)
          {
            if(!itemLeft->getObstacle())
              neighbors.append(itemLeft->getNumber());
            if(!itemUP->getObstacle())
              neighbors.append(itemUP->getNumber());
            item->setNeighbors(neighbors);
            continue;
          }
          if(!itemRight->getObstacle())
            neighbors.append(itemRight->getNumber());
          if(!itemLeft->getObstacle())
            neighbors.append(itemLeft->getNumber());
          if(!itemUP->getObstacle())
            neighbors.append(itemUP->getNumber());
          item->setNeighbors(neighbors);
          continue;
        }
      }
    }
  }
}

void FindPathMain::on_pB_findPath_clicked()
{
  threadWorker = new QThread(this);
  worker = new FindPathWorker;
  worker->setStartParameters(m_mapItemsScene, m_startField, m_finishField);
  worker->moveToThread(threadWorker);

  connect(threadWorker, &QThread::started, worker, &FindPathWorker::findPath);
  connect(worker, &FindPathWorker::findError, this, &FindPathMain::findError);
  connect(worker, &FindPathWorker::findPathFinishedOnePoint, this, &FindPathMain::findPathFinishedOnePoint);
  connect(worker, &FindPathWorker::findPathFinished, this, &FindPathMain::findParhFinished, Qt::QueuedConnection);
  connect(worker, &FindPathWorker::clearBlueFields, this, &FindPathMain::clearBlueFields);
  connect(worker, &FindPathWorker::findPathFinished, threadWorker, &QThread::terminate);
  connect(worker, &FindPathWorker::findPathFinished, threadWorker, &QThread::deleteLater);
  connect(worker, &FindPathWorker::findPathFinished, worker, &FindPathWorker::deleteLater);

  connect(worker, &FindPathWorker::findError, threadWorker, &QThread::quit);
  connect(worker, &FindPathWorker::findError, threadWorker, &QThread::deleteLater);
  connect(worker, &FindPathWorker::findError, worker, &FindPathWorker::deleteLater);

  connect(worker, &FindPathWorker::findPathFinishedOnePoint, threadWorker, &QThread::terminate);
  connect(worker, &FindPathWorker::findPathFinishedOnePoint, threadWorker, &QThread::deleteLater);
  connect(worker, &FindPathWorker::findPathFinishedOnePoint, worker, &FindPathWorker::deleteLater);
  threadWorker->start();
}

void FindPathMain::choosePoint(QPointF point)
{
  CustomGraphicsItem *item = m_itemsScene.value(point.y()/m_stepHeight).value(point.x()/m_stepWidth);
  if(item->getObstacle())
  {
    QMessageBox::critical(this, "Ошибка", "Недопустимая точка, выберите другую");
    return;
  }
  if(!m_pointStartExists)
  {
    m_pointStartExists = true;
    m_startField = item;
    item->setBrush(QColor(255,221,30));
    QGraphicsTextItem *textItem = scene->addText(tr("Начало"));
    textItem->setPos(item->rect().bottomRight());
  }
  else if(!m_pointFinishExists)
  {
    m_pointFinishExists = true;
    m_finishField = item;
    item->setBrush(QColor(216,116,252));
    QGraphicsTextItem *textItem = scene->addText(tr("Конец"));
    textItem->setPos(item->rect().bottomRight());
  }
  else
  {
    QMessageBox::information(this, "Ошибка", "Все точки заданы, нажмите \"Найти путь\"");
  }
}

void FindPathMain::findParhFinished(const QList<CustomGraphicsItem *> &data)
{
  foreach(auto*item, data)
  {
    item->setBrush(QColor(Qt::red));
  }
  m_startField->setBrush(QColor(255,221,30));
  m_finishField->setBrush(QColor(216,116,252));
}

void FindPathMain::findError()
{
  QMessageBox::critical(this, "Ошибка", "Не найден путь");
}

void FindPathMain::clearBlueFields(const QList<CustomGraphicsItem *> &data)
{
  foreach(auto*item, data)
  {
    item->setBrush(QColor(Qt::white));
  }
}

void FindPathMain::findPathFinishedOnePoint()
{
  QMessageBox::information(this, "Конец", "Точка конца отрезка в точке старта, путь найден");
}

