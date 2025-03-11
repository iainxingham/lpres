#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include "code128/code128item.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QGraphicsScene barcodeScene;
    Code128Item *m_Barcode;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();

    void on_barcodeButton_clicked();

    void on_clearButton_clicked();

    void on_lpresButton_clicked();

    void on_pacsButton_clicked();

    void on_clipboardButton_clicked();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
