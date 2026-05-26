#include <iostream>
#include <string>
#include "funciones.hpp"
using namespace std;

void mostrarMenu() {
	cout << "Bienvenido al sistema de gestion del Kiosquito. Ingrese opcion:" << endl;
	cout << "1: para Dar de alta un producto nuevo" << endl;
	cout << "2: para Buscar un producto por su nombre" << endl;
	cout << "3: para Modificar el stock y precio de un producto dado. (Ingresar Prod por Nombre)" << endl;
	cout << "0: para salir " << endl;
    cout << endl;
}

void agregar(Producto vec[], int n, int &len, Producto prod) {
    if (n == len) {
        cout << "Error. No se puede agregar. Vector lleno." << endl;
    } else {
        vec[len] = prod;
        len++;
    }
}

void darAltaNuevoProducto(Producto vec[], int n, int &len) {
    Producto prod;

    cout << "-------- Dar de alta un producto nuevo --------" << endl;
    cout << "Ingrese codigo del producto: ";
    cin >> prod.codigo;
    cout << "Ingrese nombre del producto: ";
    cin >> prod.nombre;
    cout << "Ingrese precio del producto: ";
    cin >> prod.precio;
    cout << "Ingrese cantidad del producto: ";
    cin >> prod.cantidad;
    cout << endl;

    agregar(vec, n, len, prod);
}

int buscar(Producto vec[], int len, string prod) {
    
    for (int i = 0; i < len; i++) {
        if (vec[i].nombre == prod) {
            return i;
        }
    }

    return -1;
}

void buscarEImprimirProducto(Producto vec[], int len) {
    string prod;
    int pos;

    cout << "-------- Buscar un producto por su nombre --------" << endl;
    cout << "Ingrese el nombre del producto que desea buscar: ";
    cin >> prod;

    pos = buscar(vec, len, prod);

    if (pos == -1) {
        cout << "El producto no se encuentra cargado." << endl;
        cout << endl;
    } else {
        cout << "Producto encontrado" << endl;
        cout << "ID: " << vec[pos].codigo << endl;
        cout << "Nombre: " << vec[pos].nombre << endl;
        cout << "Precio: " << vec[pos].precio << endl;
        cout << "Cantidad: " << vec[pos].cantidad << endl;
        cout << endl;
    }
}

void modificarProducto(Producto vec[], int len) {
    int pos;
    string prod;

    cout << "-------- Modificar el stock y precio de un producto --------" << endl;
    cout << "Ingrese el nombre del producto que desea modificar: ";
    cin >> prod;

    pos = buscar(vec, len, prod);

    if (pos == -1) {
        cout << "El producto no se encuentra cargado." << endl;
        cout << endl;
    } else {
        cout << "Producto " << prod << " encontrado" << endl;
        cout << "Ingrese el nuevo stock: ";
        cin >> vec[pos].cantidad;
        cout << "Ingrese el nuevo precio: ";
        cin >> vec[pos].precio;
        cout << endl;
    }
}