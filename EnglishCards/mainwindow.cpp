#include "mainwindow.h"
#include "ui_mainwindow.h"

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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonPrevClicked()
{

}

void MainWindow::onButtonNextClicked()
{

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
