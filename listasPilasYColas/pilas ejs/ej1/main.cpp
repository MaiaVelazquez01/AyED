#include <iostream>
using namespace std;

struct Nodo {
	int info;
    Nodo* sgte;
};

void push(Nodo* &pila, int valor);
int pop(Nodo* &pila);
void eliminarDosPrimerosYAgregarX(Nodo* &pila, int x);

int main() {

    Nodo* pila = NULL;

    push(pila, 1);
    push(pila, 2);
    push(pila, 3);

    int x;

    cout << "Ingresar valor X: ";
    cin >> x;
    eliminarDosPrimerosYAgregarX(pila, x);

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

void eliminarDosPrimerosYAgregarX(Nodo* &pila, int x) {

    for(int i = 0; i < 2; i++) {
        cout << "Eliminado " << pop(pila) << endl;
    }

    push(pila, x);

    cout << "------- Pila resultante -------" << endl;
    while(pila != NULL) {
        cout << pop(pila) << endl;
    }

}