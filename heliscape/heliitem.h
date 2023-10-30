#ifndef HELIITEM_H
#define HELIITEM_H

//Inherits from the item class and QgraphicsPixmapitemclass
//The pixmapitemclass helps to give animation type effect to objects
// This class holds the helicopter item of the game
#include "item.h"

class HeliItem : public item, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(qreal rotation READ rotation WRITE setRotation)
    Q_PROPERTY(qreal y READ y WRITE setY)

public:
    explicit HeliItem(QPixmap pixmap);
    ~HeliItem();
    qreal rotation() const;
    void setRotation(qreal newRotation);
    void rotateTo(const qreal &end, const int& duration, const QEasingCurve& curve);
    void yTo(const qreal &end, const int& duration, const QEasingCurve& curve);
    void shootup();
    void falltotheground();
    void startmoving();
    void stopFlying();
    void freezeinplace();
    void resumeflying();
    bool groundhit();
    qreal y() const;
    void setY(qreal newY);
    bool roofhit();

private:
    enum Wingposition{
        one,two,three,four,five,six,seven,eight
    };
    void updatePixmap();
    Wingposition wingposition;
    qreal m_rotation;
    qreal m_y;
    qreal groundposition;
    QPropertyAnimation *yanimation;
    QPropertyAnimation *rotationanimation;
    qreal m_axis;
    qreal m_x;
};

#endif // HELIITEM_H
