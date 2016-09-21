#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private:
    void showCard();

    Ui::MainWindow *ui;
    EnglishCards::Card card;
};

#endif // MAINWINDOW_H
