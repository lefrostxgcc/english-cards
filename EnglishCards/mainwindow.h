#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include "card.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void onButtonPrevClicked();
    void onButtonNextClicked();
    void onButtonEnglishClicked();
    void onButtonRussianClicked();
    void onButtonVideoClicked();
    void onVideoStateChanged(QMediaPlayer::State state);

private:
    void showCard();

    Ui::MainWindow *ui;
    EnglishCards::Card card;
    QMediaPlayer *mediaPlayer;
    QVideoWidget *video;
};

#endif // MAINWINDOW_H
