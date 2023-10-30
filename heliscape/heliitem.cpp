#include "heliitem.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

HeliItem::HeliItem(QPixmap pixmap)
{
    wingposition = one;
    setPixmap(pixmap);
    QTimer * heliWingsTimer = new QTimer(this);
    connect(heliWingsTimer,&QTimer::timeout,[=](){
        updatePixmap();
    });
    heliWingsTimer->start(80);

    groundposition = scenePos().y()+230;

    yanimation = new QPropertyAnimation(this,"y",this);

    rotationanimation = new QPropertyAnimation(this,"rotation",this);
}

HeliItem::~HeliItem()
{
    delete yanimation;
    delete rotationanimation;
}



void HeliItem::updatePixmap()
{
    if(wingposition == Wingposition::one){
        setPixmap(QPixmap(":/assets/helicopter/separated_frames/helicopter_1.png"));
        wingposition = two;
    }
    else if(wingposition == Wingposition::two){
        setPixmap(QPixmap(":/assets/helicopter/separated_frames/helicopter_2.png"));
        wingposition = three;
    }
    else if(wingposition == Wingposition::three){
        setPixmap(QPixmap(":/assets/helicopter/separated_frames/helicopter_3.png"));
        wingposition = four;
    }
    else if(wingposition == Wingposition::four){
        setPixmap(QPixmap(":/assets/helicopter/separated_frames/helicopter_4.png"));
        wingposition = five;
    }
    else if(wingposition == Wingposition::five){
        setPixmap(QPixmap(":/assets/helicopter/separated_frames/helicopter_5.png"));
        wingposition = six;
    }
    if(wingposition == Wingposition::six){
        setPixmap(QPixmap(":/assets/helicopter/separated_frames/helicopter_6.png"));
        wingposition = seven;
    }
    else if(wingposition == Wingposition::seven){
        setPixmap(QPixmap(":/assets/helicopter/separated_frames/helicopter_7.png"));
        wingposition = eight;
    }
    else if(wingposition == Wingposition::eight){
        setPixmap(QPixmap(":/assets/helicopter/separated_frames/helicopter_8.png"));
        wingposition = one;
    }
}

qreal HeliItem::rotation() const
{
    return m_rotation;
}

void HeliItem::setRotation(qreal newrotation)
{
    m_rotation = newrotation;
    QPointF c= boundingRect().center();
    QTransform t;
    t.translate(c.x(),c.y());
    t.rotate(newrotation);
    t.translate(-c.x(),-c.y());
    setTransform(t);
}

void HeliItem::rotateTo(const qreal &end, const int &duration, const QEasingCurve &curve)
{
    //roofhit();
    rotationanimation->setStartValue(rotation());
    rotationanimation->setEndValue(((end>-groundposition)?end:-groundposition));
    rotationanimation->setEasingCurve(curve);
    rotationanimation->setDuration(duration);
    rotationanimation->start();
}

void HeliItem::yTo(const qreal &end, const int &duration, const QEasingCurve &curve)
{
    //roofhit();
    yanimation->setStartValue(y());
    yanimation->setEndValue(((end>-groundposition)?end:-groundposition));
    yanimation->setEasingCurve(curve);
    yanimation->setDuration(duration);
    yanimation->start();
}

void HeliItem::shootup()
{
    yanimation->stop();
    rotationanimation->stop();
    qreal curPosY = y();
    connect(yanimation,&QPropertyAnimation::finished,[=](){
        falltotheground();
        //roofhit();
    });
    yTo(curPosY-scene()->sceneRect().height()/20,285,QEasingCurve::OutQuad);
    rotateTo(-20,200,QEasingCurve::OutCubic);
    roofhit();
}

void HeliItem::falltotheground()
{
    if(y()<groundposition){
        yTo(groundposition,1200,QEasingCurve::InQuad);
        rotateTo(90,1200,QEasingCurve::InCubic);
    }
    else if(y()==groundposition){
        //roofhit();
        groundhit();
    }
}

void HeliItem::startmoving()
{
    setY(0);
    yanimation->stop();
    rotateTo(0,0,QEasingCurve::InQuad);
    rotationanimation->stop();
    yTo(groundposition,1000,QEasingCurve::InQuad);
    rotateTo(90,1200,QEasingCurve::InQuad);
    rotationanimation->stop();

}

void HeliItem::stopFlying()
{
    setY(0);
    yanimation->stop();
    rotationanimation->stop();
    rotateTo(0,1,QEasingCurve::InQuad);
}

void HeliItem::freezeinplace()
{
    //setY(0);
    yanimation->stop();
    rotationanimation->stop();
}

void HeliItem::resumeflying()
{
    yTo(groundposition,1000,QEasingCurve::InQuad);
    rotateTo(90,1200,QEasingCurve::InQuad);
}

bool HeliItem::groundhit()
{
    if(y()==groundposition){
        yanimation->stop();
        rotationanimation->stop();
        return true;
    }
    return false;
}

qreal HeliItem::y() const
{
    return m_y;

}

void HeliItem::setY(qreal newY)
{
    //qDebug()<<"Heli position: "<<y();
    moveBy(0,newY-m_y);
    m_y = newY;
}

bool HeliItem::roofhit()
{
    if(y()<=(-groundposition-8)){
        setY(-groundposition-8);
        yanimation->stop();
        rotationanimation->stop();
        //falltotheground();
        return true;
    }
    return false;
}
