#include <iostream>
using namespace std;

struct Nodo {
	int info;
    Nodo* sgte;
};

void push(Nodo* &pila, int valor);
int pop(Nodo* &pila);
void ordenar(Nodo* &pila);

int main() {

    Nodo* pila = NULL;

    push(pila, 89);
    push(pila, 456);
    push(pila, 2);
    push(pila, 6);
    push(pila, 1);
    push(pila, 76);

    ordenar(pila);

    return 0;

}

void push(Nodo* &pila, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->info = valor;
    nuevo->sgte= pila;
    pila = nuevo;
}

int pop(Nodo* &pila) {
    int ret = pila->info;
    Nodo* aux = pila;
    pila = aux->sgte;
    delete(aux);
    return ret;
}

// Asumí ordenarla de forma ascendente
void ordenar(Nodo* &pila) {
    Nodo* aux = NULL; 

    while (pila != NULL) { 
        int valorActual = pop(pila);

        while (aux != NULL) {
            int valorTopeAux = pop(aux);

            if (valorTopeAux < valorActual) {
                push(pila, valorTopeAux);
            } else {
                push(aux, valorTopeAux);
                break; 
            }
        }

        push(aux, valorActual);
    }

    cout << "------ Pila resultante ------" << endl;
    while(aux != NULL) {
        cout << pop(aux) << endl;
    }
}