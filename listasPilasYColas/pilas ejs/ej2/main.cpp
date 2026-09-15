#include <iostream>
using namespace std;

struct Nodo {
	int info;
    Nodo* sgte;
};

void push(Nodo* &pila, int valor);
int pop(Nodo* &pila);
void insertarComoTercer(Nodo* &pila, int valor, char &rdo);

int main() {

    Nodo* pila = NULL;

    push(pila, 1);
    push(pila, 2);
    push(pila, 3);
    push(pila, 4);

    int x;
    cout << "Ingresar valor X: ";
    cin >> x;
    
    char rdo;
    insertarComoTercer(pila, x, rdo);
    cout << "Resulto exitoso?: " << rdo << endl;

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

void insertarComoTercer(Nodo* &pila, int valor, char &rdo) {
    
    int v1, v2;

    if(pila != NULL) {
        v1 = pop(pila);
        if(pila != NULL && pila->sgte != NULL) {
            v2 = pop(pila);
            rdo = 'S';
        } else {
            rdo = 'N';
        }
    } else {
        rdo = 'N';
    }

    if(rdo == 'S') {
        push(pila, valor);
        push(pila, v2);
        push(pila, v1);

        cout << "------- Pila resultante -------" << endl;
        while(pila != NULL) {
            cout << pop(pila) << endl;
        }
    }
    
}