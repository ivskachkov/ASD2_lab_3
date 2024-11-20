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
    root(new Node)
{
    ui->setupUi(this);
    searchdialogwindow->setNode(root);
    adddialogwindow->setNode(root);
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
    QString s = read();
}

void MainWindow::on_actionSave_triggered(){
    qDebug() << "Save triggered";
}

QString MainWindow::read()
{
    QString data;
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open File"), "/home/ivan/Qt/popitka/build", tr("Text files (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return data;

    QTextStream in(&file);
    data = in.readAll();

    file.close();
    return data;
}

void MainWindow::write(QString data)
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save file"), "/home/ivan/Qt/popitka/build", tr("Text files (*.txt)"));
    QFile file(fileName + ".txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << data;
    file.close();
}


