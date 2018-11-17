#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer1=new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(timerOut()));
    showLCD(0);
    pause=false;
    working=false;
    ui->pushButtonPause->setEnabled(false);
    shortcutZidong= new QShortcut(this);
    shortcutZidong->setKey(tr("1"));
    shortcutZidong->setAutoRepeat(false);
    connect(shortcutZidong,SIGNAL(activated()),this,SLOT(on_pushButtonZidong_clicked()));

    shortcutShoudong= new QShortcut(this);
    shortcutShoudong->setKey(tr("2"));
    shortcutShoudong->setAutoRepeat(false);
    connect(shortcutShoudong,SIGNAL(activated()),this,SLOT(on_pushButtonShoudong_clicked()));

    shortcutJineng= new QShortcut(this);
    shortcutJineng->setKey(tr("3"));
    shortcutJineng->setAutoRepeat(false);
    connect(shortcutJineng,SIGNAL(activated()),this,SLOT(on_pushButtonJineng_clicked()));

    shortcutZanting= new QShortcut(this);
    shortcutZanting->setKey(tr(" "));
    shortcutZanting->setAutoRepeat(false);
    connect(shortcutZanting,SIGNAL(activated()),this,SLOT(on_pushButtonPause_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::showLCD(int a)
{
    int minute=a/60;
    int second=a%60;


    QString mString,sString;
    if(minute<10)
        mString=QString("0%1").arg(minute);
    else
        mString=QString("%1").arg(minute);
    if(second<10)
        sString=QString("0%1").arg(second);
    else
        sString=QString("%1").arg(second);
    QString tmp=QString("%1:%2").arg(mString).arg(sString);
    ui->lcdNumber->display(tmp);
}

void MainWindow::on_pushButtonZidong_clicked()
{
    pause=false;
    ui->pushButtonPause->setText("暂停");
    if(working)
    {
        timer1->stop();
    }
    working=true;
    end=15;
    showLCD(end);
    timer1->start(1000);
    ui->pushButtonJineng->setEnabled(false);
    ui->pushButtonShoudong->setEnabled(false);
    ui->pushButtonZidong->setEnabled(false);
    ui->pushButtonPause->setEnabled(true);
}

void MainWindow::on_pushButtonShoudong_clicked()
{
    pause=false;
    ui->pushButtonPause->setText("暂停");
    if(working)
    {
        timer1->stop();
    }
    working=true;
    end=105;
    showLCD(end);
    timer1->start(1000);
    ui->pushButtonJineng->setEnabled(false);
    ui->pushButtonShoudong->setEnabled(false);
    ui->pushButtonZidong->setEnabled(false);
    ui->pushButtonPause->setEnabled(true);
}

void MainWindow::on_pushButtonJineng_clicked()
{
    pause=false;
    ui->pushButtonPause->setText("暂停");
    if(working)
    {
        timer1->stop();
    }
    working=true;
    end=60;
    showLCD(end);
    timer1->start(1000);
    ui->pushButtonJineng->setEnabled(false);
    ui->pushButtonShoudong->setEnabled(false);
    ui->pushButtonZidong->setEnabled(false);
    ui->pushButtonPause->setEnabled(true);
}

void MainWindow::timerOut()
{
    end-=1;
    showLCD(end);
    if(end==0)
    {
        timer1->stop();
        ui->pushButtonJineng->setEnabled(true);
        ui->pushButtonShoudong->setEnabled(true);
        ui->pushButtonZidong->setEnabled(true);
        ui->pushButtonPause->setEnabled(false);
    }
}

void MainWindow::on_pushButton_clicked()
{
    working=false;
    timer1->stop();
    showLCD(0);
    ui->pushButtonJineng->setEnabled(true);
    ui->pushButtonShoudong->setEnabled(true);
    ui->pushButtonZidong->setEnabled(true);
    ui->pushButtonPause->setEnabled(false);
    pause=false;
    ui->pushButtonPause->setText("暂停");
}

void MainWindow::on_pushButtonPause_clicked()
{
    if(!working)
        return;
    if(pause)
    {
        timer1->start();
        pause=false;
        ui->pushButtonPause->setText("暂停");
    }else{
        timer1->stop();
        pause=true;
        ui->pushButtonPause->setText("继续");
    }
}
