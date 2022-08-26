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

    int stepHeight = ui->gV_field->height() / m_height;
    int stepWidth = ui->gV_field->width() / m_width;
    QPen pen(Qt::SolidLine);
    QBrush brush(QColor(255,255,255));
    for(int i = 0; i < m_height; i++)
    {
      for(int j = 0; j < m_width; j++)
      {
        QGraphicsItem *item = scene->addRect(QRect(j*stepWidth, i*stepHeight, stepWidth, stepHeight),pen, brush);
      }
    }
}
