#include "scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

Scene::Scene(QObject *parent) :
    QGraphicsScene(parent),
    gameon(false),
    score(0),
    bestscore(0),
    buildingitem{nullptr},
    heli{nullptr},
    Item{nullptr},
    gameover {nullptr},
    scoreText {nullptr},
    gamepause {nullptr}
{
    musicfiles = new QMediaPlayer[5];
    audiooutput = new QAudioOutput[5];

    locations[0]="music/pointsound.mp3";
    locations[1]="music/heliwing.mp3";
    locations[2]="music/helicrash.m4a";
    locations[3]="music/gamebg.mp3";
    locations[4]="music/tapsound.mp3";

    handlemusic(music);

    setUpBuildingTimer();
}

Scene::~Scene()
{
    delete Item;
    delete BuildingTimer;
    if(heli != nullptr)delete heli;
    if(buildingitem != nullptr)delete []buildingitem;
    delete gameover;
    delete scoreText;
    delete gamepause;
    delete []musicfiles;
    delete []audiooutput;
}

void Scene::showgameover()
{
    gameover = new QGraphicsPixmapItem(QPixmap(":/assets/background/gameover.png"));
    addItem(gameover);
    gameover->setTransform(QTransform().scale(0.25,0.25));
    gameover->setPos(QPointF(0,0)-QPointF((gameover->boundingRect().width()*0.25)/2,(gameover->boundingRect().height()*0.25)/2));
    if(scoreText){
        removeItem(scoreText);
        delete scoreText;
    }
    scoreText = new QGraphicsTextItem();
    QString htmlstring = "<p> Score: " + QString::number(score)+"</p>" +
                           "<p> High Score: "+ QString::number(bestscore)+"</p>";
    QFont mfont("Consolas", 30, QFont::Bold);
    scoreText->setHtml(htmlstring);
    scoreText->setFont(mfont);
    scoreText->setDefaultTextColor(Qt::yellow);
    addItem(scoreText);
    scoreText->setPos(QPointF(0,0)-QPointF(scoreText->boundingRect().width()/2,-scoreText->boundingRect().height()/2));
}

void Scene::hidegameover()
{
    if(gameover){
        removeItem(gameover);
        delete gameover;
        gameover = nullptr;
    }
    if(scoreText){
        removeItem(scoreText);
        delete scoreText;
        scoreText = nullptr;
    }
    if(gamepause){
        removeItem(gamepause);
        delete gamepause;
        gamepause = nullptr;
    }

}

void Scene::showhighscore()
{
    scoreText = new QGraphicsTextItem();
    QString htmlstring ="<p> High Score: "+ QString::number(bestscore)+"</p>";
    QFont mfont("Consolas", 30, QFont::Bold);
    scoreText->setHtml(htmlstring);
    scoreText->setFont(mfont);
    scoreText->setDefaultTextColor(Qt::yellow);
    addItem(scoreText);
    scoreText->setPos(QPointF(0,0)-QPointF(scoreText->boundingRect().width()/2,-scoreText->boundingRect().height()/2));
}

void Scene::addheli()
{
    Item = new HeliItem(QPixmap(":/assets/helicopter/separated_frames/helicopter_1.png"));
    heli = dynamic_cast<HeliItem*>(Item);
    addItem(heli);
    heli->QGraphicsPixmapItem::setPos(QPointF(0,0)-QPointF(heli->QGraphicsPixmapItem::boundingRect().width()/2+100,0));

}

void Scene::startgame()
{
    modeSoundeffect(&musicfiles[3],0);
    modeSoundeffect(&musicfiles[1],1);
    musicfiles[1].setLoops(INFINITY);
    hidegameover();
    setScore(0);
    showscore();
    setGameon(true);

    // heli
    heli->startmoving();
    heli->QGraphicsPixmapItem::setPos(QPointF(0,0)-QPointF(heli->QGraphicsPixmapItem::boundingRect().width()/2+100,0));
    heli->setY(0);

    // Building
    if(!BuildingTimer->isActive() || true){
        cleanbuildings();
        BuildingTimer->start(1000);
    }

}

void Scene::stopgame()
{
    modeSoundeffect(&musicfiles[1],0);
    modeSoundeffect(&musicfiles[3],1);
    hidegameover();
    setGameon(false);
    heli->stopFlying();
    heli->QGraphicsPixmapItem::setPos(QPointF(0,0)-QPointF(heli->QGraphicsPixmapItem::boundingRect().width()/2+100,0));
    if(BuildingTimer->isActive()){
        BuildingTimer->stop();
    }
    cleanbuildings();
}

void Scene::pausegame()
{
    gamepause = new QGraphicsPixmapItem(QPixmap(":/assets/background/circle-pause-icon-14-removebg-preview.png"));
    addItem(gamepause);
    gamepause->setTransform(QTransform().scale(0.25,0.25));
    gamepause->setPos(QPointF(0,0)-QPointF((gamepause->boundingRect().width()*0.25)/2,(gamepause->boundingRect().height()*0.25)/2));
    setGameon(false);
    BuildingTimer->stop();
    freezeheliandbuilding();
}

void Scene::resumegame()
{
    setGameon(true);
    removeItem(gamepause);
    heli->resumeflying();
    QList<QGraphicsItem*> sceneitems=items();
    int x = 3000,i=0;
    foreach (QGraphicsItem *item,sceneitems){
        BuildingItem *building = dynamic_cast<BuildingItem*>(item);
        if(building){
            x-=i*1000;
            building->newmove(x);
            i++;
        }
    }
    BuildingTimer->stop();
    if(!BuildingTimer->isActive()){
        BuildingTimer->start(1000);
    }

}

bool Scene::ifground()
{
    if(heli->groundhit()){
        setGameon(false);
        BuildingTimer->stop();
        freezeheliandbuilding();
        showgameover();
        return true;
    }
    return false;
}

void Scene::ifroof()
{
    if(heli->roofhit()){
        heli->falltotheground();;
    }

}

int Scene::setUpBuildingTimer()
{
    BuildingTimer= new QTimer(this);
    connect(BuildingTimer,&QTimer::timeout,[=]{
        if(ifground())return 0;
        Item = new BuildingItem();
        buildingitem = dynamic_cast<BuildingItem*>(Item);
        connect(buildingitem, &BuildingItem::collideFail,[=]{
            modeSoundeffect(&musicfiles[2],1);
            BuildingTimer->stop();
            freezeheliandbuilding();
            setGameon(false);
            showgameover();
        });
        addItem(buildingitem);
    });
    return 0;
}

void Scene::freezeheliandbuilding()
{
    heli->freezeinplace();
    QList<QGraphicsItem*> sceneitems=items();
    foreach (QGraphicsItem *item,sceneitems){
        BuildingItem *building = dynamic_cast<BuildingItem*>(item);
        if(building){
            building->freezeinplace();
        }
    }
}

void Scene::setMusic(int newMusic)
{
    music = newMusic;
}

QMediaPlayer *Scene::getBgm() const
{
    return &musicfiles[3];
}

void Scene::setScore(int newScore)
{
    score = newScore;
}

int Scene::getscore()
{
    return score;
}

void Scene::handlemusic(int i)
{
    if(i==1){
        for(int i = 0;i<5;i++){
            locatesound(&musicfiles[i],locations[i]);
            setSoundeffect(&musicfiles[i],&audiooutput[i],50);
        }
        modeSoundeffect(&musicfiles[3],1);
        musicfiles[3].setLoops(INFINITY);
    }
    else{
        for(int i = 0;i<5;i++){
            locatesound(&musicfiles[i],locations[i]);
            setSoundeffect(&musicfiles[i],&audiooutput[i],0);
        }
    }
}


bool Scene::getGameon() const
{
    return gameon;
}

void Scene::setGameon(bool newGameon)
{
    gameon = newGameon;
}

int Scene::incrementscore()
{
    modeSoundeffect(&musicfiles[0],1);
    score++;
    removeItem(scoreText);
    delete scoreText;
    showscore();
    if(score>bestscore){
        bestscore = score;
    }
    return score;
}

void Scene::showscore()
{
    scoreText = new QGraphicsTextItem();
    QString htmlstring = "<p> Score: " + QString::number(score)+"</p>";
    QFont mfont("Consolas", 30, QFont::ExtraBold);
    scoreText->setHtml(htmlstring);
    scoreText->setFont(mfont);
    scoreText->setDefaultTextColor(Qt::yellow);
    addItem(scoreText);
    scoreText->setPos(QPointF(0,0)-QPointF(scoreText->boundingRect().width()+180,scoreText->boundingRect().height()+220));
}

void Scene::cleanbuildings()
{
    QList<QGraphicsItem*> sceneitems=items();
    foreach (QGraphicsItem *item,sceneitems){
        BuildingItem *building = dynamic_cast<BuildingItem*>(item);
        if(building){
            removeItem(building);
            delete building;
        }
    }
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Space){
        if(gameon){
            heli->shootup();
            modeSoundeffect(&musicfiles[4],1);
        }
    }
    QGraphicsScene::keyPressEvent(event);
    if((event->key()==Qt::Key_Up)){
        if(gameon){
            heli->shootup();
            modeSoundeffect(&musicfiles[4],1);
        }
    }
    QGraphicsScene::keyPressEvent(event);
    if((event->key())==Qt::Key_Shift){
        if(!gameon && !gameover)resumegame();
    }
    QGraphicsScene::keyPressEvent(event);
    if((event->key())==Qt::Key_Backspace){
        if(gameon)pausegame();
    }
    QGraphicsScene::keyPressEvent(event);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if((event->button()==Qt::LeftButton)){
        if(gameon){
            heli->shootup();
            modeSoundeffect(&musicfiles[4],1);
        }
    }
    QGraphicsScene::mousePressEvent(event);
}

template<class T1, class T2, class T3>
void Scene::setSoundeffect(T1 *soundeffect,T2 *output, T3 volume)
{
    soundeffect->setAudioOutput(output);
    output->setVolume(volume);
}

template<class T1, class T2>
void Scene::locatesound(T1 *sound,T2 &location)
{
    QString c = QString::fromStdString(location);
    sound->setSource(QUrl::fromLocalFile(c));

}

template<class T1, class T3>
void Scene::modeSoundeffect(T1* soundeffect, T3 mode)
{
    if(mode==1){
        soundeffect->play();
    }
    else{
        soundeffect->stop();
    }
}

template<class T>
void Scene::PressEvent(T *event)
{
    if(typeid(T)==typeid(QKeyEvent)){
        keyPressEvent(event);
    }
    else if(typeid(T)==typeid(QGraphicsSceneMouseEvent)){
        mousePressEvent(event);
    }
}
