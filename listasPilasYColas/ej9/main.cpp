#include <iostream>
using namespace std;

struct Nodo {
    int info;
    Nodo* sgte;
};

Nodo* buscar(Nodo* lista, int v);
Nodo* insertarOrdenado(Nodo*& lista, int v);
Nodo* buscaEInsertaOrdenado(Nodo* &lista, int v, bool &enc);

int main() {

    Nodo* lista = NULL;

    return 0;

}

Nodo* buscar(Nodo* lista, int v) {

	Nodo* aux = lista;
	while(aux != NULL && aux->info != v) {
		aux = aux->sgte;
	}
	return aux;

}

Nodo* insertarOrdenado(Nodo*& lista, int v) {
	
	Nodo* nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sgte = NULL;
	
	Nodo* aux = lista;
	Nodo* ant = NULL;
	
	while(aux != NULL && aux->info <= v){
		ant = aux;
		aux = aux->sgte;
	}
	
	if(ant != NULL){
		ant->sgte = nuevo;
	} else {
		lista = nuevo;
	}
	
	nuevo->sgte = aux;
	
	return nuevo;
}

Nodo* buscaEInsertaOrdenado(Nodo* &lista, int v, bool &enc) {

    Nodo* nodoBuscado = buscar(lista, v);

	if(nodoBuscado != NULL) {
		enc = true;
	} else {
		enc = false;
		nodoBuscado = insertarOrdenado(lista, v);
	}

	return nodoBuscado;

}