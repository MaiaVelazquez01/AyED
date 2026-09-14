#include <iostream>
using namespace std;

struct Nodo {
    int info;
    Nodo* sgte;
};

void liberar(Nodo* &lista);

int main() {

    Nodo* lista = NULL;

    return 0;

}

void liberar(Nodo* &lista) {

    Nodo* aux;
	while(lista != NULL){
		aux = lista;
		lista = lista->sgte;
		delete aux;
	}
    
}