#ifndef EDITDIALOGWINDOW_H
#define EDITDIALOGWINDOW_H

#include <QDialog>
#include "table.h"

namespace Ui {
class EditDialogWindow;
}

class EditDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialogWindow(QWidget *parent = nullptr);
    ~EditDialogWindow();
    void setTable(Table *node);

private slots:
    void on_btnEdit_clicked();


    void on_pushButtonBack_clicked();

private:
    Ui::EditDialogWindow *ui;
    Table *root;
};

#endif // EDITDIALOGWINDOW_H
