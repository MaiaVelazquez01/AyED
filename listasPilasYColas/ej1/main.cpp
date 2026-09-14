#include <iostream>
using namespace std;

struct Nodo {
    int info;
    Nodo* sgte;
};

void agregarNodo(Nodo* &lista, int x);

int main() {

    Nodo* lista = NULL;

    return 0;
}

void agregarNodo(Nodo* &lista, int x) {

    Nodo* nuevo = new Nodo();
    nuevo->info = x;
    nuevo->sgte = NULL;

    if(lista == NULL) {
        lista = nuevo;
    } else {
        Nodo* aux = lista;
        while(aux->sgte != NULL) {
            aux = aux->sgte;
        }
        aux->sgte = nuevo;
    }

}