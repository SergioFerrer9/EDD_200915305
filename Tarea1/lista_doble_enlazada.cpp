#include "lista_doble_enlazada.h"
#include <iostream>

using namespace std;
using std::cout;
using std::endl;

typedef struct NodoLista Nodo;
Nodo *primero;
Nodo *ultimo;

void Lista_Doble_Enlazada::Agregar(int dato){
    ///Inicializar el Nodo...
    Nodo *nuevo;
    nuevo=(Nodo*)malloc(sizeof(struct NodoLista));
    nuevo->dato=dato;
    nuevo->ant=NULL;
    nuevo->sig=NULL;

    if(primero==NULL){
        nuevo->sig=NULL;
        nuevo->ant=NULL;
        primero=nuevo;
        ultimo=nuevo;
    }else{
        nuevo->sig=NULL;
        nuevo->ant=ultimo;
        ultimo->sig=nuevo;
        ultimo=nuevo;
    }
}

void Lista_Doble_Enlazada::Mostrar(){
    Nodo *aux=primero;
    if(primero!=NULL){
        while (aux!=NULL) {
            cout<<"DATO: "<<aux->dato<<endl;
            aux=aux->sig;
        }
    }
}

void Lista_Doble_Enlazada::Eliminar(int dato){
    Nodo *aux=primero;

    if(primero!=NULL){
        while (aux!=NULL) {

            if(aux->dato==dato){
                if(aux==primero){
                    primero=primero->sig;
                }else if(aux==ultimo){
                    Nodo *temp=primero;
                    while (temp->sig!=ultimo) {
                        temp=temp->sig;
                    }
                    ultimo=temp;
                    ultimo->sig=NULL;

                }else{
                  aux->ant->sig=aux->sig;
                  aux->sig->ant=aux->ant;
                }

              break;
            }



            aux=aux->sig;
        }
    }



}


























