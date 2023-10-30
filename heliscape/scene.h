#ifndef SCENE_H
#define SCENE_H

// Main Game screen class
// Inherits from QGraphicsScene, a library function
#include <QtMultimedia>
#include <QAudioOutput>
#include <QSoundEffect>
#include <QMediaPlayer>
#include <QGraphicsScene>
#include <QTimer>
#include "buildingitem.h"
#include "heliitem.h"
#include "scores.h"


class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
    ~Scene();
    void showgameover();
    void hidegameover();
    void showhighscore();
    void addheli();
    void startgame();
    void stopgame();
    void pausegame();
    void resumegame();
    bool ifground();
    void ifroof();
    bool getGameon() const;
    void setGameon(bool newGameon);
    int incrementscore();
    void showscore();
    void setScore(int newScore);
    int getscore();

    void handlemusic(int);
    QMediaPlayer *getBgm() const;

    void setMusic(int newMusic);

    template<class T1, class T2, class T3>
    void setSoundeffect(T1* soundeffect, T2* audiooutput, T3 volume);

    template<class T1, class T3>
    void modeSoundeffect(T1* soundeffect, T3 mode);

    template<class T1, class T2>
    void locatesound(T1* sound, T2& location);

signals:

private:
    void cleanbuildings();
    int setUpBuildingTimer();
    void freezeheliandbuilding();

    bool gameon;
    int score,music;
    int bestscore;
    std::string locations[5];
    QTimer * BuildingTimer;
    BuildingItem* buildingitem;
    HeliItem * heli;
    item* Item;
    QGraphicsPixmapItem *gameover;
    QGraphicsTextItem *scoreText;
    QGraphicsPixmapItem *gamepause;
    QMediaPlayer* musicfiles;
    QAudioOutput* audiooutput;

protected:
    template<class T>
    void PressEvent(T *);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SCENE_H
