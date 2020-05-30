#include "mainwindow.h"
#include "ui_mainwindow.h"

int a,b,wynik;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->losuj, SIGNAL(released()), this,
                SLOT(losuj()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::losuj(){
    a = ui->liczbamin->text().toDouble();
    b = ui->liczbamax->text().toDouble();
    QString s2;
    if (a < b ){
        wynik = (rand()%(a-b))+a;
        s2 = QString::number(wynik);
    }
    else{
        wynik = (rand()%(b-a))+b;
        s2 = QString::number(wynik);
    }
    ui->wynik->setText(s2);
}
