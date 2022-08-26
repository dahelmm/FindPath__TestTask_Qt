#include "findpathmain.h"
#include "ui_findpathmain.h"

#include <QMessageBox>

FindPathMain::FindPathMain(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::FindPathMain)
  , m_width(0)
  , m_height(0)
{
  ui->setupUi(this);
  scene = new QGraphicsScene(this);
  ui->gV_field->setScene(scene);
}

FindPathMain::~FindPathMain()
{
  delete ui;
}


void FindPathMain::on_pB_generate_clicked()
{
  QMap<int, QGraphicsRectItem*> rowItems;
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
    int stepHeight = ui->gV_field->height() / m_height;
    int stepWidth = ui->gV_field->width() / m_width;
    QPen pen(Qt::SolidLine);
    QBrush brush(QColor(255,255,255));
    for(int i = 0; i < m_height; i++)
    {
      for(int j = 0; j < m_width; j++)
      {

        QGraphicsRectItem *item = scene->addRect(QRect(j*stepWidth, i*stepHeight, stepWidth, stepHeight),pen, brush);
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
    QGraphicsRectItem *item = m_itemsScene.value(rand()%m_height).value(rand()%m_width);
    item->setBrush(QColor(155,155,155));
  }




}


