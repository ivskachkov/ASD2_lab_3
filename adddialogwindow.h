#ifndef ADDDIALOGWINDOW_H
#define ADDDIALOGWINDOW_H

#include <QDialog>
#include "table.h"

namespace Ui {
class AddDialogWindow;
}

class AddDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialogWindow(QWidget *parent = nullptr);
    ~AddDialogWindow();
    void setTable(Table *node);

private slots:
    void on_btnAdd_clicked();

    void on_pushButtonBack_clicked();

private:
    Ui::AddDialogWindow *ui;
    Table *root;
    int count;
};

#endif // ADDDIALOGWINDOW_H
