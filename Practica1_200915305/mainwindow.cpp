#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <estructuras.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;
using std::cout;
using std::endl;

ColaAviones *Cola =new ColaAviones();
int contador_Aviones=0;
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

void MainWindow::Graficar_Estructuras(){
    Cola->Graficar_Cola_Aviones();
    QPixmap pix("/home/debian9/Escritorio/Practica1_200915305/Cola_Aviones.png");
    ui->label_2->setPixmap(pix);
}



void MainWindow::on_pushButton_2_clicked()///Eliminar de Cola..
{
    Cola->Eliminar_Cola_Aviones();
    Cola->Graficar_Cola_Aviones();
    QPixmap pix("/home/debian9/Escritorio/Practica1_200915305/Cola_Aviones.png");
    ui->label_2->setPixmap(pix);
}

void MainWindow::on_pushButton_3_clicked()///TURNOS......
{
    srand(time(NULL));
    contador_Aviones++;
    ///Probabilidad de los aviones.....
    ///
    int num[10]={1,2,3,1,2,3,1,2,3,1};
    int random=0+rand()%(10);
    int avion= num[random];
    cout<<avion<<","<<random<<endl;
    ///Avion Pequeño = 1 = 0.4
    ///Avion Mediano = 2 = 0.3
    ///Avion Grande  = 3 = 0.3

    if(avion==1){///Agregar un Avion Pequeño...
        int pasajeros1 = 5+rand()%(10-5);
        int mantenimiento1 = 1+rand()%(4-1);
        Cola->Agregar_Cola_Aviones(contador_Aviones,"Pequeño",pasajeros1,1,mantenimiento1);

    }else if(avion==2){///Agregar un Avion Mediano...
        int pasajeros2 = 15+rand()%(25-15);
        int mantenimiento2 = 2+rand()%(5-2);
        Cola->Agregar_Cola_Aviones(contador_Aviones,"Mediano",pasajeros2,2,mantenimiento2);

    }else{///Agregar un Avion Grande...
        int pasajeros3 = 30+rand()%(40-30);
        int mantenimiento3 = 3+rand()%(7-3);
        Cola->Agregar_Cola_Aviones(contador_Aviones,"Grande",pasajeros3,3,mantenimiento3);

    }

    Graficar_Estructuras();
}




























