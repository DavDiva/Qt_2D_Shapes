#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->spinScale->setValue(this->ui->renderArea->getScale());
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_ui()
{
    this->ui->spinScale->setValue(this->ui->renderArea->getScale());
}
void MainWindow::on_btnAstroid_clicked()
{

    this->ui->renderArea->setShape(RenderArea::Astroid);
    this->ui->renderArea->repaint();

    update_ui();
}

void MainWindow::on_btnCycloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);
    this->ui->renderArea->repaint();

    update_ui();
}

void MainWindow::on_btnHuygens_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HuygensCycloid);
    this->ui->renderArea->repaint();

    update_ui();
}

void MainWindow::on_btnHypo_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HypoCycloid);
    this->ui->renderArea->repaint();

    update_ui();
}

void MainWindow::on_btnLine_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Line);
    this->ui->renderArea->repaint();

    update_ui();
}

void MainWindow::on_spinScale_valueChanged(double scale)
{
    this->ui->renderArea->setScale(scale);
}
