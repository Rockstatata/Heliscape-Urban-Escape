#ifndef BUILDINGITEM_H
#define BUILDINGITEM_H

// Building items inherit from items and the QGraphicsItemGroup, a library class
// This class is used to represent the buildings, which are grouped together
// These items spawn a bit randomly in y direction, and keeps running in a continuous animation in x direction
// If gets hit by the helicopter, then the game is declared to be over
#include "item.h"

class BuildingItem : public item,  public QGraphicsItemGroup{
    Q_OBJECT
    Q_PROPERTY(qreal x READ x WRITE setX)

public:
    explicit BuildingItem();
    ~BuildingItem();
    void freezeinplace();
    void startmoving();
    void newmove(int a);
    qreal x() const;
    void setX(qreal newX);

signals:
    void collideFail();

private:
    QGraphicsPixmapItem *topBuilding[3];
    QGraphicsPixmapItem *bottomBuilding[3];
    QPropertyAnimation *xanimation;
    int yPos;
    int q;
    qreal m_x;
    bool pastbuilding;
    bool collideswithheli();
};

#endif // BUILDINGITEM_H
