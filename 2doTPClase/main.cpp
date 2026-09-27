#include <iostream>
#include <string>
#include <string.h>
#include "funciones.hpp"
using namespace std;

int main() {

    // Dadas 2 Colas de enteros (Cola A y Cola B) genere la UNION de ambos en Cola C.
    // Nodo* cfteA = NULL;
    // Nodo* cfteB = NULL;
    // Nodo* cfteC = NULL;
    // Nodo* cfinA = NULL;
    // Nodo* cfinB = NULL;
    // Nodo* cfinC = NULL;
    // int v;
    // while(cfteA != NULL) {
    //     v = suprimir(cfteA, cfinA);
    //     agregar(cfteC, cfinC, v);
    // }
    // while(cfteB != NULL) {
    //     v = suprimir(cfteB, cfinB);
    //     agregar(cfteC, cfinC, v);
    // }

    // Dadas 2 Pilas de enteros (PilaA y PilaB) genere la UNION en la PilaC
    // Nodo* pilaA = NULL;
    // Nodo* pilaB = NULL;
    // Nodo* pilaC = NULL;
    // int v;
    // while(pilaA != NULL) {
    //     v = pop(pilaA);
    //     push(pilaC, v);
    // }
    // while(pilaB != NULL) {
    //     v = pop(pilaB);
    //     push(pilaC, v);
    // }

    // Un procedimiento que genere una lista sin orden a partir de la intersección de una lista y un vector
    // int vec[10];
    // int len;
    // Nodo* lista = NULL;
    // Nodo* listaI = NULL;
    // generarListaInterseccion(lista, vec, len, listaI);

    // Dadas 1 Pila de enteros y 1 Cola de enteros, se pide cargar la UNION ambos en una Lista Ordenada y mostrarla por pantalla
    // Nodo* pila = NULL;
    // push(pila, 56);
    // push(pila, 1);
    // push(pila, 78);
    // Nodo*colafte=NULL;
	// Nodo*colafin=NULL;
    // agregar(colafte, colafin, 7);
    // agregar(colafte, colafin, 9);
    // agregar(colafte, colafin, 11);
    // Nodo* lista = NULL;
    // int valorP, valorC;
    // while(pila != NULL) {
    //     valorP = pop(pila);
    //     insertarOrdenado(lista, valorP);
    // }
    // while(colafte != NULL) {
    //     valorC = suprimir(colafte, colafin);
    //     insertarOrdenado(lista, valorC);
    // }
    // cout << "------- Lista ordenada resultante -------" << endl;
    // mostrar(lista);

    // Se tiene un vector de los alumnos del curso K1151, que contiene todos los alumnos que cursaron la materia con los siguientes campos:
    // Numero de Legajo, Nota Primer Parcial, Nota Segundo Parcial, Nota de Aprobación.
    // Además, se cuenta con una lista ordenada que contiene las notas de los que rindieron recuperatorio del Primer Parcial ó Segundo Parcial; cada nodo de la lista contiene el Número de Legajo, Nota Recuperatorio primer parcial ó la nota del recuperatorio del segundo parcial (puede considerar que tiene 0 en el campo que no haya rendido).
    // Se pide, actualizar el vector K1151 con la información que hay en la lista, reemplazando el Primer o Segundo parcial por la nota del recuperatorio y actualizar el campo Nota de Aprobación. En el caso que la nota de aprobación sea 8 o más, imprimir por pantalla que el alumno promocionó.
    // Se sabe que cómo Máximo hay 50 alumnos.
    // Alumno k1151[50];
    // int len, pos;
    // NodoR* lista = NULL;
    // Recuperatorios r;
    // while(lista != NULL) {
    //     r = eliminarPrimerNodoR(lista);
    //     pos = buscarVectorA(k1151, len, r.legajo);
    //     if(pos != -1) {
    //         if(r.recu1erP > 0) {
    //             k1151[pos].nota1erP = r.recu1erP;
    //         }
    //         if(r.recu2doP > 0) {
    //             k1151[pos].nota2doP = r.recu2doP;
    //         }
    //         k1151[pos].notaA = (k1151[pos].nota1erP + k1151[pos].nota2doP) / 2;
    //         if(k1151[pos].notaA >= 8) {
    //             cout << "El alumno/a con legajo " << r.legajo << " promociono" << endl;
    //         }
    //     }
    // }

    return 0;
}

void generarListaInterseccion(Nodo* &lista, int vec[], int len, Nodo* &listaI) {

    int v, pos;

    while(lista != NULL) {
        v = eliminarPrimerNodo(lista);
        pos = buscarVector(vec, len, v);
        if(pos != -1) {
            agregarNodo(listaI, v);
        }
    }

}