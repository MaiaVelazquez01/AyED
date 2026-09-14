#include <iostream>
using namespace std;

struct Nodo {
    int info;
    Nodo* sgte;
};

void mostrar(Nodo* lista);

int main() {

    Nodo* lista = NULL;

    return 0;

}

void mostrar(Nodo* lista) {

    Nodo* aux = lista;
    while(aux != NULL){
		cout << aux->info << endl;
		aux = aux->sgte;
	}

}