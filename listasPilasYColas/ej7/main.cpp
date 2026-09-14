#include <iostream>
using namespace std;

struct Nodo {
    int info;
    Nodo* sgte;
};

Nodo* insertarOrdenado(Nodo* &lista, int v);

int main() {

    Nodo* lista = NULL;

    return 0;

}

Nodo* insertarOrdenado(Nodo* &lista, int v) {

    Nodo* nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sgte = NULL;
	
	Nodo* aux = lista;
	Nodo* ant = NULL;
	
	while(aux != NULL && aux->info <= v) {
        ant = aux;
		aux = aux->sgte;
	}
	
	if(ant != NULL) {
		ant->sgte = nuevo;
	} else {
		lista = nuevo;
	}
	
	nuevo->sgte = aux;

	return nuevo;

}