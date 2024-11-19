#include "searchdialogwindow.h"
#include "ui_searchdialogwindow.h"

SearchDialogWindow::SearchDialogWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SearchDialogWindow)
{
    ui->setupUi(this);
}

SearchDialogWindow::~SearchDialogWindow()
{
    delete ui;
}
