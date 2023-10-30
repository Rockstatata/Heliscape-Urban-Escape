#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// The main window class which holds the application
// Inherits from the QMainwindow, a library class
// The application runs as long as this class is running
// Recursion occurs in this class and it keeps calling other classes
// Only Exits the game when the quit function of this class is called

// Can start the main game from here
// Can go to settings and change some stuff up there
// Can go to Highscores tab and check the highscores of different players
// Can go to Highscores tab and check the Leaderboard of the entire history of the game
// Can exit the game and a messagebox pops out, and only when its true the game exits


#include "playerprofile.h"
#include <QWidget>
#include <QCloseEvent>
#include <QMessageBox>
#include <QMainWindow>
#include "scene.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QApplication *app, QWidget *parent = nullptr);
    ~MainWindow();
    void getSystemLeaderboard();

    template <typename T>
    int createprofile(const T&);

    template <typename T>
    void updateSessionScore(const T&,int sessionscore);

    template <typename T>
    void getProfileHighScores(const T&);

    void loadprofilefromfile();
    void saveprofiletofile();
    void incrementscore(int);
    void combolist();
    void checkkey();
    void make_leaderboard();
    void set_tick();

signals:


private slots:

    void makeprofileboard(int i);

    void on_exitgame_clicked();

    void on_highscore_2_clicked();

    void on_startgame_clicked();

    void on_startexit_clicked();

    void on_Settings_clicked();

    void on_back_2_clicked();

    void on_back_clicked();

    void on_playername_textChanged(const QString &arg1);

    void on_restart_clicked();

    void on_profile_clicked();

    void on_leaderboard_clicked();

    void on_backbutton_clicked();

    void on_backbutton_2_clicked();

    void on_fullscreen_stateChanged(int arg1);

    void on_music_stateChanged(int arg1);

private:
    QApplication *app;
    Ui::MainWindow *ui;
    Scene *scene;
    QGraphicsPixmapItem *background;
    int cur_index,flag,fullscreen,music;
    std::string filen;
    std::string pp;
    std::string shs;
    std::string set;
    std::string name;
    playerprofile profile;
    std::fstream file,file2,file3,file4;
    std::vector<playerprofile>playerprofiles;
    std::vector<scores<std::string,int>>leaderboard;
    std::vector<std::string>playername;
    std::vector<scores<std::string,int>> profileHighScores;
    void closeEvent(QCloseEvent *event);
};
#endif // MAINWINDOW_H
