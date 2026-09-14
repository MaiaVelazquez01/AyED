#include <iostream>
using namespace std;

struct Nodo {
    int info;
    Nodo* sgte;
};

int eliminarPrimerNodo(Nodo* &lista);

int main() {

    Nodo* lista = NULL;

    return 0;

}

int eliminarPrimerNodo(Nodo* &lista) {

    int ret= lista->info;

	Nodo* aux = lista;
	lista = aux->sgte;
	delete aux;
    
	return ret;

}