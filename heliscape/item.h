#ifndef ITEM_H
#define ITEM_H

// An Abstract class which is parent to all the fundamental classes of the game
// This inherits the Qobject, a library class which makes gives special functionality to normal objects

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

class item : public QObject
{
    Q_OBJECT
public:
    item();
    virtual void freezeinplace()=0;
    virtual void startmoving()=0;
    virtual ~item();
};

#endif // ITEM_H
