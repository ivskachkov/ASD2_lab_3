#ifndef SEARCHDIALOGWINDOW_H
#define SEARCHDIALOGWINDOW_H

#include <QDialog>

namespace Ui {
class SearchDialogWindow;
}

class SearchDialogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialogWindow(QWidget *parent = nullptr);
    ~SearchDialogWindow();

private:
    Ui::SearchDialogWindow *ui;
};

#endif // SEARCHDIALOGWINDOW_H
