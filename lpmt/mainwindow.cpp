#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QStatusBar>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    QString Octet = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
    lineEdit.setValidator(new QRegExpValidator(QRegExp("^" + Octet + "\\." + Octet + "\\." + Octet + "\\." + Octet + "$"), this));

    ui->setupUi(this);
    // add drop down menus (currently empty)
    menuBar()->addMenu("&File");
    menuBar()->addMenu("&Edit");
    menuBar()->addMenu("&View");
    menuBar()->addMenu("&Simulate");
    menuBar()->addMenu("&Help");

    // add status bar message
    statusBar()->showMessage("QSimulate has started");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
