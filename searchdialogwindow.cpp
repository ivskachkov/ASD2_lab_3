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

void SearchDialogWindow::setTable(Table *node)
{
    root = node;
}



void SearchDialogWindow::on_btnSearch_clicked()
{
    bool ok;
    auto i = ui->inputIndex->text().toInt(&ok);
    if(!ok){
        ui->resultLBL->setText("Уведіть ціле число.");
    }
    if(root != nullptr){
        auto result = root->search(i);
        if(result.first != 0){
            ui->resultLBL->setText("Запис за індексом: " + QString::fromStdString(result.second));
        }else{
            ui->resultLBL->setText("Відповідь не знайдено");
        }
    }
}


void SearchDialogWindow::on_pushButtonBack_clicked()
{
    SearchDialogWindow::hide();
}

