#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
