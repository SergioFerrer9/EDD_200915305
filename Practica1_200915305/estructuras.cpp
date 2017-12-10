#include "estructuras.h"
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;
using std::cout;
using std::endl;
ColaPasajeros *newPasajeros = new ColaPasajeros();
ColaEscritorios *newEscritorios = new ColaEscritorios();
NodoEscritorio *NodoEcritorio_ = new NodoEscritorio();

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
        primeroCA=primeroCA->sig;
    }else{
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

///*********************DESABORDAJE DE LOS AVIONES*******************************
///
void ColaAviones::Desabordaje(int Pasajeros, int Avion){
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

   // fputs("b0 -> b1 -> b2 -> b3;\n" ,gra);

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

    fputs("}",gra);

    fclose(gra);
    system("dot -Tpng Cola_Aviones.dot -o Cola_Aviones.png");

}

///*******************COLA DOBLE DE LOS ESCRITORIOS************************

void ColaEscritorios::Agregar_Cola_Escritorios(char *escritorio){
    NodoES *nuevo;
    nuevo=(NodoES*)malloc(sizeof(struct NodoEscritorio));
    nuevo->Escritorio=escritorio;
    nuevo->ant=NULL;
    nuevo->sig=NULL;

    if(primeroES==NULL){
        nuevo->ant=NULL;
        nuevo->sig=NULL;
        primeroES=nuevo;
        ultimoES=nuevo;
        newEscritorios->contador++;
    }else{
        nuevo->sig=NULL;
        nuevo->ant=ultimoES;
        ultimoES->sig=nuevo;
        ultimoES=nuevo;
        newEscritorios->contador++;


    }

    //AGREGAR ORDENAMIENTO....

   Ordenar();
}

void ColaEscritorios::Ordenar(){


    NodoES *temp=primeroES;

    cout<<"Contador....."<<newEscritorios->contador<<endl;
    for(int i=0; i<newEscritorios->contador; i++){
        cout<<"FOR1....."<<endl;
        NodoES *temporal=temp->sig;
        for (int j=0; j<newEscritorios->contador-1; j++) {
            if(temporal!=NULL){
            if(strcmp(temporal->Escritorio,temp->Escritorio)<0){
                printf("es mayor\n");
                NodoES *aux;
                aux->Escritorio=temporal->Escritorio;
                temporal->Escritorio=temp->Escritorio;
                temp->Escritorio=temporal->Escritorio;
                temp->Escritorio=aux->Escritorio;

              /*  aux->Escritorio = temporal->Escritorio;
                temporal->Escritorio=temp->Escritorio;
                temp->Escritorio=aux->Escritorio;
                */

             }
            printf("es menor\n");
            temporal=temporal->sig;
            }

        }
        temp=temp->sig;
    }




}





void ColaEscritorios::Graficar_Cola_Escritorios(){
   if(primeroES!=NULL){
   fputs("\n subgraph cluster_2 {\n",gra);
   fputs("node [style=filled];\n",gra);

      int a=1;
      NodoES *aux=primeroES;
      while(aux!=NULL){
          fputs("\"",gra);
          fputs("nodoEscritorio",gra);
          fprintf(gra,"%d",a);
          fputs("\"",gra);
          fputs("\n[ ",gra);
          fprintf(gra, "label=\" " );
          fputs("Escritorio: ",gra);
          fprintf(gra, "%d",a);
          fputs(" &#92;n ",gra);
          fputs("Avion: ",gra);
          fprintf(gra, "%s",aux->Escritorio);

          fputs("\"];\n",gra);
          a++;
              aux=aux->sig;
      }

      int b =1;
      int c =b+1;
      aux=primeroES;
      while(aux->sig!=NULL){
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


              aux=aux->sig;
              b++;
              c++;
      }



   fputs("fontsize = \"10\"\n",gra);
   fputs("shape = \"Mrecord\"\n",gra);
   fputs("color=\"cyan4\"\n",gra);
   fputs("style =\"filled, bold\"\n",gra);
   fputs("label =\"Escritorios\"\n",gra);
   fputs("}\n",gra);
}

}


















