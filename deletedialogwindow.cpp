#include "deletedialogwindow.h"
#include "ui_deletedialogwindow.h"

DeleteDialogWindow::DeleteDialogWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DeleteDialogWindow)
{
    ui->setupUi(this);
}

DeleteDialogWindow::~DeleteDialogWindow()
{
    delete ui;
}
