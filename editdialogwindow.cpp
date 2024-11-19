#include "editdialogwindow.h"
#include "ui_editdialogwindow.h"

EditDialogWindow::EditDialogWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditDialogWindow)
{
    ui->setupUi(this);
}

EditDialogWindow::~EditDialogWindow()
{
    delete ui;
}
