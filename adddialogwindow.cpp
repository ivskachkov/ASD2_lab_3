#include "adddialogwindow.h"
#include "ui_adddialogwindow.h"

AddDialogWindow::AddDialogWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddDialogWindow),
    root(nullptr)
{
    ui->setupUi(this);
}

AddDialogWindow::~AddDialogWindow()
{
    delete ui;
}

void AddDialogWindow::setTable(Table *node)
{
    root = node;
}

void AddDialogWindow::on_btnAdd_clicked()
{
    if(root != nullptr){
        auto value = ui->inputText->text().toStdString();
        root->insert(value);
    }
}


void AddDialogWindow::on_pushButtonBack_clicked()
{
    AddDialogWindow::hide();
}

