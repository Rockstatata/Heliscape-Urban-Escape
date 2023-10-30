#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QApplication *app, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene{nullptr}
    , background{nullptr}
    , flag{0}
{
    ui->setupUi(this);
    this->app = app;

    filen = (QApplication::applicationDirPath()).toStdString();
    pp = "file/player_profiles.txt";
    shs = "file/systemwidehigh_scores.txt";
    set = "file/settings.txt";


    QWidget parentwidget;
    QGraphicsView view(&parentwidget);

    scene = new Scene(this);

    setWindowTitle("Heliscape: Urban Escape");
    QIcon icon(":/assets/background/pixel-8-bit-uppercase-letter-h-as-font-vector-47463245.jpg"); // Replace with the path to your icon file
    setWindowIcon(icon);


    background = new QGraphicsPixmapItem(QPixmap(":/assets/background/sky double.png"));
    scene->addItem(background);
    background->setTransform(QTransform().scale(1.15,1.15));
    background->setPos(QPointF(0,0)-QPointF((background->boundingRect().width()*1.15)/2,(background->boundingRect().height()*1.15)/2));

    scene->addheli();
    ui->graphicsView->setScene(scene);

    loadprofilefromfile();
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(makeprofileboard(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

void MainWindow::getSystemLeaderboard()
{
    for(playerprofile& profile : playerprofiles) {
        for(scores<std::string,int>& score:profile.getSessionscores()){
            leaderboard.push_back(score);
        }
    }
    std::sort(leaderboard.begin(), leaderboard.end(), [](const scores<std::string,int>& a, const scores<std::string,int>& b) {
        return a.getScore() > b.getScore();
    });
}

template<class T>
int MainWindow::createprofile(const T& playerName)
{
    for (int i = 0;i<playerprofiles.size();i++) {
        if (playerprofiles[i].getPlayername() == playerName) {
            return i;
        }
    }
    std::vector<scores<std::string,int>>s;
    playerprofile newProfile(playerName,s);
    playerprofiles.push_back(newProfile);
    return (playerprofiles.size()-1);
}

template<class T>
void MainWindow::updateSessionScore(const T& playerName,int sessionscore)
{
    for (playerprofile& profile : playerprofiles) {
        if (profile.getPlayername() == playerName) {
            scores newScore(playerName,sessionscore);
            profile.getSessionscores().push_back(newScore);
        }
    }
}

template<class T>
void MainWindow::getProfileHighScores(const T& playerName)
{

    for (playerprofile& profile : playerprofiles) {
        if (profile.getPlayername() == playerName) {
            std::vector<scores<std::string,int>> &score = profile.getSessionscores();
            std::sort(score.begin(), score.end(), [](const scores<std::string,int>& a,const scores<std::string,int>& b) {
                return a.getScore() > b.getScore();
            });
        }
    }
}

void MainWindow::loadprofilefromfile()
{
    std::string name,pname;
    std::vector <scores<std::string,int>> allscore;
    scores<std::string,int> score;
    file.open(pp,std::ios::in);
    file3.open(shs,std::ios::in);
    file4.open(set,std::ios::in);
    while(std::getline(file,name)){
        std::string filename = "file/"+name+".txt";
        file2.open(filename,std::ios::in);
        std::getline(file2,pname);
        while(file2>>score){
            allscore.push_back(score);
        }
        playerprofiles.push_back({name,allscore});
        file2.close();
        allscore.clear();
    }
    file4>>fullscreen>>music;
    set_tick();
    file.close();
    file4.close();
    file3.close();
}

void MainWindow::saveprofiletofile()
{
    file2.open(pp,std::ios::out);
    file3.open(shs,std::ios::out);
    file4.open(set,std::ios::out);
    for(auto profiles: playerprofiles){
        //auto it = std::find(playerprofiles.begin(),playerprofiles.end(),)
        file2<<profiles.getPlayername()<<std::endl;
        std::string filename = "file/"+profiles.getPlayername()+".txt";
        file.open(filename,std::ios::out);
        file<<profiles.getPlayername()<<std::endl;
        getProfileHighScores(profiles.getPlayername());
        for(auto &scores:profiles.getSessionscores()){
            file<<scores;
        }
        file.close();
    }
    getSystemLeaderboard();
    for(auto score:leaderboard){
        file3<<score;
    }
    file4<<fullscreen<<" "<<music;
    file2.close();
    file3.close();
    file4.close();
}

void MainWindow::combolist()
{
    for(int i =0;i<playerprofiles.size();i++){
        std::string s = playerprofiles[i].getPlayername();
        QString c =  QString::fromStdString(s);
        ui->comboBox->addItem(c);
    }
}

void MainWindow::make_leaderboard()
{
    leaderboard.clear();
    getSystemLeaderboard();
    ui->tableWidget->clear();
    ui->tableWidget_2->setColumnCount(2);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList() << "Player Name" << "Score");
    ui->tableWidget_2->setRowCount(leaderboard.size());
    for (int row = 0; row < leaderboard.size(); ++row) {
        const scores<std::string,int>& entry = leaderboard[row];

        QTableWidgetItem* playerNameItem = new QTableWidgetItem(QString::fromStdString(entry.getPlayername()));
        QTableWidgetItem* scoreItem = new QTableWidgetItem(QString::number(entry.getScore()));

        ui->tableWidget_2->setItem(row, 0, playerNameItem);
        ui->tableWidget_2->setItem(row, 1, scoreItem);
    }
}

void MainWindow::set_tick()
{
    if(fullscreen==1){
        ui->fullscreen->setChecked(true);
    }
    else{
        ui->fullscreen->setChecked(false);
    }
    if(music==1){
        ui->music->setChecked(true);
        scene->setMusic(1);
        scene->getBgm()->play();
    }
    else{
        ui->music->setChecked(false);
        scene->setMusic(0);
    }
}

void MainWindow::makeprofileboard(int i)
{
    ui->tableWidget->clear();
    std::string s = ui->comboBox->currentText().toStdString();
    for(auto profile:playerprofiles){
        if(s==profile.getPlayername()){
            getProfileHighScores(s);
            ui->tableWidget->setColumnCount(2);
            ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            ui->tableWidget_2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
            ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Player Name" << "Score");
            ui->tableWidget->setRowCount(profile.getSessionscores().size());
            for (int row = 0; row < profile.getSessionscores().size(); ++row) {
                const scores<std::string,int>& entry = profile.getSessionscores()[row];

                QTableWidgetItem* playerNameItem = new QTableWidgetItem(QString::fromStdString(entry.getPlayername()));
                QTableWidgetItem* scoreItem = new QTableWidgetItem(QString::number(entry.getScore()));

                ui->tableWidget->setItem(row, 0, playerNameItem);
                ui->tableWidget->setItem(row, 1, scoreItem);
            }
        }
    }
}

void MainWindow::on_exitgame_clicked()
{
    saveprofiletofile();
    app->quit();
}


void MainWindow::on_highscore_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_startgame_clicked()
{
    if(ui->playername->text().isEmpty()){
        ui->warning->setText("Set Player name...");
    }
    else{
        flag =0;
        name = ui->playername->text().toStdString();
        cur_index = createprofile(name);
        ui->stackedWidget->setCurrentIndex(1);
    }
}

void MainWindow::on_startexit_clicked()
{
    flag = 0;
    updateSessionScore(name,scene->getscore());
    saveprofiletofile();
    scene->stopgame();
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_Settings_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_back_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_playername_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        ui->warning->setText("Set Player name...");
    }
    else{
        ui->warning->setText("");
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton exit = QMessageBox::question(this,"Heliscape",tr("Do you really want to quit game?"),QMessageBox::No | QMessageBox::Yes | QMessageBox::Cancel);
    if(exit!=QMessageBox::Yes){
        event->ignore();
    }
    else{
        event->accept();
    }
}


void MainWindow::on_restart_clicked()
{
    if(scene->getGameon() || flag==1){
        updateSessionScore(name,scene->getscore());
    }
    scene->startgame();
    flag = 1;
}


void MainWindow::on_profile_clicked()
{
    combolist();
    ui->stackedWidget_2->setCurrentIndex(1);
}


void MainWindow::on_leaderboard_clicked()
{
    make_leaderboard();
    ui->stackedWidget_2->setCurrentIndex(2);
}


void MainWindow::on_backbutton_clicked()
{
    ui->comboBox->clear();
    ui->stackedWidget_2->setCurrentIndex(0);
}


void MainWindow::on_backbutton_2_clicked()
{
    ui->comboBox->clear();
    ui->stackedWidget_2->setCurrentIndex(0);
}


void MainWindow::on_fullscreen_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        fullscreen=1;
        showFullScreen();
    }
    else{
        fullscreen=0;
        showNormal();
    }
}


void MainWindow::on_music_stateChanged(int arg1)
{
    if(arg1==Qt::Checked){
        music=1;
        scene->handlemusic(1);

    }
    else{
        scene->getBgm()->stop();
        music=0;
        scene->handlemusic(0);

    }
    scene->setMusic(music);
}

