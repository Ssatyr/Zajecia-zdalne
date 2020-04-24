#include "mainwindow.h"
#include "ui_mainwindow.h"

double calcVal = 0.0;
bool diTrigger = false;
bool muTrigger = false;
bool suTrigger = false;
bool adTrigger = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Display->setText(QString::number(calcVal));
    QPushButton *numButtons[10];
    for(int i = 0; i < 10; i++){
        QString butName = "Button" + QString::number(i);
        numButtons[i] = MainWindow::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this,
                SLOT(NumPressed()));
    }

    connect(ui->ButtonAd, SIGNAL(released()), this,
            SLOT(Action()));
    connect(ui->ButtonSu, SIGNAL(released()), this,
            SLOT(Action()));
    connect(ui->ButtonMu, SIGNAL(released()), this,
            SLOT(Action()));
    connect(ui->ButtonDi, SIGNAL(released()), this,
            SLOT(Action()));
    connect(ui->ButtonEq, SIGNAL(released()), this,
            SLOT(EqualButton()));
    connect(ui->ButtonAC, SIGNAL(released()), this,
            SLOT(ACButton()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NumPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    QString displayVal = ui->Display->text();
    if((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0)){
        ui->Display->setText(butVal);
    } else {
        QString newVal = displayVal + butVal;
        double dblNewVal = newVal.toDouble();
        ui->Display->setText(QString::number(dblNewVal, 'g', 16));
    }
}

void MainWindow::Action(){
    diTrigger = false;
    muTrigger = false;
    suTrigger = false;
    adTrigger = false;
    QString displayVal = ui->Display->text();
    calcVal = displayVal.toDouble();
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button -> text();
    if(QString::compare(butVal, "/", Qt::CaseInsensitive) == 0){
        diTrigger = true;
    } else if (QString::compare(butVal, "*", Qt::CaseInsensitive) == 0){
        muTrigger = true;
    } else if (QString::compare(butVal, "+", Qt::CaseInsensitive) == 0){
        adTrigger = true;
    } else {
        suTrigger = true;
    }

    ui->Display->setText("");
}


void MainWindow::EqualButton(){
    double solution = 0.0;
    QString displayVal = ui->Display->text();
    double dblDisplayVal = displayVal.toDouble();
    if(adTrigger || suTrigger || muTrigger || diTrigger){
        if(adTrigger){
            solution = calcVal + dblDisplayVal;
        } else if(diTrigger){
            solution = calcVal / dblDisplayVal;
        } else if(muTrigger){
            solution = calcVal * dblDisplayVal;
        } else {
            solution = calcVal - dblDisplayVal;
        }
    }
    ui->Display->setText(QString::number(solution));
}

void MainWindow::ACButton(){
    ui->Display->setText("");
    diTrigger = false;
    muTrigger = false;
    suTrigger = false;
    adTrigger = false;
}
