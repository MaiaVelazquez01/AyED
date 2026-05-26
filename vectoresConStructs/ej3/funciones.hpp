#include <string>
using namespace std;

struct Producto {
    int codigo;
    string nombre;
    float precio;
    int cantidad;
};

#ifndef funciones
#define funciones

void mostrarMenu();
void agregar(Producto vec[], int n, int &len, Producto prod);
void darAltaNuevoProducto(Producto vec[], int n, int &len);
int buscar(Producto vec[], int len, string prod);
void buscarEImprimirProducto(Producto vec[], int len);
void modificarProducto(Producto vec[], int len);

#endif