#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <estructuras.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <sstream>

using namespace std;
using std::cout;
using std::endl;
stringstream ss;

ColaAviones *Cola =new ColaAviones();
ColaEscritorios *Escri = new ColaEscritorios();
ColaPasajeros *pasajeros = new ColaPasajeros();
int contador_Aviones=0;
int Cantidad_Aviones=0;
int Cantidad_Escritorios=0;
int Cantidad_Mantenimiento=0;
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



void MainWindow::on_pushButton_2_clicked()///Simulacion..
{
    string Aviones=ui->lineEdit->text().toUtf8().constData();
    string Escritorios=ui->lineEdit_2->text().toUtf8().constData();
    string Mantenimiento=ui->lineEdit_2->text().toUtf8().constData();
    Cantidad_Aviones=atoi(Aviones.c_str());
    Cantidad_Escritorios=atoi(Escritorios.c_str());
    Cantidad_Mantenimiento=atoi(Mantenimiento.c_str());
    cout<<"Aviones...."<<Cantidad_Aviones<<endl;
    ui->lineEdit->setDisabled(true);
    ui->lineEdit_2->setDisabled(true);
    ui->lineEdit_3->setDisabled(true);
    char *letra;
    for(int i=1; i<=Cantidad_Escritorios; i++){

        if(i==1){
           letra="Z";
        }else if(i==2){
           letra="X";
        }else if(i==3){
           letra="C";
        }else if(i==4){
           letra="D";
        }else if(i==5){
           letra="E";
        }else if(i==6){
           letra="F";
        }else if(i==7){
            letra="G";
         }else if(i==8){
            letra="H";
         }else if(i==9){
            letra="I";
         }else if(i==10){
            letra="J";
         }else if(i==11){
            letra="K";
         }else if(i==12){
            letra="L";
         }else if(i==13){
            letra="M";
         }else if(i==14){
            letra="N";
         }else if(i==15){
            letra="O";
         }else if(i==16){
            letra="P";
         }else if(i==17){
            letra="Q";
         }else if(i==18){
            letra="R";
         }else if(i==19){
            letra="S";
         }else if(i==20){
            letra="T";
         }else if(i==21){
            letra="U";
         }else if(i==22){
            letra="V";
         }else if(i==23){
            letra="W";
         }else if(i==24){
            letra="X";
         }else if(i==25){
            letra="Y";
         }else if(i==26){
            letra="Z";
         }
        Escri->Agregar_Cola_Escritorios(letra,0);


    }

    Turnos();

}

void MainWindow::Turnos(){
    if(Cantidad_Aviones>0){
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
                Cantidad_Aviones--;

            }else if(avion==2){///Agregar un Avion Mediano...
                int pasajeros2 = 15+rand()%(25-15);
                int mantenimiento2 = 2+rand()%(5-2);
                Cola->Agregar_Cola_Aviones(contador_Aviones,"Mediano",pasajeros2,2,mantenimiento2);
                Cantidad_Aviones--;

            }else{///Agregar un Avion Grande...
                int pasajeros3 = 30+rand()%(40-30);
                int mantenimiento3 = 3+rand()%(7-3);
                Cola->Agregar_Cola_Aviones(contador_Aviones,"Grande",pasajeros3,3,mantenimiento3);
                Cantidad_Aviones--;

             }

    Graficar_Estructuras();

    }else{
        cout<<"Se Terminaron los Aviones..."<<endl;
    }


}

void MainWindow::on_pushButton_3_clicked()///TURNOS......
{
    Turnos();
    pasajeros->Verificar_Turnos_Pasajeros();
    Cola->Verificar_Turnos();
    Escri->Mostrar_Cola_Escritorios();
    Graficar_Estructuras();
}



void MainWindow::on_pushButton_clicked()///Habilitar
{
    ui->lineEdit->setDisabled(false);
    ui->lineEdit_2->setDisabled(false);
    ui->lineEdit_3->setDisabled(false);
}


