#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

///****************************ESTRUCTURA DE LA COLA DOBLE DE LOS AVIONES*********************
///

struct NodoColaAviones
{
    int Avion;
    char *Tipo;
    int Pasajeros;
    int Turno_Desabordaje;
    int Turno_Mantenimiento;
    struct NodoColaAviones *sig;
    struct NodoColaAviones *ant;
};

struct ColaAviones
{
    void Agregar_Cola_Aviones(int Avion, char *Tipo, int Pasajeros, int Turno_D, int Turno_M);
    void Eliminar_Cola_Aviones();
    void Mostrar_Cola_Aviones();
    void Graficar_Cola_Aviones();
    void Verificar_Turnos();
    void Desabordaje(int Pasajeros, int Avion);
};

///**************************ESTRUCTURA DE LA COLA SIMPLE DE LOS PASAJEROS*********************
///
struct NodoColaPasajeros
{
    int Avion;
    int Maletas;
    int Documentos;
    int Turnos;
    struct NodoColaPasajeros *sig;

};

struct ColaPasajeros
{
    void Agregar_Cola_Pasajeros( int Avion, int Maletas, int Documentos, int Turnos);
    void Mostrar_Cola_Pasajeros();
    void Graficar_Cola_Pasajeros();
    void Eliminar_Cola_Pasajeros();
    void Verificar_Turnos_Pasajeros();



};

///**************************ESTRUCTURA DE LA COLA DE LOS ESCRITORIOS**************************
///

struct NodoPila ///Pila de Documentos Enlazada a los Escritorios...
{
    int Documento;
    NodoPila *sig;
};

struct NodoCola ///Cola de las Personas en los Escritorios
{
    int Avion;
    int Maletas;
    int Documentos;
    int Turnos;
    struct NodoCola *sig;
};



struct NodoEscritorio /// Lista Doble de los Escritorios
{
    char *Escritorio;
    int Cantidad;
    struct NodoEscritorio *sig;
    struct NodoEscritorio *ant;
    struct NodoCola *primeroC;
    struct NodoCola *ultimoC;
    struct NodoPila *primeroP;
    struct NodoPila *ultimoP;

};

struct ColaEscritorios
{
    void Agregar_Cola_Escritorios(char *escritorio, int cantidad);
    void Ordenar();
    void Mostrar_Cola_Escritorios();
    void Graficar_Cola_Escritorios();
    void Cola(NodoColaPasajeros *Nuevo);
    void Documentos(NodoEscritorio *Nuevo);
    void Verificar_Turnos_Escritoios();
    void Verificar_Documentos();
    void Eliminar_Cola_Escritorios(NodoEscritorio *Actual);
    int contador=0;
};

///**************************ESTRUCTURA DE LA LISTA DOBLE CIRCULAR**************************
///

struct NodoMaleta
{
    int Maletas;
    struct NodoMaleta *sig;
    struct NodoMaleta *ant;
};

struct Maletas
{
    int cantidad=0;
    void Agregar_Maleta();
    void Eliminar_Maleta();
    void Graficar_Maleta();
};

///*************************ESTRUCTURA DEL MANTENIMIENTO DE LOS AVIONES***********************
///
struct NodoMantenimiento
{
    int Avion;
    struct NodoAvion *sig;
};

struct NodoEstacion
{
    int Estacion;
    int Avion;
    int Turnos;
    NodoEstacion *sig;
    NodoMantenimiento *primeroMA;
};

struct Estacion
{
    void Agregar_Estacion(int estacion, int avion, int turnos);
    void Eliminar_Estacion();
    void Graficar_Estacion();
};

struct NodoColaMantenimiento
{
    int Avion;
    char *Estado;
    int Turnos;
    struct NodoColaMantenimiento *sig;
};

struct ColaMantenimiento
{
    void Agregar_Cola_Mantenimiento(NodoColaAviones *Nuevo);
    void Eliminer_Cola_Mantenimiento();
    void Graficar_Cola_Mantenimiento();
};



#endif // ESTRUCTURAS_H

















