#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->buttonPrevCard, &QPushButton::clicked, this, &MainWindow::onButtonPrevClicked);
    connect(ui->buttonNextCard, &QPushButton::clicked, this, &MainWindow::onButtonNextClicked);
    connect(ui->buttonEnglish,  &QPushButton::clicked, this, &MainWindow::onButtonEnglishClicked);
    connect(ui->buttonRussian,  &QPushButton::clicked, this, &MainWindow::onButtonRussianClicked);
    connect(ui->buttonVideo,    &QPushButton::clicked, this, &MainWindow::onButtonVideoClicked);
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

}

void MainWindow::onButtonRussianClicked()
{

}

void MainWindow::onButtonVideoClicked()
{

}

void MainWindow::showCard()
{
    ui->buttonEnglish->setText(card.english());
    ui->buttonRussian->setText(card.russian());
    ui->labelPicture->setPixmap(QPixmap(card.picture()).scaled(QSize(300, 300), Qt::KeepAspectRatio));
}
