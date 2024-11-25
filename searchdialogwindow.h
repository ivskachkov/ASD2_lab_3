#ifndef SEARCHDIALOGWINDOW_H
#define SEARCHDIALOGWINDOW_H

#include <QDialog>
#include "table.h"

namespace Ui {
class SearchDialogWindow;
}

class SearchDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialogWindow(QWidget *parent = nullptr);
    ~SearchDialogWindow();
    void setTable(Table *node);

private slots:
    void on_btnSearch_clicked();

    void on_pushButtonBack_clicked();

private:
    Ui::SearchDialogWindow *ui;
    Table *root;
};

#endif // SEARCHDIALOGWINDOW_H
