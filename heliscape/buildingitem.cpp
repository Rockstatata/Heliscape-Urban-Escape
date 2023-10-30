#include "buildingitem.h"
#include <QRandomGenerator>
#include <QGraphicsScene>
#include "scene.h"
#include "heliitem.h"

BuildingItem::BuildingItem()
{
    topBuilding[0] = new QGraphicsPixmapItem(QPixmap(":/assets/buildings/px-conversions/building_2-removebg-preview mirror.png"));
    bottomBuilding[0] = new QGraphicsPixmapItem(QPixmap(":/assets/buildings/px-conversions/building_2-removebg-preview.png"));
    topBuilding[1] = new QGraphicsPixmapItem(QPixmap(":/assets/buildings/px-conversions/building-removebg-preview mirror.png"));
    bottomBuilding[1] = new QGraphicsPixmapItem(QPixmap(":/assets/buildings/px-conversions/building-removebg-preview.png"));
    topBuilding[2] = new QGraphicsPixmapItem(QPixmap(":/assets/buildings/px-conversions/building_3_-removebg-preview mirror.png"));
    bottomBuilding[2] = new QGraphicsPixmapItem(QPixmap(":/assets/buildings/px-conversions/building_3_-removebg-preview.png"));

    pastbuilding=false;
    q = QRandomGenerator::global()->bounded(0,3);
    switch(q){
    case 0:
        topBuilding[q]->setTransform(QTransform().scale(0.8,0.8));
        bottomBuilding[q]->setTransform(QTransform().scale(0.8,0.8));
        topBuilding[q]->setPos(QPointF(0,0)-QPointF(topBuilding[q]->boundingRect().width()*0.8/2,topBuilding[q]->boundingRect().height()*0.8/2+420));
        bottomBuilding[q]->setPos(QPointF(0,0)+QPointF(-bottomBuilding[q]->boundingRect().width()*0.8/2,-bottomBuilding[q]->boundingRect().height()*0.8/2));
        break;
    case 1:
        topBuilding[q]->setTransform(QTransform().scale(0.5,0.5));
        bottomBuilding[q]->setTransform(QTransform().scale(0.5,0.5));
        topBuilding[q]->setPos(QPointF(0,0)-QPointF(topBuilding[q]->boundingRect().width()*0.5/2,topBuilding[q]->boundingRect().height()*0.5/2+500));
        bottomBuilding[q]->setPos(QPointF(0,0)+QPointF(-bottomBuilding[q]->boundingRect().width()*0.5/2,-bottomBuilding[q]->boundingRect().height()*0.5/2-40));
        break;
    case 2:
        topBuilding[q]->setTransform(QTransform().scale(0.8,0.8));
        bottomBuilding[q]->setTransform(QTransform().scale(0.8,0.8));
        topBuilding[q]->setPos(QPointF(0,0)-QPointF(topBuilding[q]->boundingRect().width()*0.8/2,topBuilding[q]->boundingRect().height()*0.8/2+530));
        bottomBuilding[q]->setPos(QPointF(0,0)+QPointF(-bottomBuilding[q]->boundingRect().width()*0.8/2,-bottomBuilding[q]->boundingRect().height()*0.8/2));
        break;
    }

    addToGroup(topBuilding[q]);
    addToGroup(bottomBuilding[q]);
    startmoving();

    connect(xanimation,&QPropertyAnimation::finished,[=](){
        QGraphicsItemGroup::scene()->removeItem(this);
        delete this;
    });

}

BuildingItem::~BuildingItem()
{
    delete topBuilding[3];
    delete bottomBuilding[3];
    delete xanimation;
}

void BuildingItem::freezeinplace()
{
    xanimation->stop();
}

void BuildingItem::startmoving()
{
    yPos = QRandomGenerator::global()->bounded(200,300);
    int xRandomizer = QRandomGenerator::global()->bounded(50,500);
    QGraphicsItemGroup::setPos(QPoint(0,0) + QPoint(500+ xRandomizer, yPos));
    xanimation = new QPropertyAnimation(this,"x",this);
    xanimation->setStartValue(2000+xRandomizer);
    xanimation->setEndValue(-700);
    xanimation->setEasingCurve(QEasingCurve::BezierSpline);
    xanimation->setDuration(5000);
    xanimation->start();
}

void BuildingItem::newmove(int a)
{
    xanimation = new QPropertyAnimation(this,"x",this);
    xanimation->setStartValue(x());
    xanimation->setEndValue(-400);
    xanimation->setEasingCurve(QEasingCurve::BezierSpline);
    xanimation->setDuration(a);
    xanimation->start();
}


bool BuildingItem::collideswithheli()
{
    QList<QGraphicsItem*> collidingitems = topBuilding[q]->collidingItems();
    collidingitems.append(bottomBuilding[q]->collidingItems());
    foreach (QGraphicsItem *item, collidingitems){
        HeliItem *heli = dynamic_cast<HeliItem*>(item);
        if(heli){
            return true;
        }
    }
    return false;
}

qreal BuildingItem::x() const
{
    return m_x;
}

void BuildingItem::setX(qreal newX)
{
    m_x = newX;

    if(x() < -150 && !pastbuilding){
        pastbuilding = true;
        QGraphicsScene *mscene = QGraphicsItemGroup::scene();
        Scene * myscene = dynamic_cast<Scene*>(mscene);
        if(myscene){
            myscene->incrementscore();
        }
    }

    if(collideswithheli()){
        emit collideFail();

    }
    QGraphicsItemGroup::setPos(QPointF(0,0)+QPointF(newX,yPos));
}
