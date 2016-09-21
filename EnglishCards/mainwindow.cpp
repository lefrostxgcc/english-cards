#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mediaPlayer = new QMediaPlayer(this);

    connect(ui->buttonPrevCard, &QPushButton::clicked,          this, &MainWindow::onButtonPrevClicked);
    connect(ui->buttonNextCard, &QPushButton::clicked,          this, &MainWindow::onButtonNextClicked);
    connect(ui->buttonEnglish,  &QPushButton::clicked,          this, &MainWindow::onButtonEnglishClicked);
    connect(ui->buttonRussian,  &QPushButton::clicked,          this, &MainWindow::onButtonRussianClicked);
    connect(ui->buttonVideo,    &QPushButton::clicked,          this, &MainWindow::onButtonVideoClicked);
    connect(mediaPlayer,        &QMediaPlayer::stateChanged,    this, &MainWindow::onVideoStateChanged);

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
    mediaPlayer->setMedia(QUrl::fromLocalFile(card.englishAudio()));
    mediaPlayer->play();
}

void MainWindow::onButtonRussianClicked()
{
    mediaPlayer->setMedia(QUrl::fromLocalFile(card.russianAudio()));
    mediaPlayer->play();
}

void MainWindow::onButtonVideoClicked()
{
    ui->stackedPictureVideo->setCurrentIndex(1);
    mediaPlayer->setMedia(QUrl::fromLocalFile(card.video()));
    mediaPlayer->play();
}

void MainWindow::onVideoStateChanged(QMediaPlayer::State state)
{
    ui->stackedPictureVideo->setCurrentIndex(state == QMediaPlayer::PlayingState ? 1 : 0);
}

void MainWindow::showCard()
{
    ui->buttonEnglish->setText(card.english());
    ui->buttonRussian->setText(card.russian());
    ui->labelPicture->setPixmap(QPixmap(card.picture()).scaled(QSize(300, 300), Qt::KeepAspectRatio));
    ui->buttonVideo->setVisible(card.video() != "");
}
