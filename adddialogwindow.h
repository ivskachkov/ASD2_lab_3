#ifndef ADDDIALOGWINDOW_H
#define ADDDIALOGWINDOW_H

#include <QDialog>
#include "db.h"

namespace Ui {
class AddDialogWindow;
}

class AddDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialogWindow(QWidget *parent = nullptr);
    ~AddDialogWindow();
    void setNode(Node *node);

private slots:
    void on_btnAdd_clicked();

private:
    Ui::AddDialogWindow *ui;
    Node *root;
    int count;
};

#endif // ADDDIALOGWINDOW_H
