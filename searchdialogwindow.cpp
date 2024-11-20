#include "searchdialogwindow.h"
#include "ui_searchdialogwindow.h"

SearchDialogWindow::SearchDialogWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SearchDialogWindow),
    root(nullptr)
{
    ui->setupUi(this);
}

SearchDialogWindow::~SearchDialogWindow()
{
    delete ui;
}

void SearchDialogWindow::setNode(Node *node)
{
    root = node;
}



void SearchDialogWindow::on_btnSearch_clicked()
{
    int i = ui->inputIndex->text().toInt();
    if(root != nullptr){
        auto result = search(root, i);
        if(result.first != 0){
            ui->resultLBL->setText(QString::fromStdString(result.second));
        }else{
            ui->resultLBL->setText("Відповідь не знайдено");
        }
    }
}

