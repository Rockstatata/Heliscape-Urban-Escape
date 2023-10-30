QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buildingitem.cpp \
    heliitem.cpp \
    item.cpp \
    main.cpp \
    mainwindow.cpp \
    playerprofile.cpp \
    scene.cpp \
    scores.cpp

HEADERS += \
    buildingitem.h \
    heliitem.h \
    item.h \
    mainwindow.h \
    playerprofile.h \
    scene.h \
    scores.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc \
    resources.qrc

DISTFILES += \
    assets/background/circle-pause-icon-14-removebg-preview.png \
    assets/background/gameover.png \
    assets/background/only sky.png \
    assets/background/only sky.png \
    assets/background/sky cropped mirror.png \
    assets/background/sky cropped mirror.png \
    assets/background/sky cropped.png \
    assets/background/sky cropped.png \
    assets/background/sky double.png \
    assets/background/sky double.png \
    assets/background/style-1990s-video-game-2d-pixelated_670382-119571 mirror.png \
    assets/background/style-1990s-video-game-2d-pixelated_670382-119571 mirror.png \
    assets/background/style-1990s-video-game-2d-pixelated_670382-119571.avif \
    assets/background/style-1990s-video-game-2d-pixelated_670382-119571.png \
    assets/buildings/px-conversions/building 2.png \
    assets/buildings/px-conversions/building 2.png \
    assets/buildings/px-conversions/building 3 .png \
    assets/buildings/px-conversions/building 3 .png \
    assets/buildings/px-conversions/building 4.png \
    assets/buildings/px-conversions/building 4.png \
    assets/buildings/px-conversions/building-removebg-preview mirror.png \
    assets/buildings/px-conversions/building-removebg-preview mirror.png \
    assets/buildings/px-conversions/building-removebg-preview.png \
    assets/buildings/px-conversions/building_2-removebg-preview mirror.png \
    assets/buildings/px-conversions/building_2-removebg-preview mirror.png \
    assets/buildings/px-conversions/building_2-removebg-preview.png \
    assets/buildings/px-conversions/building_3_-removebg-preview mirror.png \
    assets/buildings/px-conversions/building_3_-removebg-preview mirror.png \
    assets/buildings/px-conversions/building_3_-removebg-preview.png \
    assets/buildings/px-conversions/building_4-removebg-preview mirror.png \
    assets/buildings/px-conversions/building_4-removebg-preview mirror.png \
    assets/buildings/px-conversions/building_4-removebg-preview.png \
    assets/buildings/px-conversions/city-skyline-black_1284-13554.png \
    assets/buildings/px-conversions/city-skyline-design_1128-279.png \
    assets/buildings/px-conversions/cityscape.png \
    assets/buildings/px-conversions/different-buildings-set-white-background_1308-127937.png \
    assets/buildings/px-conversions/different-skyscrapers-illustrations-set_74855-17035.png \
    assets/buildings/px-conversions/set-modern-building_1308-14661.png \
    assets/buildings/px-conversions/small bui.png \
    assets/buildings/px-conversions/small bui.png \
    assets/buildings/px-conversions/small build.png \
    assets/buildings/px-conversions/small build.png \
    assets/helicopter/broken_parts/cabine.png \
    assets/helicopter/broken_parts/door_16x16.png \
    assets/helicopter/broken_parts/helicopter_back.png \
    assets/helicopter/helicopter.png \
    assets/helicopter/separated_frames/helicopter_1.png \
    assets/helicopter/separated_frames/helicopter_2.png \
    assets/helicopter/separated_frames/helicopter_3.png \
    assets/helicopter/separated_frames/helicopter_4.png \
    assets/helicopter/separated_frames/helicopter_5.png \
    assets/helicopter/separated_frames/helicopter_6.png \
    assets/helicopter/separated_frames/helicopter_7.png \
    assets/helicopter/separated_frames/helicopter_8.png \
    assets/helicopter2/heli1.png \
    assets/helicopter2/heli2.png \
    assets/helicopter2/heli3.png \
    assets/helicopter2/heli4.png \
    assets/helicopter2/pngaaa.com-1952383.png \
    assets/music/gamebg.mp3 \
    assets/music/helicrash.m4a \
    assets/music/heliwing.mp3 \
    assets/music/pointsound.mp3 \
    assets/music/tapsound.mp3 \
    assets/records/high_scores.txt \
    assets/records/player_highscore.txt \
    assets/records/player_profiles.txt \
    assets/records/systemwidehigh_scores.txt \
    assets/style/stylesheet.css
