#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <estructuras.h>

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <sstream>
#include <QPlainTextEdit>
#include <QString>

using namespace std;
using std::cout;
using std::endl;
stringstream ss;

ColaAviones *Cola =new ColaAviones();
ColaEscritorios *Escri = new ColaEscritorios();
ColaPasajeros *pasajeros = new ColaPasajeros();
Estacion *estacion= new Estacion();
Estacion *estaciones = new Estacion();
Maletas *maleta =new Maletas();
QString TextoSalida="";
int ContadorTurnos=0;


int contador_Aviones=0;
int Cantidad_Aviones=0;
int Cantidad_Escritorios=0;
int Cantidad_Mantenimiento=0;
int Cantidad_Turnos=0;
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
    TextoSalida.append("********************EMPEZO LA SIMULACION********************\n");
    string Aviones=ui->lineEdit->text().toUtf8().constData();
    string Escritorios=ui->lineEdit_2->text().toUtf8().constData();
    string Mantenimiento=ui->lineEdit_3->text().toUtf8().constData();
    string CantTurnos=ui->lineEdit_5->text().toUtf8().constData();
    Cantidad_Aviones=atoi(Aviones.c_str());
        TextoSalida.append("Se Agregaron ");
        QString s = QString::number(Cantidad_Aviones);
        TextoSalida.append(s);
        TextoSalida.append(" Aviones\n");
    Cantidad_Escritorios=atoi(Escritorios.c_str());
        TextoSalida.append("Se Agregaron ");
        s = QString::number(Cantidad_Escritorios);
        TextoSalida.append(s);
        TextoSalida.append(" Escritorios\n");
    Cantidad_Mantenimiento=atoi(Mantenimiento.c_str());
        TextoSalida.append("Se Agregaron ");
        s = QString::number(Cantidad_Mantenimiento);
        TextoSalida.append(s);
        TextoSalida.append(" Estaciones de Mantenimiento\n");
    Cantidad_Turnos=atoi(CantTurnos.c_str());

    cout<<"Aviones...."<<Cantidad_Aviones<<endl;
    ui->lineEdit->setDisabled(true);
    ui->lineEdit_2->setDisabled(true);
    ui->lineEdit_3->setDisabled(true);
    ui->pushButton_2->setDisabled(true);
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
        TextoSalida.append("Se Agrego el Escritorio ");
        TextoSalida.append(letra);
        TextoSalida.append("\n");
        Escri->Agregar_Cola_Escritorios(letra,0);


    }

    for(int i=1;i<=Cantidad_Mantenimiento;i++){
        QString s = QString::number(i);
        TextoSalida.append("Se Agrego la Estacion");
        TextoSalida.append(s);
        TextoSalida.append("\n");
        estaciones->Agregar_Estacion(i,0,0);
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
                TextoSalida.append("Aterrizo un Avion PEQUEÑO\n");
                TextoSalida.append("Cantidad de Pasajeros: ");
                 QString ss = QString::number(pasajeros1);
                 TextoSalida.append(ss);
                 TextoSalida.append("\n");
                TextoSalida.append("Turnos en Mantenimiento : ");
                 ss = QString::number(mantenimiento1);
                 TextoSalida.append(ss);
                 TextoSalida.append("\n\n");
                Cantidad_Aviones--;

            }else if(avion==2){///Agregar un Avion Mediano...
                int pasajeros2 = 15+rand()%(25-15);
                int mantenimiento2 = 2+rand()%(5-2);
                Cola->Agregar_Cola_Aviones(contador_Aviones,"Mediano",pasajeros2,2,mantenimiento2);
                TextoSalida.append("Aterrizo un Avion MEDIANO\n");
                TextoSalida.append("Cantidad de Pasajeros: ");
                QString ss = QString::number(pasajeros2);
                TextoSalida.append(ss);
                TextoSalida.append("\n");
               TextoSalida.append("Turnos en Mantenimiento : ");
                ss = QString::number(mantenimiento2);
                TextoSalida.append(ss);
                TextoSalida.append("\n\n");
                Cantidad_Aviones--;

            }else{///Agregar un Avion Grande...
                int pasajeros3 = 30+rand()%(40-30);
                int mantenimiento3 = 3+rand()%(7-3);
                Cola->Agregar_Cola_Aviones(contador_Aviones,"Grande",pasajeros3,3,mantenimiento3);
                TextoSalida.append("Aterrizo un Avion GRANDE\n");
                TextoSalida.append("Cantidad de Pasajeros: ");
                QString ss = QString::number(pasajeros3);
                TextoSalida.append(ss);
                TextoSalida.append("\n");
               TextoSalida.append("Turnos en Mantenimiento : ");
                ss = QString::number(mantenimiento3);
                TextoSalida.append(ss);
                TextoSalida.append("\n\n");
                Cantidad_Aviones--;

             }

    Graficar_Estructuras();

    }else{
        cout<<"Se Terminaron los Aviones..."<<endl;
    }




}

void MainWindow::on_pushButton_3_clicked()///TURNOS......
{
    ContadorTurnos++;

    QString s = QString::number(ContadorTurnos);
    ui->lineEdit_4->setText(s);
    TextoSalida.append("*****************************TURNO # ");
    TextoSalida=TextoSalida+s;
    TextoSalida.append("******************************\n");
    Turnos();
    Escri->Verificar_Turnos_Escritoios();
    pasajeros->Verificar_Turnos_Pasajeros();
    estacion->Verificar_Estacion();
    Cola->Verificar_Turnos();
    Escri->Mostrar_Cola_Escritorios();
    Graficar_Estructuras();

    QString Aviones=Cola->ConsolaAviones();
    TextoSalida.append(Aviones);
    TextoSalida.append("\n");

    QString Personas=pasajeros->Consola_COla_Pasajeros();
    TextoSalida.append(Personas);
    TextoSalida.append("\n");

    QString Escritorios=Escri->Consola_Cola_Escritorios();
    TextoSalida.append(Escritorios);
    TextoSalida.append("\n");

    QString Cant_Maletas = maleta->Consola_Maletas();
    TextoSalida.append(Cant_Maletas);
    TextoSalida.append("\n");




    TextoSalida.append("************************FIN DEL TURNO # ");
    TextoSalida.append(s);
    TextoSalida.append("*************************\n\n");
    ui->textEdit->setText(TextoSalida);
    if(ContadorTurnos==Cantidad_Turnos){
        ui->pushButton_3->setDisabled(true);
    }
}



void MainWindow::on_pushButton_clicked()///Habilitar
{
    ui->lineEdit->setDisabled(false);
    ui->lineEdit_2->setDisabled(false);
    ui->lineEdit_3->setDisabled(false);
    ui->pushButton_2->setDisabled(false);
}


