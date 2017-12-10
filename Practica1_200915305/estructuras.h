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
    void Eliminar_Cola_Pasajeros();
    void Mostrar_Cola_Pasajeros();
    void Graficar_Cola_Pasajeros();
    void Verificar_Turnos_Pasajeros();
    void Pasar_A_Registro();

};

///**************************ESTRUCTURA DE LA COLA DE LOS ESCRITORIOS**************************
///
struct NodoEscritorio
{
    char *Escritorio;
    struct NodoEscritorio *sig;
    struct NodoEscritorio *ant;

};

struct ColaEscritorios
{
    void Agregar_Cola_Escritorios(char *escritorio);
    void Ordenar();
    void Mostrar_Cola_Escritorios();
    void Graficar_Cola_Escritorios();
    int contador=0;
};

#endif // ESTRUCTURAS_H

















