#include "estructuras.h"
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;
using std::cout;
using std::endl;

///************************PUNTEROS DE LA COLA AVIONES*************************
typedef struct NodoColaAviones NodoCA;
NodoCA *primeroCA;
NodoCA *ultimoCA;

///***********************AGREGAR A LA COLA AVIONES****************************
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

void ColaAviones::Eliminar_Cola_Aviones(){
    if(primeroCA!=ultimoCA){
        primeroCA=primeroCA->sig;
    }else{
        primeroCA=ultimoCA=NULL;
        cout<<"La Pila esta vacia..."<<endl;
    }

}

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

void ColaAviones::Graficar_Cola_Aviones(){
      FILE *gra;
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





            fputs("}",gra);
            fclose(gra);
            system("dot -Tpng Cola_Aviones.dot -o Cola_Aviones.png");

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

        fputs("}",gra);
        fclose(gra);
        system("dot -Tpng Cola_Aviones.dot -o Cola_Aviones.png");
    }
}


















