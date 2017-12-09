#include <QCoreApplication>
#include <iostream>
#include "lista_doble_enlazada.h"

using namespace std;
using std::cout;
using std::endl;
Lista_Doble_Enlazada *lista =new Lista_Doble_Enlazada();


int main()
{
    int n, opcion;

       do
       {
           printf( "\n   1. Agregar...");
           printf( "\n   2. Eliminar...");
           printf( "\n   3. Mostrar...");
           printf( "\n   4. Salir." );
           printf( "\n " );

           scanf( "%d", &opcion );


           switch ( opcion )
           {
               case 1: printf( "\n Agrega un nuevo dato  \n");
                       int dato;
                       scanf( "%d", &dato );
                       lista->Agregar(dato);
                       break;

               case 2: printf( "\n Ingrese el dato a Eliminar  \n");
                       int dato2;
                       scanf( "%d", &dato2 );
                       lista->Eliminar(dato2);
                       break;

               case 3: printf( "\n ****LISTA DOBLE ENLAZADA****  \n");
                       lista->Mostrar();
                       break;
            }


       } while ( opcion != 4 );

       return 0;
}
