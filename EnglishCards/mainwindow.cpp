#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mediaPlayer = new QMediaPlayer(this);

    connect(ui->buttonPrevCard, &QPushButton::clicked,              this, &MainWindow::onButtonPrevClicked);
    connect(ui->buttonNextCard, &QPushButton::clicked,              this, &MainWindow::onButtonNextClicked);
    connect(ui->buttonEnglish,  &QPushButton::clicked,              this, &MainWindow::onButtonEnglishClicked);
    connect(ui->buttonRussian,  &QPushButton::clicked,              this, &MainWindow::onButtonRussianClicked);
    connect(ui->buttonVideo,    &QPushButton::clicked,              this, &MainWindow::onButtonVideoClicked);
    connect(mediaPlayer,        &QMediaPlayer::stateChanged,        this, &MainWindow::onVideoStateChanged);
    connect(ui->actionAbout,    &QAction::triggered,                this, &MainWindow::onActionAboutProgramTriggered);

    video = new QVideoWidget();
    ui->stackedPictureVideo->insertWidget(1, video);
    mediaPlayer->setVideoOutput(video);
    showCard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonPrevClicked()
{
    card.prev();
    showCard();
}

void MainWindow::onButtonNextClicked()
{
    card.next();
    showCard();
}

void MainWindow::onButtonEnglishClicked()
{
    playingVideo = false;
    mediaPlayer->setMedia(QUrl::fromLocalFile(card.englishAudio()));
    mediaPlayer->play();
}

void MainWindow::onButtonRussianClicked()
{
    playingVideo = false;
    mediaPlayer->setMedia(QUrl::fromLocalFile(card.russianAudio()));
    mediaPlayer->play();
}

void MainWindow::onButtonVideoClicked()
{
    playingVideo = true;
    mediaPlayer->setMedia(QUrl::fromLocalFile(card.video()));
    mediaPlayer->play();
}

void MainWindow::onVideoStateChanged(QMediaPlayer::State state)
{
    ui->stackedPictureVideo->setCurrentIndex(playingVideo && state == QMediaPlayer::PlayingState ? 1 : 0);
}

void MainWindow::showCard()
{
    ui->buttonEnglish->setText(card.english());
    ui->buttonRussian->setText(card.russian());
    ui->labelPicture->setPixmap(QPixmap(card.picture()).scaled(ui->labelPicture->size(), Qt::KeepAspectRatio));
    ui->buttonVideo->setVisible(card.video() != "");
    playingVideo = false;
    mediaPlayer->stop();
}

void MainWindow::onActionAboutProgramTriggered()
{
    QMessageBox::about(this,
                       "О программе",
                       "Программа \"Английские карточки\".\n\nВыбирайте карточки с помощью боковых клавиш '<<' '>>'\n"
                       "Верхняя и нижняя кнопки выводят звук.\n"
                       "Для некоторых карточек доступно видео.\n\n"
                       "Автор: Ильшат.\ne-mail: lefrostx@gmail.com\nДата: 21.09.16.");
}
