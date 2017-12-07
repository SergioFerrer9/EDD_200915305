#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <estructuras.h>

ColaAviones *Cola =new ColaAviones();
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;


}

void MainWindow::on_pushButton_clicked()///Agrear a Cola...
{

    Cola->Agregar_Cola_Aviones(1,"pequeño",1,1,1);
    Cola->Agregar_Cola_Aviones(2,"pequeño",2,1,1);
    Cola->Agregar_Cola_Aviones(4,"pequeño",3,1,1);
    Cola->Agregar_Cola_Aviones(5,"pequeño",4,1,1);
    Cola->Agregar_Cola_Aviones(7,"pequeño",5,1,1);
    /*Cola->Mostrar_Cola_Aviones();
    Cola->Eliminar_Cola_Aviones();
    Cola->Mostrar_Cola_Aviones();*/
    Cola->Mostrar_Cola_Aviones();
    Cola->Graficar_Cola_Aviones();
}

void MainWindow::on_pushButton_2_clicked()///Eliminar de Cola..
{

}
