#ifndef SEARCHDIALOGWINDOW_H
#define SEARCHDIALOGWINDOW_H

#include <QDialog>
#include "db.h"

namespace Ui {
class SearchDialogWindow;
}

class SearchDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialogWindow(QWidget *parent = nullptr);
    ~SearchDialogWindow();
    void setNode(Node *node);

private slots:
    void on_btnSearch_clicked();

private:
    Ui::SearchDialogWindow *ui;
    Node *root;
};

#endif // SEARCHDIALOGWINDOW_H
