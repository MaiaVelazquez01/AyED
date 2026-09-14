#include <iostream>
using namespace std;

struct Nodo {
    int info;
    Nodo* sgte;
};

void ordenar(Nodo* &lista);

int main() {

    Nodo* lista = NULL;

    return 0;

}

int eliminarPrimerNodo(Nodo*& lista){

	int ret = lista->info;
    
	Nodo* aux = lista;
	lista = aux->sgte;
	
	delete aux;
	return ret;

}

Nodo* insertarOrdenado(Nodo*& lista, int v){
	
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

void ordenar(Nodo* &lista) {

    Nodo* listaAux = NULL;
	int v;
	
	while(lista != NULL){
		v = eliminarPrimerNodo(lista);
		insertarOrdenado(listaAux,v);
	}
	
	lista = listaAux;
}