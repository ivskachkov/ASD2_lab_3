#ifndef ADDDIALOGWINDOW_H
#define ADDDIALOGWINDOW_H

#include <QDialog>

namespace Ui {
class AddDialogWindow;
}

class AddDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialogWindow(QWidget *parent = nullptr);
    ~AddDialogWindow();

private:
    Ui::AddDialogWindow *ui;
};

#endif // ADDDIALOGWINDOW_H
