#ifndef DELETEDIALOGWINDOW_H
#define DELETEDIALOGWINDOW_H

#include <QDialog>
#include "db.h"

namespace Ui {
class DeleteDialogWindow;
}

class DeleteDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteDialogWindow(QWidget *parent = nullptr);
    ~DeleteDialogWindow();
    void setNode(Node *node);

private:
    Ui::DeleteDialogWindow *ui;
    Node *root;
};

#endif // DELETEDIALOGWINDOW_H
