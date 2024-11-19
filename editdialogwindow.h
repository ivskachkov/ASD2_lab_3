#ifndef EDITDIALOGWINDOW_H
#define EDITDIALOGWINDOW_H

#include <QDialog>

namespace Ui {
class EditDialogWindow;
}

class EditDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialogWindow(QWidget *parent = nullptr);
    ~EditDialogWindow();

private:
    Ui::EditDialogWindow *ui;
};

#endif // EDITDIALOGWINDOW_H
