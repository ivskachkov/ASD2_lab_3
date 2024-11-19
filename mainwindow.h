#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "adddialogwindow.h"
#include "searchdialogwindow.h"
#include "deletedialogwindow.h"
#include "editdialogwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonSearch_clicked();

    void on_pushButtonEdit_clicked();

    void on_pushButtonDelete_clicked();

private:
    Ui::MainWindow *ui;
    AddDialogWindow *adddialogwindow;
    SearchDialogWindow *searchdialogwindow;
    EditDialogWindow *editdialogwindow;
    DeleteDialogWindow *deletedialogwindow;
};
#endif // MAINWINDOW_H
