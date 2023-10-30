/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_8;
    QStackedWidget *stackedWidget;
    QWidget *mainmenu;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *menubox;
    QLabel *gamelabel;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *playername;
    QLabel *warning;
    QSpacerItem *verticalSpacer;
    QPushButton *startgame;
    QPushButton *Settings;
    QPushButton *highscore_2;
    QPushButton *exitgame;
    QWidget *gamescreen;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *gamebox;
    QGraphicsView *graphicsView;
    QSpacerItem *verticalSpacer_9;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *restart;
    QPushButton *startexit;
    QSpacerItem *horizontalSpacer_4;
    QWidget *settingspage;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *settingsbox;
    QLabel *settingstext;
    QSpacerItem *verticalSpacer_4;
    QCheckBox *fullscreen;
    QCheckBox *music;
    QSpacerItem *verticalSpacer_3;
    QPushButton *back;
    QWidget *highscore;
    QHBoxLayout *horizontalLayout_5;
    QStackedWidget *stackedWidget_2;
    QWidget *page;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *scorebox;
    QLabel *scores;
    QSpacerItem *verticalSpacer_6;
    QPushButton *profile;
    QSpacerItem *verticalSpacer_7;
    QPushButton *leaderboard;
    QSpacerItem *verticalSpacer_5;
    QPushButton *back_2;
    QWidget *profile_2;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_2;
    QLabel *profilelabel;
    QComboBox *comboBox;
    QTableWidget *tableWidget;
    QPushButton *backbutton_2;
    QWidget *leaderboard_2;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_3;
    QLabel *leaderlabel;
    QTableWidget *tableWidget_2;
    QPushButton *backbutton;
    QSpacerItem *verticalSpacer_10;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_7;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(472, 417);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");

        horizontalLayout->addLayout(horizontalLayout_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_8);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        mainmenu = new QWidget();
        mainmenu->setObjectName("mainmenu");
        horizontalLayout_3 = new QHBoxLayout(mainmenu);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        menubox = new QVBoxLayout();
        menubox->setObjectName("menubox");
        gamelabel = new QLabel(mainmenu);
        gamelabel->setObjectName("gamelabel");
        gamelabel->setAlignment(Qt::AlignCenter);

        menubox->addWidget(gamelabel);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        menubox->addItem(verticalSpacer_2);

        playername = new QLineEdit(mainmenu);
        playername->setObjectName("playername");

        menubox->addWidget(playername);

        warning = new QLabel(mainmenu);
        warning->setObjectName("warning");
        warning->setAlignment(Qt::AlignCenter);

        menubox->addWidget(warning);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        menubox->addItem(verticalSpacer);

        startgame = new QPushButton(mainmenu);
        startgame->setObjectName("startgame");

        menubox->addWidget(startgame);

        Settings = new QPushButton(mainmenu);
        Settings->setObjectName("Settings");

        menubox->addWidget(Settings);

        highscore_2 = new QPushButton(mainmenu);
        highscore_2->setObjectName("highscore_2");

        menubox->addWidget(highscore_2);

        exitgame = new QPushButton(mainmenu);
        exitgame->setObjectName("exitgame");

        menubox->addWidget(exitgame);


        horizontalLayout_3->addLayout(menubox);

        stackedWidget->addWidget(mainmenu);
        gamescreen = new QWidget();
        gamescreen->setObjectName("gamescreen");
        horizontalLayout_4 = new QHBoxLayout(gamescreen);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        gamebox = new QVBoxLayout();
        gamebox->setObjectName("gamebox");
        graphicsView = new QGraphicsView(gamescreen);
        graphicsView->setObjectName("graphicsView");
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        graphicsView->setMouseTracking(false);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

        gamebox->addWidget(graphicsView);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gamebox->addItem(verticalSpacer_9);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        restart = new QPushButton(gamescreen);
        restart->setObjectName("restart");
        restart->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_12->addWidget(restart);

        startexit = new QPushButton(gamescreen);
        startexit->setObjectName("startexit");
        startexit->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_12->addWidget(startexit);


        gamebox->addLayout(horizontalLayout_12);


        horizontalLayout_4->addLayout(gamebox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        stackedWidget->addWidget(gamescreen);
        settingspage = new QWidget();
        settingspage->setObjectName("settingspage");
        horizontalLayout_2 = new QHBoxLayout(settingspage);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        settingsbox = new QVBoxLayout();
        settingsbox->setObjectName("settingsbox");
        settingstext = new QLabel(settingspage);
        settingstext->setObjectName("settingstext");
        settingstext->setAlignment(Qt::AlignCenter);

        settingsbox->addWidget(settingstext);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        settingsbox->addItem(verticalSpacer_4);

        fullscreen = new QCheckBox(settingspage);
        fullscreen->setObjectName("fullscreen");

        settingsbox->addWidget(fullscreen);

        music = new QCheckBox(settingspage);
        music->setObjectName("music");

        settingsbox->addWidget(music);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        settingsbox->addItem(verticalSpacer_3);

        back = new QPushButton(settingspage);
        back->setObjectName("back");

        settingsbox->addWidget(back);


        horizontalLayout_2->addLayout(settingsbox);

        stackedWidget->addWidget(settingspage);
        highscore = new QWidget();
        highscore->setObjectName("highscore");
        horizontalLayout_5 = new QHBoxLayout(highscore);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        stackedWidget_2 = new QStackedWidget(highscore);
        stackedWidget_2->setObjectName("stackedWidget_2");
        page = new QWidget();
        page->setObjectName("page");
        horizontalLayout_8 = new QHBoxLayout(page);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        scorebox = new QVBoxLayout();
        scorebox->setObjectName("scorebox");
        scores = new QLabel(page);
        scores->setObjectName("scores");
        scores->setAlignment(Qt::AlignCenter);

        scorebox->addWidget(scores);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        scorebox->addItem(verticalSpacer_6);

        profile = new QPushButton(page);
        profile->setObjectName("profile");

        scorebox->addWidget(profile);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        scorebox->addItem(verticalSpacer_7);

        leaderboard = new QPushButton(page);
        leaderboard->setObjectName("leaderboard");

        scorebox->addWidget(leaderboard);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        scorebox->addItem(verticalSpacer_5);

        back_2 = new QPushButton(page);
        back_2->setObjectName("back_2");

        scorebox->addWidget(back_2);


        horizontalLayout_8->addLayout(scorebox);

        stackedWidget_2->addWidget(page);
        profile_2 = new QWidget();
        profile_2->setObjectName("profile_2");
        horizontalLayout_9 = new QHBoxLayout(profile_2);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        profilelabel = new QLabel(profile_2);
        profilelabel->setObjectName("profilelabel");
        profilelabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(profilelabel);

        comboBox = new QComboBox(profile_2);
        comboBox->setObjectName("comboBox");
        comboBox->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(comboBox);

        tableWidget = new QTableWidget(profile_2);
        tableWidget->setObjectName("tableWidget");

        verticalLayout_2->addWidget(tableWidget);

        backbutton_2 = new QPushButton(profile_2);
        backbutton_2->setObjectName("backbutton_2");

        verticalLayout_2->addWidget(backbutton_2);


        horizontalLayout_9->addLayout(verticalLayout_2);

        stackedWidget_2->addWidget(profile_2);
        leaderboard_2 = new QWidget();
        leaderboard_2->setObjectName("leaderboard_2");
        horizontalLayout_10 = new QHBoxLayout(leaderboard_2);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        leaderlabel = new QLabel(leaderboard_2);
        leaderlabel->setObjectName("leaderlabel");
        leaderlabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(leaderlabel);

        tableWidget_2 = new QTableWidget(leaderboard_2);
        tableWidget_2->setObjectName("tableWidget_2");

        verticalLayout_3->addWidget(tableWidget_2);

        backbutton = new QPushButton(leaderboard_2);
        backbutton->setObjectName("backbutton");

        verticalLayout_3->addWidget(backbutton);


        horizontalLayout_10->addLayout(verticalLayout_3);

        stackedWidget_2->addWidget(leaderboard_2);

        horizontalLayout_5->addWidget(stackedWidget_2);

        stackedWidget->addWidget(highscore);

        verticalLayout->addWidget(stackedWidget);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_10);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");

        horizontalLayout->addLayout(horizontalLayout_7);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        gamelabel->setText(QCoreApplication::translate("MainWindow", "Heliscape: Urban Escape", nullptr));
        warning->setText(QString());
        startgame->setText(QCoreApplication::translate("MainWindow", "Start Game", nullptr));
        Settings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        highscore_2->setText(QCoreApplication::translate("MainWindow", "High Score", nullptr));
        exitgame->setText(QCoreApplication::translate("MainWindow", "Exit Game", nullptr));
        restart->setText(QCoreApplication::translate("MainWindow", "Start Game", nullptr));
        startexit->setText(QCoreApplication::translate("MainWindow", "Exit Game", nullptr));
        settingstext->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        fullscreen->setText(QCoreApplication::translate("MainWindow", "Full Screen", nullptr));
        music->setText(QCoreApplication::translate("MainWindow", "Music", nullptr));
        back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        scores->setText(QCoreApplication::translate("MainWindow", "Scores", nullptr));
        profile->setText(QCoreApplication::translate("MainWindow", "Profile", nullptr));
        leaderboard->setText(QCoreApplication::translate("MainWindow", "Leaderboard", nullptr));
        back_2->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        profilelabel->setText(QCoreApplication::translate("MainWindow", "Profile High Score", nullptr));
        backbutton_2->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        leaderlabel->setText(QCoreApplication::translate("MainWindow", "Leaderboard", nullptr));
        backbutton->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Made with love by Sarwad - 2107006\342\235\244\357\270\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
