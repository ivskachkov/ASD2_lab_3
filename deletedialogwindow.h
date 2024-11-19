#ifndef DELETEDIALOGWINDOW_H
#define DELETEDIALOGWINDOW_H

#include <QDialog>

namespace Ui {
class DeleteDialogWindow;
}

class DeleteDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteDialogWindow(QWidget *parent = nullptr);
    ~DeleteDialogWindow();

private:
    Ui::DeleteDialogWindow *ui;
};

#endif // DELETEDIALOGWINDOW_H
