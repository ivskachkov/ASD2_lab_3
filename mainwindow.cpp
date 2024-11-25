#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    adddialogwindow(new AddDialogWindow(this)),
    searchdialogwindow(new SearchDialogWindow(this)),
    editdialogwindow(new EditDialogWindow(this)),
    deletedialogwindow(new DeleteDialogWindow(this)),
    root(new Table)
{
    ui->setupUi(this);
    searchdialogwindow->setTable(root);
    adddialogwindow->setTable(root);
    editdialogwindow->setTable(root);
    deletedialogwindow->setTable(root);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAdd_clicked()
{
    adddialogwindow->show();
}

void MainWindow::on_pushButtonSearch_clicked()
{
    searchdialogwindow->show();
}


void MainWindow::on_pushButtonEdit_clicked()
{
    editdialogwindow->show();
}

void MainWindow::on_pushButtonDelete_clicked()
{
    deletedialogwindow->show();
}

void MainWindow::on_actionOpen_triggered(){
    qDebug() << "Open triggered";
    root->LoadFromFile("db.txt");
}

void MainWindow::on_actionSave_triggered(){
    qDebug() << "Save triggered";
    root->SaveToFile("db.txt");
}




