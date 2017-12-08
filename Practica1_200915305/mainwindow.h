#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void Turnos();
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void Graficar_Estructuras();



    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
