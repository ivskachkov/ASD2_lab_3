#include "editdialogwindow.h"
#include "ui_editdialogwindow.h"

EditDialogWindow::EditDialogWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditDialogWindow),
    root(nullptr)
{
    ui->setupUi(this);
}

EditDialogWindow::~EditDialogWindow()
{
    delete ui;
}

void EditDialogWindow::setTable(Table *node)
{
    root = node;
}

void EditDialogWindow::on_btnEdit_clicked()
{
    bool ok;
    auto i = ui->inputIndex->text().toInt(&ok);
    if(!ok){
        ui->resultLBL->setText("Уведіть ціле число.");
    }
    if(root != nullptr){
        int iteration = 0;
        auto result = ui->inputText->text().toStdString();
        root->edit(i, result, iteration);
        ui->iteration->setText(QString::number(iteration));
    }
}


void EditDialogWindow::on_pushButtonBack_clicked()
{
    EditDialogWindow::hide();
}

