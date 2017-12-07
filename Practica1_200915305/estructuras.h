#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H


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
};

#endif // ESTRUCTURAS_H
