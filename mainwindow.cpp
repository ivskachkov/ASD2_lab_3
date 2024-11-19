#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    adddialogwindow(new AddDialogWindow(this)),
    searchdialogwindow(new SearchDialogWindow(this)),
    editdialogwindow(new EditDialogWindow(this)),
    deletedialogwindow(new DeleteDialogWindow(this))
{
    ui->setupUi(this);
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

