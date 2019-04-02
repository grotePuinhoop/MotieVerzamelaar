#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "getpages.h"

GetPages *myGetPages=nullptr;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    myGetPages = new GetPages();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete myGetPages;
    delete ui;
}
