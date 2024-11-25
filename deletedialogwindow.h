#ifndef DELETEDIALOGWINDOW_H
#define DELETEDIALOGWINDOW_H

#include <QDialog>
#include "table.h"

namespace Ui {
class DeleteDialogWindow;
}

class DeleteDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteDialogWindow(QWidget *parent = nullptr);
    ~DeleteDialogWindow();
    void setTable(Table *node);

private slots:
    void on_btnDelete_clicked();

    void on_pushButtonBack_clicked();

private:
    Ui::DeleteDialogWindow *ui;
    Table *root;
};

#endif // DELETEDIALOGWINDOW_H
