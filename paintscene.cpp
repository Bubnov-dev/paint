#include "paintscene.h"
#include "paint.h"

paintScene::paintScene(QObject *parent) : QGraphicsScene(parent)
{

}

paintScene::~paintScene()
{

}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QBrush col;
    if (colour == "red"){
        col = QBrush (Qt::red);
    }
    if (colour == "green"){
        col = QBrush (Qt::green);
    }
    if (colour == "blue"){
        col = QBrush (Qt::blue);
    }
    addEllipse(event->scenePos().x() - 5,
               event->scenePos().y() - 5,
               10,
               10,
               QPen(Qt::NoPen),
               col);
    // Сохраняем координаты точки нажатия
    previousPoint = event->scenePos();
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QBrush col;
    if (colour == "red"){
        col = QBrush (Qt::red);
    }
    if (colour == "green"){
        col = QBrush (Qt::green);
    }
    if (colour == "blue"){
        col = QBrush (Qt::blue);
    }
{
    addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(col,10,Qt::SolidLine,Qt::RoundCap));
    // Обновляем данные о предыдущей координате
    previousPoint = event->scenePos();
     }


void paintScene::clrchng(QString lcolour){
    this->colour = lcolour;
    qDebug() << colour;
}
