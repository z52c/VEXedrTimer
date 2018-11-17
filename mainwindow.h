#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QShortcut>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showLCD(int a);

private slots:
    void on_pushButtonZidong_clicked();

    void on_pushButtonShoudong_clicked();

    void on_pushButtonJineng_clicked();
    void timerOut();

    void on_pushButton_clicked();

    void on_pushButtonPause_clicked();

private:
    Ui::MainWindow *ui;
    int end;
    QTimer *timer1;
    bool pause;
    bool working;
    QShortcut *shortcutZidong;
    QShortcut *shortcutShoudong;
    QShortcut *shortcutJineng;

    QShortcut *shortcutZanting;
};

#endif // MAINWINDOW_H
