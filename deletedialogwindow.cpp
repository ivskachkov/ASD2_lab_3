#include "deletedialogwindow.h"
#include "ui_deletedialogwindow.h"

DeleteDialogWindow::DeleteDialogWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DeleteDialogWindow),
    root(nullptr)
{
    ui->setupUi(this);
}

DeleteDialogWindow::~DeleteDialogWindow()
{
    delete ui;
}

void DeleteDialogWindow::setTable(Table *node)
{
    root = node;
}

void DeleteDialogWindow::on_btnDelete_clicked()
{
    bool ok;
    auto i = ui->inputIndex->text().toInt(&ok);
    if(!ok){
        ui->resultLBL->setText("Уведіть ціле число.");
        return;
    }
    if(root != nullptr){
        if(root->remove(i)){
            ui->resultLBL->setText("Запис " + QString::number(i) + " видалено");
        }else{
            ui->resultLBL->setText("Запис не знайдено/не видалено");
        }
    }else{
        ui->resultLBL->setText("Дерево порожнє");
    }
}


void DeleteDialogWindow::on_pushButtonBack_clicked()
{
    DeleteDialogWindow::hide();
}

