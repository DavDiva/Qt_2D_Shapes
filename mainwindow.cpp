#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAstroid_clicked()
{
    // change background color for render area
    // add a function to change the background color
    this->ui->renderArea->setShape(RenderArea::Astroid);
    //this->ui->renderArea->setBackgroundColor(QColorConstants::Red);
    this->ui->renderArea->repaint();
}

void MainWindow::on_btnCycloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);
    //this->ui->renderArea->setBackgroundColor(QColorConstants::Green);
    this->ui->renderArea->repaint();

}

void MainWindow::on_btnHuygens_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HuygensCycloid);
    //this->ui->renderArea->setBackgroundColor(QColorConstants::Blue);
    this->ui->renderArea->repaint();

}

void MainWindow::on_btnHypo_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HypoCycloid);
    //this->ui->renderArea->setBackgroundColor(QColorConstants::Yellow);
    this->ui->renderArea->repaint();

}