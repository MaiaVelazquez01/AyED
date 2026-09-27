#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct Nodo {
	int info;
    Nodo* sgte;
};

struct Alumno {
    int legajo;
    int nota1erP;
    int nota2doP;
    int notaA;
};

struct Recuperatorios {
    int legajo;
    int recu1erP;
    int recu2doP;
};

struct NodoR {
    Recuperatorios r;
    NodoR* sgte;
};

#ifndef funciones
#define funciones

// listas
void agregarNodo(Nodo*& lista, int x);
void mostrar(Nodo* lista);
void liberar(Nodo*& lista);
Nodo* buscar(Nodo* lista, int v);
void eliminar(Nodo*& lista, int v);
Recuperatorios eliminarPrimerNodoR(NodoR*& lista);
int eliminarPrimerNodo(Nodo*& lista);
Nodo* insertarOrdenado(Nodo*& lista, int v);
void ordenar(Nodo*& lista);
Nodo* buscaEInsertaOrdenado(Nodo*& lista, int v, bool& enc);

// pilas
void push(Nodo* &pila, int valor);
int pop(Nodo* &pila);

// colas
void agregar(Nodo* &cfte, Nodo* &cfin, int a);
int suprimir (Nodo* &cfte, Nodo* &cfin);

// vectores
int buscarVector(int arr[], int len, int v);
int buscarVectorA(Alumno arr[], int len, int v);

#endif