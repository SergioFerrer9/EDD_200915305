#ifndef LISTA_DOBLE_ENLAZADA_H
#define LISTA_DOBLE_ENLAZADA_H

struct NodoLista
{
    int dato;
    struct NodoLista *sig;
    struct NodoLista *ant;
};

class Lista_Doble_Enlazada
{
public:

    void Agregar(int dato);
    void Eliminar(int dato);
    void Mostrar();
};

#endif // LISTA_DOBLE_ENLAZADA_H
