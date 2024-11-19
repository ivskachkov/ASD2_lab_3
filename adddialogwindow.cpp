#include "adddialogwindow.h"
#include "ui_adddialogwindow.h"

AddDialogWindow::AddDialogWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddDialogWindow)
{
    ui->setupUi(this);
}

AddDialogWindow::~AddDialogWindow()
{
    delete ui;
}
