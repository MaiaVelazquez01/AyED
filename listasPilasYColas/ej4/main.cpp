#include <iostream>
using namespace std;

struct Nodo {
    int info;
    Nodo* sgte;
};

Nodo* buscar(Nodo* lista, int v);

int main() {

    Nodo* lista = NULL;

    return 0;

}

Nodo* buscar(Nodo* lista, int v) {

    Nodo* aux = lista;
	while(aux != NULL && aux->info != v){
		aux = aux->sgte;
	}
	return aux;
    
}