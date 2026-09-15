#include <iostream>
using namespace std;

struct Nodo {
	int info;
    Nodo* sgte;
};

void push(Nodo* &pila, int valor);
int pop(Nodo* &pila);
void reemplazarXPorY(Nodo* &pila, int x, int y);

int main() {

    Nodo* pila = NULL;

    push(pila, 45);
    push(pila, 56);
    push(pila, 78);
    push(pila, 99);
    push(pila, 56);

    int x, y;
    cout << "Ingrese el valor que desea reemplazar: ";
    cin >> x;
    cout << "Ingrese el valor por el cual lo desea reemplazar: ";
    cin >> y;
    reemplazarXPorY(pila, x, y);

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

void reemplazarXPorY(Nodo* &pila, int x, int y) {

    Nodo* aux = NULL;
    bool encontradoX;

    while(pila != NULL) {

        if(pila->info == x) {
            encontradoX = true;
            pila->info = y;
        }
        
        push(aux, pop(pila));
    }

    while(aux != NULL) {
        push(pila, pop(aux));
    }

    if(encontradoX == true) {
        cout << "------- Pila con modificacion -------" << endl;
    } else {
        cout << "------- Pila sin modificacion -------" << endl;
    }

    while(pila != NULL) {
        cout << pop(pila) << endl;
    }

}