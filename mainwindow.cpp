#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Queue.h>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    queint = new Queue<int>(10,true);
 //   questr = new Queue<QString>(10,false);
    queint = new Queue<int> (10);
    questr = new Queue<QString> (10);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()                     //int!!!
{
    // stack->push(ui->spinBox->value());
    queint->enqueue(ui->spinBox->value());
}

void MainWindow::on_pushButton_3_clicked()
{

   // ui->label->setText(QString::number( intQueue.dequeue()));
    ui->label->setText(QString::number(queint->dequeue()));
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->label->setText(QString::number(queint->getSize()));
}

void MainWindow::on_pushButton_2_clicked()
{
    queint->print();
}

void MainWindow::on_pushButton_7_clicked()
{
    queint->Deletion();
}

void MainWindow::on_pushButton_4_clicked()                  //str!!!
{
    questr->enqueue(ui->lineEdit->text());
}

void MainWindow::on_pushButton_6_clicked()
{
    questr->print();
}

void MainWindow::on_pushButton_8_clicked()
{
    questr->Deletion();
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->label_2->setText(QString::number(questr->getSize()));
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->label_2->setText(questr->dequeue());
}
