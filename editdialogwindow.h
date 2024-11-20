#ifndef EDITDIALOGWINDOW_H
#define EDITDIALOGWINDOW_H

#include <QDialog>
#include "db.h"

namespace Ui {
class EditDialogWindow;
}

class EditDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialogWindow(QWidget *parent = nullptr);
    ~EditDialogWindow();
    void setNode(Node *node);

private:
    Ui::EditDialogWindow *ui;
    Node *root;
};

#endif // EDITDIALOGWINDOW_H
