#include "estructuras.h"
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;
using std::cout;
using std::endl;
ColaPasajeros *newPasajeros = new ColaPasajeros();
FILE *gra;

///************************PUNTEROS DE LA COLA AVIONES*************************
typedef struct NodoColaAviones NodoCA;
NodoCA *primeroCA;
NodoCA *ultimoCA;

///************************PUNTEROS DE LA COLA DE PASAJEROS*******************
typedef struct NodoColaPasajeros NodoPA;
NodoPA *primeroPA;
NodoPA *ultimoPA;


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
void ColaPasajeros::Agregar_Cola_Pasajeros(int Pasajeros, int Avion, int Maletas, int Documentos, int Turnos){
    NodoPA *nuevo;
    nuevo=(NodoPA*)malloc(sizeof(struct NodoColaPasajeros));
    nuevo->Pasajeros=Pasajeros;
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
void ColaAviones::Desabordaje(int Pasajeros){
    for(int i=1;i<=Pasajeros;i++){
        newPasajeros->Agregar_Cola_Pasajeros(i,1,1,1,1);
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
            Desabordaje(primeroCA->Pasajeros);

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

       int a=0;
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
           fputs("\"];\n",gra);
           a++;
               aux=aux->sig;
       }

       int b =0;
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
    fputs("}",gra);

    fclose(gra);
    system("dot -Tpng Cola_Aviones.dot -o Cola_Aviones.png");

}


















