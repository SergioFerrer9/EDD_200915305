#include "estructuras.h"
#include "mainwindow.h"
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <QString>

using namespace std;
using std::cout;
using std::endl;
ColaPasajeros *newPasajeros = new ColaPasajeros();
ColaEscritorios *newEscritorios = new ColaEscritorios();
NodoEscritorio *NodoEcritorio_ = new NodoEscritorio();
Maletas *newMaletas = new Maletas();
Estacion *newEstaciones = new Estacion();
ColaMantenimiento *newMantenimiento = new ColaMantenimiento();



FILE *gra;



///************************PUNTEROS DE LA COLA AVIONES*************************
typedef struct NodoColaAviones NodoCA;
NodoCA *primeroCA;
NodoCA *ultimoCA;

///************************PUNTEROS DE LA COLA DE PASAJEROS*******************
typedef struct NodoColaPasajeros NodoPA;
NodoPA *primeroPA;
NodoPA *ultimoPA;

///************************PUNTEROS DE LA COLA DE ESCRITORIOS*******************
typedef struct NodoEscritorio NodoES;
NodoES *primeroES;
NodoES *ultimoES;

///************************PUNTEROS DE LA COLA SIMPLE*******************
typedef struct NodoCola NodoC;

///************************PUNTEROS PILA DE LOS DOCUMENTOS*******************
typedef struct NodoPila NodoP;

///************************PUNTEROS AVION EN MANTENIMIENTO*******************
typedef struct NodoMantenimiento NodoMA;


///************************PUNTEROS LISTA DOBLE CIRCULAR*******************
typedef struct NodoMaleta NodoM;
NodoM *primeroM;
NodoM *ultimoM;

///************************PUNTEROS COLA SIMPLE DE LOS AVIONES*******************
typedef struct NodoEstacion NodoE;
NodoE *primeroE;
NodoE *ultimoE;


///************************PUNTEROS COLA SIMPLE DE LOS AVIONES*******************
typedef struct NodoColaMantenimiento NodoCM;
NodoCM *primeroCM;
NodoCM *ultimoCM;



///***********************AGREGAR A LA COLA AVIONES****************************
///
void ColaAviones::Agregar_Cola_Aviones(int Avion, char *Tipo, int Pasajeros, int Turno_D, int Turno_M){


    NodoCA *nuevo;
    nuevo=(NodoCA*)malloc(sizeof(struct NodoColaAviones));
    nuevo->Avion=Avion;
    nuevo->Tipo=Tipo;
    nuevo->Pasajeros=Pasajeros;
    nuevo->Turno_Desabordaje=Turno_D;
    nuevo->Turno_Mantenimiento=Turno_M;

    if(primeroCA==NULL){///Agregar el Primer Nodo a la Cola...
        nuevo->ant=NULL;
        nuevo->sig=NULL;
        primeroCA=nuevo;
        ultimoCA=nuevo;
    }else{ ///Agregar un nuevo nodo a la Cola...
        nuevo->sig=NULL;
        nuevo->ant=ultimoCA;
        ultimoCA->sig=nuevo;
        ultimoCA=nuevo;
    }

}
///*********************ELIMINAR DE LA COLA DE AVIONES*************************
///
void ColaAviones::Eliminar_Cola_Aviones(){
    if(primeroCA!=ultimoCA){
         newMantenimiento->Agregar_Cola_Mantenimiento(primeroCA);
         cout<<"....................ELIMINAR COLA AVIONES......"<<endl;
        primeroCA=primeroCA->sig;

    }else{
        newMantenimiento->Agregar_Cola_Mantenimiento(primeroCA);
        primeroCA=ultimoCA=NULL;
        cout<<"La Pila esta vacia..."<<endl;
    }

}

///**********************MOSTRAR COLA DE AVIONES********************************
///
void ColaAviones::Mostrar_Cola_Aviones(){
    NodoCA *aux=primeroCA;
    NodoCA *aux2=ultimoCA;
    cout<<"************************COLA AVIONES************************"<<endl;
    while(aux!=NULL){
        cout<<aux->Avion<<endl;
        aux=aux->sig;
    }
    cout<<""<<endl;

    while(aux2!=NULL){
        cout<<aux2->Avion<<endl;
        aux2=aux2->ant;
    }


}
QString ColaAviones::ConsolaAviones(){

    NodoCA *aux=primeroCA;
    QString informacion="";
    informacion.append("**************COLA DE AVIONES**************\n");
    QString s;
    QString ss;
    QString sss;

    int Avion;
    int Pasajeros;
    int Turnos;
    while(aux!=NULL){
        Avion=aux->Avion;
        s = QString::number(Avion);
        informacion.append("Avion: ");
        informacion.append(s);
        informacion.append("\n");
        Pasajeros=aux->Pasajeros;
        ss = QString::number(Pasajeros);
        informacion.append("Cantidad Pasajeros: ");
        informacion.append(ss);
        informacion.append("\n");
        Turnos=aux->Turno_Desabordaje;
        sss = QString::number(Turnos);
        informacion.append("Turnos en Espera: ");
        informacion.append(sss);
        informacion.append("\n\n");
        aux=aux->sig;
    }

    return informacion;

}

///*********************AGREGAR A LA COLA DE PASAJEROS***************************
///
void ColaPasajeros::Agregar_Cola_Pasajeros( int Avion, int Maletas, int Documentos, int Turnos){
    NodoPA *nuevo;
    nuevo=(NodoPA*)malloc(sizeof(struct NodoColaPasajeros));
    nuevo->Avion=Avion;
    nuevo->Maletas=Maletas;
    nuevo->Documentos=Documentos;
    nuevo->Turnos=Turnos;

    if(primeroPA==NULL){///Agregar el Primer Nodo a la Cola...
        nuevo->sig=primeroPA;
        primeroPA=nuevo;
        ultimoPA=nuevo;
    }else{ ///Agregar un nuevo nodo a la Cola...
        ultimoPA->sig=nuevo;
        nuevo->sig=NULL;
        ultimoPA=nuevo;
    }
}

///***********ELIMINAR DE LA COLA DE PASAJEROS*********************
///
void ColaPasajeros::Eliminar_Cola_Pasajeros(){
    Maletas *maleta = new Maletas();
    if(primeroPA!=ultimoPA){
        newEscritorios->Cola(primeroPA);
        for(int i=0;i<primeroPA->Maletas;i++){
            maleta->Agregar_Maleta();
         }
        cout<<"Agregando a Cola...."<<endl;
        primeroPA=primeroPA->sig;

    }else{

        maleta->Agregar_Maleta();
        primeroPA=ultimoPA=NULL;
        cout<<"La Cola de Pasajeros esta vacia..."<<endl;
    }


}

QString ColaPasajeros::Consola_COla_Pasajeros(){
    NodoPA *aux=primeroPA;
    QString informacion="";
    informacion.append("**************COLA DE LOS PASAJEROS**************\n");
    QString s;
    QString ss;
    QString sss;
    QString c;

    int Avion;
    int Pasajeros;
    int Turnos;
    int Contador=0;
    while(aux!=NULL){
        Contador++;
        s = QString::number(Contador);
        informacion.append("Pasajero: ");
        informacion.append(s);
        informacion.append("\n");
        Pasajeros=aux->Maletas;
        ss = QString::number(Pasajeros);
        informacion.append("Cant. Maletas: ");
        informacion.append(ss);
        informacion.append("\n");
        Turnos=aux->Documentos;
        sss = QString::number(Turnos);
        informacion.append("Cant. Documentos: ");
        informacion.append(sss);
        informacion.append("\n");
        Turnos=aux->Turnos;
        c = QString::number(Turnos);
        informacion.append("Turnos Restantes: ");
        informacion.append(c);
        informacion.append("\n\n");

        aux=aux->sig;
    }

    return informacion;
}

///********VERIFICAR SI AI PASAJEROS PARA PASAR A LOS ESCRITORIOS*****
///
void ColaPasajeros::Verificar_Turnos_Pasajeros(){
    int cantidad=0;
    if(primeroES!=NULL){
        if(primeroPA!=NULL){
            NodoES *actual=primeroES;
            while (actual!=NULL)
            {

                        int cant = actual->Cantidad;
                        cout<<"Escritorio::::"<<actual->Escritorio<<endl;
                        cout<<"Cantidad::::"<<actual->Cantidad<<endl;
                        if(actual->Cantidad<10){
                             cantidad= 10-cant;
                             cout<<"Cantidad::::"<<actual->Cantidad<<endl;
                            for(int i=1;i<=cantidad;i++){
                                if(primeroPA!=NULL){
                                Eliminar_Cola_Pasajeros();
                                //actual->Cantidad=cantidad;
                                }else{
                                    break;
                                }
                            }

                        }

                        actual=actual->sig;

            }
        }

    }
}

///*********************DESABORDAJE DE LOS AVIONES*******************************
///
void ColaAviones::Desabordaje(int Pasajeros, int Avion){
    //newMantenimiento->Agregar_Cola_Mantenimiento(primeroCA);
    for(int i=1;i<=Pasajeros;i++){
        int maletas = 1+rand()%(5-1);
        int documentos = 1+rand()%(11-1);
        int turnos = 1+rand()%(4-1);
        newPasajeros->Agregar_Cola_Pasajeros(Avion,maletas,documentos,turnos);
    }

}

///*********************VERIFICAR TURNO DE LOS AVIONES***************************
///
void ColaAviones::Verificar_Turnos(){
    if(primeroCA!=NULL){
        if(primeroCA->Turno_Desabordaje>0){
            primeroCA->Turno_Desabordaje--;
        }
        if(primeroCA->Turno_Desabordaje==0){
            ///Desabordaje de los Pasajeros.....
            Desabordaje(primeroCA->Pasajeros,primeroCA->Avion);

            Eliminar_Cola_Aviones();
            Graficar_Cola_Aviones();

        }
    }
}





///*********************GRAFICAR COLA PASAJEROS*********************************
///
void ColaPasajeros::Graficar_Cola_Pasajeros(){
     if(primeroPA!=NULL){
    fputs("\n subgraph cluster_1 {\n",gra);
    fputs("node [style=filled];\n",gra);

       int a=1;
       NodoPA *aux=primeroPA;
       while(aux!=NULL){
           fputs("\"",gra);
           fputs("nodoPasajero",gra);
           fprintf(gra,"%d",a);
           fputs("\"",gra);
           fputs("\n[ ",gra);
           fprintf(gra, "label=\" " );
           fputs("Pasajero: ",gra);
           fprintf(gra, "%d",a);
           fputs(" &#92;n ",gra);
           fputs("Avion: ",gra);
           fprintf(gra, "%d",aux->Avion);
           fputs(" &#92;n ",gra);
           fputs("Turnos: ",gra);
           fprintf(gra, "%d",aux->Turnos);
           fputs(" &#92;n ",gra);
           fputs("Maletas: ",gra);
           fprintf(gra, "%d",aux->Maletas);
           fputs(" &#92;n ",gra);
           fputs("Doc: ",gra);
           fprintf(gra, "%d",aux->Documentos);
           fputs("\"];\n",gra);
           a++;
               aux=aux->sig;
       }

       int b =1;
       int c =b+1;
       aux=primeroPA;
       while(aux->sig!=NULL){
           // nodo1---->nodo2 siguintes
           fputs("\"nodoPasajero",gra);
           fprintf(gra,"%d",b);
           fputs("\"-> \"nodoPasajero",gra);
           fprintf(gra,"%d",c);
           fputs( "\";\n",gra);


               aux=aux->sig;
               b++;
               c++;
       }

    fputs("fontsize = \"10\"\n",gra);
    fputs("shape = \"Mrecord\"\n",gra);
    fputs("color=\"blue\"\n",gra);
    fputs("style =\"filled, bold\"\n",gra);
    fputs("label =\"Pasajeros\"\n",gra);
    fputs("}\n",gra);
}
}
///**********************GRAFICA DE LA COLA DE LOS AVIONES***********************
///
void ColaAviones::Graficar_Cola_Aviones(){
    ///GRAFICAR LA COLA DE LOS AVIONES...............................................................
    if(primeroCA!=NULL){
       gra=fopen("Cola_Aviones.dot","wt");
       fputs("digraph g {  \n subgraph cluster_0 {\n",gra);

       fputs("rankdir= \"LR\"\n};\n",gra);
       fputs("node [\n" ,gra);
       fputs("fontsize = \"10\"\n",gra);
       fputs("shape = \"Mrecord\"\n",gra);
       fputs("color=\"darkslateblue\"\n",gra);
       fputs("style =\"filled, bold\"\n",gra);
       fputs("];\n",gra);

       int a=0;
       NodoCA *aux=primeroCA;
       NodoCA *aux2=ultimoCA;
       while(aux!=NULL){
           fputs("\"",gra);
           fputs("nodoAvion",gra);
           fprintf(gra,"%d",a);
           fputs("\"",gra);
           fputs("\n[ ",gra);
           fprintf(gra, "label=\" " );
           fputs("Avion: ",gra);
           fprintf(gra, "%d",aux->Avion);
           fputs(" &#92;n ",gra);
           fputs("Tipo: ",gra);
           fprintf(gra, "%s",aux->Tipo);
           fputs(" &#92;n ",gra);
           fputs("Pasajeros: ",gra);
           fprintf(gra, "%d",aux->Pasajeros);
           fputs(" &#92;n ",gra);
           fputs("T_Desabordaje: ",gra);
           fprintf(gra, "%d",aux->Turno_Desabordaje);
           fputs(" &#92;n ",gra);
           fputs("T_Mantenimiento: ",gra);
           fprintf(gra, "%d",aux->Turno_Mantenimiento);
           fputs("\"];\n",gra);
           a++;
               aux=aux->sig;
       }

       int b =0;
       int c =b+1;

       aux=primeroCA;

       while(aux->sig!=NULL){
           // nodo1---->nodo2 siguintes
           fputs("\"nodoAvion",gra);
           fprintf(gra,"%d",b);
           fputs("\"-> \"nodoAvion",gra);
           fprintf(gra,"%d",c);
           fputs( "\";\n",gra);
           // nodo1<----nodo2 siguintes
           fputs("\"nodoAvion",gra);
           fprintf(gra,"%d",c);
           fputs("\"-> \"nodoAvion",gra);
           fprintf(gra,"%d",b);
           fputs( "\";\n",gra);

               aux=aux->sig;
               b++;
               c++;
       }

    }else{
        cout<<"La Cola de Aviones esta Vacia..."<<endl;
        gra=fopen("Cola_Aviones.dot","wt");
        fputs("digraph g {  \n subgraph cluster_0 {\n",gra);
        fputs("rankdir= \"LR\"\n};\n",gra);
        fputs("node [\n" ,gra);
        fputs("fontsize = \"10\"\n",gra);
        fputs("shape = \"Mrecord\"\n",gra);
        fputs("color=\"darkslateblue\"\n",gra);
        fputs("style =\"filled, bold\"\n",gra);
        fputs("];\n",gra);

        // LA COLA ESTA VACIA...

    }
    newPasajeros->Graficar_Cola_Pasajeros();
    newEscritorios->Graficar_Cola_Escritorios();
    newEstaciones->Graficar_Estacion();
    newMaletas->Graficar_Maleta();



    fputs("}",gra);

    fclose(gra);
    system("dot -Tpng Cola_Aviones.dot -o Cola_Aviones.png");

}

///*******************COLA DOBLE DE LOS ESCRITORIOS************************

void ColaEscritorios::Agregar_Cola_Escritorios(char *escritorio, int cantidad){
    NodoES *nuevo;
    nuevo=(NodoES*)malloc(sizeof(struct NodoEscritorio));
    nuevo->Escritorio=escritorio;
    nuevo->Cantidad=cantidad;
    nuevo->ant=NULL;
    nuevo->sig=NULL;

    if(primeroES==NULL){
        nuevo->ant=NULL;
        nuevo->sig=NULL;
        primeroES=nuevo;
        ultimoES=nuevo;
        newEscritorios->contador++;
        nuevo->primeroC=NULL;
        nuevo->primeroP=NULL;
    }else{
        nuevo->sig=NULL;
        nuevo->ant=ultimoES;
        ultimoES->sig=nuevo;
        ultimoES=nuevo;
        newEscritorios->contador++;
        nuevo->primeroC=NULL;
        nuevo->primeroP=NULL;

    }

    //AGREGAR ORDENAMIENTO....

   Ordenar();
}

void ColaEscritorios::Ordenar(){


    NodoES *temp=primeroES;

    cout<<"Contador....."<<newEscritorios->contador<<endl;
    for(int i=0; i<newEscritorios->contador; i++){
        NodoES *temporal=temp->sig;
        for (int j=0; j<newEscritorios->contador-1; j++) {
            if(temporal!=NULL){
            if(strcmp(temporal->Escritorio,temp->Escritorio)<0){
                NodoES *aux;
                aux->Escritorio=temporal->Escritorio;
                temporal->Escritorio=temp->Escritorio;
                temp->Escritorio=temporal->Escritorio;
                temp->Escritorio=aux->Escritorio;

             }
            temporal=temporal->sig;
            }

        }
        temp=temp->sig;
    }

}

QString ColaEscritorios::Consola_Cola_Escritorios(){
    NodoES *aux=primeroES;
    QString informacion="";
    informacion.append("**************LISTA DOBLE DE LOS ESCRITORIOS**************\n");
    QString s;
    QString escritorio;


    int Avion;
    int Pasajeros;
    int Turnos;
    int Contador=0;
    if(aux->primeroC!=NULL){
    while(aux!=NULL){
        escritorio=aux->Escritorio;
        informacion.append("Escritorio: ");
        informacion.append(escritorio);
        informacion.append("\n");
        Pasajeros=aux->Cantidad;
        s = QString::number(Pasajeros);
        informacion.append("Cant. De Personas en Espera: ");
        informacion.append(s);
        informacion.append("\n\n");
        aux=aux->sig;
    }
    }
    return informacion;
}


///************AGREGAR A COLAS DE LOS PASAJEROS EN LOS ESCRITORIOS******************
///
void ColaEscritorios::Cola(NodoColaPasajeros *Nuevo){
    NodoC *nuevo;
    nuevo=(NodoC*)malloc(sizeof(struct NodoCola));
    nuevo->Avion=Nuevo->Avion;
    nuevo->Documentos=Nuevo->Documentos;
    nuevo->Maletas=Nuevo->Maletas;
    nuevo->Turnos=Nuevo->Turnos;
    nuevo->sig=NULL;


    if(primeroES!=NULL){
        NodoES *actual=primeroES;
        while(actual!=NULL){//Recorrer la Lista de los Escritorios...

            if(actual->Cantidad<10){ //Agregar a la Cola...
                if(actual->primeroC==NULL){ // Agregar el Primer Nodo de la Cola...
                    nuevo->sig=NULL;
                    actual->primeroC=nuevo;
                    actual->ultimoC=nuevo;
                    cout<<"Agrego PRIMERO"<<endl;
                    actual->Cantidad++;
                    break;

                 }else{
                    //Agregar otro a la Cola...
                    nuevo->sig=NULL;
                    actual->ultimoC->sig=nuevo;
                    actual->ultimoC=nuevo;
                    cout<<"Agrego OTRO"<<endl;
                    actual->Cantidad++;
                    break;


                }
            }

           actual=actual->sig;
        }


    }else{
        cout<<"Lista de Escritoros esta vacia..."<<endl;
    }
}

///*****************AGREGAR LOS DOCUMENTOS EN EL ESCRITORIO******************
///
void ColaEscritorios::Documentos(NodoEscritorio *Nuevo){
    NodoP *nuevo;
    nuevo=(NodoP*)malloc(sizeof(struct NodoPila));
    nuevo->Documento=Nuevo->primeroC->Documentos;
    nuevo->sig=NULL;

    for(int i=0;i<Nuevo->primeroC->Documentos;i++){
            if(Nuevo->primeroP==NULL){ // Agregar el Primer Nodo de la Cola...
               nuevo->sig=NULL;
               Nuevo->primeroP=nuevo;
               Nuevo->ultimoP=nuevo;
              cout<<"DOCUMENTO"<<Nuevo->primeroC->Documentos<<endl;
             }else{
               nuevo->sig=Nuevo->primeroP;
               Nuevo->primeroP=nuevo;;

               cout<<"DOCUMENTO.."<<Nuevo->primeroC->Documentos<<endl;
           }

    }


}

void ColaEscritorios::Verificar_Documentos(){
    if(primeroES!=NULL){
        NodoES *actual=primeroES;
        while(actual!=NULL){
            if(actual->primeroC!=NULL){
                 Documentos(actual);
            }else{
                break;
            }
            actual=actual->sig;
        }
    }
}

///*************MOSTRAR COLA DE LOS ESCRITORIOS********************
///
void ColaEscritorios::Mostrar_Cola_Escritorios(){
     NodoES *tem=primeroES;
     NodoC *actual;
     while(tem!=NULL){
         cout<<"Escritorio"<<tem->Escritorio<<endl;
         actual=tem->primeroC;
         if(actual!=NULL){
             while(actual!=NULL){
                 cout<<"pasajero...."<<actual->Avion<<endl;
                 actual=actual->sig;
             }
         }else{
             cout<<"las colas estan vacias..."<<endl;
         }

         tem=tem->sig;
     }

}

///****************VERIFICAR LOS TURNOS DE LOS PASAJEROS EN LA LISTA DOBLE DE ESCRITORIOS**********
///
void ColaEscritorios::Verificar_Turnos_Escritoios(){
    if(primeroES!=NULL){
        NodoES *temp=primeroES;
            while(temp!=NULL){
                if(temp->primeroC!=NULL){
                    if(temp->primeroC->Turnos>0){
                       temp->primeroC->Turnos--;
                    }
                    if(temp->primeroC->Turnos==0){
                        ///Eliminar Pasajero de la Cola de los Escritorios....
                        ///ELIMINAR.....
                        Eliminar_Cola_Escritorios(temp);
                    }



                 }
                temp=temp->sig;
            }

    }

}

void ColaEscritorios::Eliminar_Cola_Escritorios(NodoEscritorio *Actual){
    if(Actual->primeroC!=Actual->ultimoC){
        //Eliminar Maletas...
        for(int i=0;i<Actual->primeroC->Maletas;i++){
            newMaletas->Eliminar_Maleta();
            cout<<"ELIMINAR MALETAS......"<<Actual->primeroC->Maletas<<endl;
        }
        Actual->primeroC=Actual->primeroC->sig;
        Actual->Cantidad--;

    }else{

        for(int i=0;i<Actual->primeroC->Maletas;i++){
            newMaletas->Eliminar_Maleta();
        }
        Actual->primeroC=Actual->ultimoC=NULL;
        Actual->Cantidad--;
    }
}


///*************GRAFICAR COLA DE LOS ESCRITORIOS************************
///
void ColaEscritorios::Graficar_Cola_Escritorios(){
   if(primeroES!=NULL){
   fputs("\n subgraph cluster_2 {\n",gra);
   fputs("node [style=filled];\n",gra);

      int a=1;

      NodoES *aux=primeroES;

      while(aux!=NULL){
          int aa=1;
          int pp=1;
          fputs("\"",gra);
          fputs("nodoEscritorio",gra);
          fprintf(gra,"%d",a);
          fputs("\"",gra);
          fputs("\n[ ",gra);
          fprintf(gra, "label=\" " );
          fputs("Escritorio: ",gra);
          fprintf(gra, "%s",aux->Escritorio);

          if(aux->primeroC!=NULL){
              fputs(" &#92;n ",gra);
              fputs("Estado: ",gra);
              fputs("OCUPADO ",gra);
              fputs(" &#92;n ",gra);
              fputs("Cliente: ",gra);
              fprintf(gra, "%s",aux->Escritorio);
              fprintf(gra, "%d",aa);
              fputs(" &#92;n ",gra);
              fputs("Documentos: ",gra);
              fprintf(gra, "%d",aux->primeroC->Documentos);
              fputs(" &#92;n ",gra);
              fputs("Turnos: ",gra);
              fprintf(gra, "%d",aux->primeroC->Turnos);

          }else{
              fputs(" &#92;n ",gra);
              fputs("Estado: ",gra);
              fputs("LIBRE ",gra);
          }          
          fputs("\"];\n",gra);

          if(aux->primeroC!=NULL){
                  for(int i=1;i<=aux->primeroC->Documentos;i++){
                      fputs("\"",gra);
                      fputs("nodoDoc",gra);
                      fprintf(gra,"%s",aux->Escritorio);
                      fprintf(gra,"%d",i);
                      fputs("\"",gra);
                      fputs("\n[ ",gra);
                      fprintf(gra, "label=\" " );
                      fputs("Doc",gra);
                      fprintf(gra, "%d",i);
                      fputs("\"];\n",gra);

                  }
            }
                  ///Nodos de la Cola de espera
                  NodoC *actual=aux->primeroC;
                  while(actual!=NULL){
                      fputs("\"",gra);
                      fputs("nodoPas",gra);
                      fprintf(gra,"%s",aux->Escritorio);
                      fprintf(gra,"%d",aa);
                      fputs("\"",gra);
                      fputs("\n[ ",gra);
                      fprintf(gra, "label=\" " );
                      fprintf(gra,"%s",aux->Escritorio);
                      fprintf(gra, "%d",aa);
                      fputs(" &#92;n ",gra);
                      fputs("Turnos: ",gra);
                      fprintf(gra, "%d",actual->Turnos);
                      fputs(" &#92;n ",gra);
                      fputs("Maletas: ",gra);
                      fprintf(gra, "%d",actual->Maletas);
                      fputs("\"];\n",gra);

                      aa++;
                      actual=actual->sig;
                  }


          a++;
          aux=aux->sig;

      }

      int b =1;
      int c =b+1;

      NodoES *aux2=primeroES;

      while(aux2!=NULL){
          // nodo1---->nodo2 siguintes
          fputs("\"nodoEscritorio",gra);
          fprintf(gra,"%d",b);
          fputs("\"-> \"nodoEscritorio",gra);
          fprintf(gra,"%d",c);
          fputs( "\";\n",gra);
          // nodo1<----nodo2 siguintes
          fputs("\"nodoEscritorio",gra);
          fprintf(gra,"%d",c);
          fputs("\"-> \"nodoEscritorio",gra);
          fprintf(gra,"%d",b);
          fputs( "\";\n",gra);

          if(aux2->primeroC!=NULL){
                  for(int i=1;i<=aux2->primeroC->Documentos;i++){
                      // nodo1---->nodo2 siguintes
                      fputs("\"nodoDoc",gra);
                      fprintf(gra,"%s",aux2->Escritorio);
                      fprintf(gra,"%d",i);
                      fputs("\"-> \"nodoDoc",gra);
                      fprintf(gra,"%s",aux2->Escritorio);
                      fprintf(gra,"%d",i+1);
                      fputs( "\";\n",gra);

                  }
            }




          int bb =1;
          int cc =bb+1;
                  NodoC *actual=aux2->primeroC;
                  if(actual!=NULL){
                         //Escritorio---->nodo1
                          fputs("\"nodoEscritorio",gra);
                          fprintf(gra,"%d",b);
                          fputs("\"-> \"nodoPas",gra);
                          fprintf(gra,"%s",aux2->Escritorio);
                          fprintf(gra,"%d",bb);
                          fputs( "\";\n",gra);

                          fputs("\"nodoEscritorio",gra);
                          fprintf(gra,"%d",b);
                          fputs("\"-> \"nodoDoc",gra);
                          fprintf(gra,"%s",aux2->Escritorio);
                          fprintf(gra,"%d",1);
                          fputs( "\";\n",gra);

                          while(actual!=NULL){
                              // nodo1---->nodo2 siguintes
                              fputs("\"nodoPas",gra);
                              fprintf(gra,"%s",aux2->Escritorio);
                              fprintf(gra,"%d",bb);
                              fputs("\"-> \"nodoPas",gra);
                              fprintf(gra,"%s",aux2->Escritorio);
                              fprintf(gra,"%d",cc);
                              fputs( "\";\n",gra);

                                  actual=actual->sig;
                                  bb++;
                                  cc++;
                          }

                     }


              b++;
              c++;
              aux2=aux2->sig;
      }




   fputs("fontsize = \"10\"\n",gra);
   fputs("shape = \"Mrecord\"\n",gra);
   fputs("color=\"cyan4\"\n",gra);
   fputs("style =\"filled, bold\"\n",gra);
   fputs("label =\"Escritorios\"\n",gra);
   fputs("}\n",gra);
}

}

///*********************AGREGAR A LA LISTA CIRCULAR DE LAS MALETAS*************
///
void Maletas::Agregar_Maleta(){

    NodoM *nuevo;
    nuevo=(NodoM*)malloc(sizeof(struct NodoMaleta));

    if(primeroM==NULL){
        nuevo->sig=NULL;
        nuevo->ant=NULL;
        primeroM=nuevo;
        primeroM->sig=primeroM;
        nuevo->ant=ultimoM;
        ultimoM=nuevo;
        newMaletas->cantidad++;
    }else{
        ultimoM->sig=nuevo;
        nuevo->sig=primeroM;
        nuevo->ant=ultimoM;
        ultimoM=nuevo;
        primeroM->ant=ultimoM;
        newMaletas->cantidad++;

    }
}

///********************ELIMINAR LISTA DOBLE CIRCULAR DE LAS MALETAS***************
///
void Maletas::Eliminar_Maleta(){
    if(primeroM!=ultimoM){
        primeroM=primeroM->sig;
        ultimoM->sig=primeroM;
        primeroM->ant=ultimoM;
        newMaletas->cantidad--;
    }else{
        newMaletas->cantidad--;
        primeroM=ultimoM=NULL;
    }
}
///********************MOSTRAR LISTA DOBLE CIRCUAR********************************
///
void Maletas::Graficar_Maleta(){
    if(primeroM!=NULL){
   fputs("\n subgraph cluster_3 {\n",gra);
   fputs("node [style=filled];\n",gra);

      int a=0;
      NodoM *aux=primeroM;
      for(int i=0; i<newMaletas->cantidad; i++){
          fputs("\"",gra);
          fputs("nodoM",gra);
          fprintf(gra,"%d",a);
          fputs("\"",gra);
          fputs("\n[ ",gra);
          fprintf(gra, "label=\" " );
          fputs("Maleta: ",gra);
          fprintf(gra, "%d",a);
          fputs("\"];\n",gra);
          a++;
              aux=aux->sig;
      }

      int b =0;
      int c =b+1;
      aux=primeroM;
      int i=0;
      for(i=0; i<newMaletas->cantidad-1; i++){
          // nodo1---->nodo2 siguintes
          fputs("\"nodoM",gra);
          fprintf(gra,"%d",b);
          fputs("\"-> \"nodoM",gra);
          fprintf(gra,"%d",c);
          fputs( "\";\n",gra);

          // nodo1<----nodo2 siguintes
          fputs("\"nodoM",gra);
          fprintf(gra,"%d",c);
          fputs("\"-> \"nodoM",gra);
          fprintf(gra,"%d",b);
          fputs( "\";\n",gra);


              aux=aux->sig;
              b++;
              c++;
      }
      fputs("\"nodoM",gra);
      fprintf(gra,"%d",i);
      fputs("\"-> \"nodoM",gra);
      fprintf(gra,"%d",0);
      fputs( "\";\n",gra);

      fputs("\"nodoM",gra);
      fprintf(gra,"%d",0);
      fputs("\"-> \"nodoM",gra);
      fprintf(gra,"%d",i);
      fputs( "\";\n",gra);


   fputs("fontsize = \"10\"\n",gra);
   fputs("shape = \"Mrecord\"\n",gra);
   fputs("color=\"orange\"\n",gra);
   fputs("style =\"filled, bold\"\n",gra);
   fputs("label =\"Maletas\"\n",gra);
   fputs("}\n",gra);
}
}

QString Maletas::Consola_Maletas(){
    QString informacion="";
    informacion.append("**************LISTA CIRCULAR MALETAS**************\n");
    QString maleta = QString::number(newMaletas->cantidad);

    informacion.append("Cantidad de Maletas en la Lista Circular: ");
    informacion.append(maleta);
    informacion.append("\n");


    return informacion;
}

///******************ESTRUCTURA DEL MANTENIMIENTO DE LOS AVIONES**************************
///
///******************LISTA DE LAS ESTACIONES DE MANTENIMIENTO*****************************
///
void Estacion::Agregar_Estacion(int estacion, int avion, int turnos){
    NodoE *nuevo;
    nuevo=(NodoE*)malloc(sizeof(struct NodoEstacion));
    nuevo->Estacion=estacion;
    nuevo->Avion=avion;
    nuevo->Turnos=turnos;
    nuevo->primeroMA=NULL;

    if(primeroE==NULL){
        nuevo->sig=NULL;
        primeroE=nuevo;
        ultimoE=nuevo;
    }else{
        nuevo->sig=NULL;
        ultimoE->sig=nuevo;
        ultimoE=nuevo;
    }
}

void Estacion::Agregar_Avion_Estacion(NodoE *Actual,NodoCM *Nuevo){
    NodoMA *nuevo;
    nuevo=(NodoMA*)malloc(sizeof(struct NodoMantenimiento));
    nuevo->Avion=Nuevo->Avion;
    nuevo->Turnos=Nuevo->Turnos;


            nuevo->sig=NULL;
            Actual->primeroMA=nuevo;


}

///*********************VERIFICAR COLA DE AVIONES EN ESPERA DE MANTENIMIENTO****************
///
void Estacion::Verificar_Estacion(){
    if(primeroE!=NULL){
        NodoE *aux=primeroE;
        while(aux!=NULL){
            if(aux->primeroMA!=NULL){
                if(aux->primeroMA->Turnos>0){
                    aux->primeroMA->Turnos--;
                }
                if(aux->primeroMA->Turnos==0){
                    ///Eliminar Avion de la cola de espera
                    /// y agregarlo a las Estaciones...
                    aux->primeroMA=NULL;
                    newMantenimiento->Eliminer_Cola_Mantenimiento(aux);
                }

            }else{
                newMantenimiento->Eliminer_Cola_Mantenimiento(aux);
            }

            aux=aux->sig;
        }
    }
}

///*******************GRAFICAR ESTACIONES DE MANTENIMIENTO*****************
///
void Estacion::Graficar_Estacion(){
   if(primeroE!=NULL){
   fputs("\n subgraph cluster_4 {\n",gra);
   fputs("node [style=filled];\n",gra);

      int a=1;
      NodoE *aux=primeroE;
      while(aux!=NULL){
          fputs("\"",gra);
          fputs("nodoEstacion",gra);
          fprintf(gra,"%d",a);
          fputs("\"",gra);
          fputs("\n[ ",gra);
          fprintf(gra, "label=\" " );
          fputs("Estacion: ",gra);
          fprintf(gra, "%d",a);
          fputs(" &#92;n ",gra);

          if(aux->primeroMA!=NULL){
              fputs("Estado: ",gra);
              fputs("OCUPADO: ",gra);
              fputs(" &#92;n ",gra);
              fputs("Avion: ",gra);
              fprintf(gra, "%d",aux->primeroMA->Avion);
              fputs(" &#92;n ",gra);
              fputs("Turnos: ",gra);
              fprintf(gra, "%d",aux->primeroMA->Turnos);
              fputs(" &#92;n ",gra);
              fputs("\"];\n",gra);
          }else{
              fputs("Estado: ",gra);
              fputs("LIBRE: ",gra);
              fputs("\"];\n",gra);
          }

          if(aux->primeroMA!=NULL){
              fputs("\"",gra);
              fputs("nodoAvionME",gra);
              fprintf(gra,"%d",a);
              fputs("\"",gra);
              fputs("\n[ ",gra);
              fprintf(gra, "label=\" " );
              fputs("Avion: ",gra);
              fprintf(gra, "%d",aux->primeroMA->Avion);
              fputs(" &#92;n ",gra);
              fputs("Turnos: ",gra);
              fprintf(gra, "%d",aux->primeroMA->Turnos);
              fputs(" &#92;n ",gra);
              fputs("\"];\n",gra);
          }




          a++;
              aux=aux->sig;
      }

      int b =1;
      int c =b+1;
      aux=primeroE;
      while(aux->sig!=NULL){
          // nodo1---->nodo2 siguintes
          fputs("\"nodoEstacion",gra);
          fprintf(gra,"%d",b);
          fputs("\"-> \"nodoEstacion",gra);
          fprintf(gra,"%d",c);
          fputs( "\";\n",gra);

          if(aux->primeroMA!=NULL){
              // Estacion1---->nodo2 siguintes
              fputs("\"nodoEstacion",gra);
              fprintf(gra,"%d",b);
              fputs("\"-> \"nodoAvionME",gra);
              fprintf(gra,"%d",b);
              fputs( "\";\n",gra);
          }


              aux=aux->sig;
              b++;
              c++;
      }

   newMantenimiento->Graficar_Cola_Mantenimiento();

   fputs("fontsize = \"10\"\n",gra);
   fputs("shape = \"Mrecord\"\n",gra);
   fputs("color=\"green\"\n",gra);
   fputs("style =\"filled, bold\"\n",gra);
   fputs("label =\"Estaciones\"\n",gra);
   fputs("}\n",gra);
}
}

///******************COLA SIMPLE DE LOS AVIONES*******************************************
///
void ColaMantenimiento::Agregar_Cola_Mantenimiento(NodoColaAviones *Nuevo){
    NodoCM *nuevo;
    nuevo=(NodoCM*)malloc(sizeof(struct NodoColaMantenimiento));
    nuevo->Avion=Nuevo->Avion;
    nuevo->Estado="VACIO";
    nuevo->Turnos=Nuevo->Turno_Mantenimiento;


    if(primeroCM==NULL){
        nuevo->sig=NULL;
        primeroCM=nuevo;
        ultimoCM=nuevo;

    }else{
        nuevo->sig=NULL;
        ultimoCM->sig=nuevo;
        ultimoCM=nuevo;
    }

}



/// ******************ELIMINAR COLA DE MANTENIMIENTO****************************************
///
void ColaMantenimiento::Eliminer_Cola_Mantenimiento(NodoE *actual){
  if(primeroCM!=NULL){
        if(primeroCM!=ultimoCM){
                newEstaciones->Agregar_Avion_Estacion(actual, primeroCM);
                primeroCM=primeroCM->sig;

        }else{

                newEstaciones->Agregar_Avion_Estacion(actual,primeroCM);
                primeroCM=ultimoCM=NULL;

        }
    }

}


////*****************GRAFICAR COLA DE MANTENIMIENTO*****************************************
///
void ColaMantenimiento::Graficar_Cola_Mantenimiento(){
    if(primeroCM!=NULL){

       int a=1;
       NodoCM *aux=primeroCM;
       while(aux!=NULL){
           fputs("\"",gra);
           fputs("nodoMantenimiento",gra);
           fprintf(gra,"%d",a);
           fputs("\"",gra);
           fputs("\n[ ",gra);
           fprintf(gra, "label=\" " );
           fputs("#: ",gra);
           fprintf(gra, "%d",a);
           fputs(" &#92;n ",gra);
           fputs("Avion: ",gra);
           fprintf(gra, "%d",aux->Avion);
           fputs(" &#92;n ",gra);
           fputs("Turnos: ",gra);
           fprintf(gra, "%d",aux->Turnos);
           fputs(" &#92;n ",gra);
           fputs("\"];\n",gra);
           a++;
               aux=aux->sig;
       }

       int b =1;
       int c =b+1;
       aux=primeroCM;
       while(aux->sig!=NULL){
           // nodo1---->nodo2 siguintes
           fputs("\"nodoMantenimiento",gra);
           fprintf(gra,"%d",b);
           fputs("\"-> \"nodoMantenimiento",gra);
           fprintf(gra,"%d",c);
           fputs( "\";\n",gra);


               aux=aux->sig;
               b++;
               c++;
       }



 }
}









