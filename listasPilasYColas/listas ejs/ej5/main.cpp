#include <iostream>
using namespace std;

struct Nodo {
    int info;
    Nodo* sgte;
};

void eliminar(Nodo* &lista, int v);

int main() {

    Nodo* lista = NULL;

    return 0;

}

void eliminar(Nodo* &lista, int v) {

    Nodo* aux = lista;
	Nodo* ant = NULL;
	
	while(aux != NULL && aux->info != v){
		ant = aux;
		aux = aux->sgte;
	}
    
	if(ant != NULL){
		ant->sgte = aux->sgte;
	} else {
		lista = aux->sgte;
	}
	delete aux;

}