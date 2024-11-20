#include "adddialogwindow.h"
#include "ui_adddialogwindow.h"

AddDialogWindow::AddDialogWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddDialogWindow),
    root(nullptr),
    count(0)
{
    ui->setupUi(this);
}

AddDialogWindow::~AddDialogWindow()
{
    delete ui;
}

void AddDialogWindow::setNode(Node *node)
{
    root = node;
}

void AddDialogWindow::on_btnAdd_clicked()
{
    if(root != nullptr){
        auto value = ui->inputText->text().toStdString();
        insert(root, count++, value);
    }
}

