#include <iostream>
using namespace std;

struct Nodo {
	char info;
    Nodo* sgte;
};

void push(Nodo* &pila, char valor);
char pop(Nodo* &pila);
bool inversa(Nodo* pila, Nodo* pila2);

int main() {

    Nodo* pila = NULL;
    Nodo* pila2 = NULL;

    char n;
    cout << "Ingrese caracteres del primer conjunto y . para terminar: ";
    cin >> n;
    while(n != '.') {
        push(pila, n);
        cout << "Ingrese caracteres del primer conjunto y . para terminar: ";
        cin >> n;
    }
    if(n == '.') {
        cout << "Ingrese caracteres del segundo conjunto y . para terminar: ";
        cin >> n;
        while(n != '.') {
            push(pila2, n);
            cout << "Ingrese caracteres del segundo conjunto y . para terminar: ";
            cin >> n;
        }
    }

    cout << "Los conjuntos son inversos? " << boolalpha << inversa(pila, pila2) << endl;

    return 0;

}

void push(Nodo* &pila, char valor) {
    Nodo* nuevo = new Nodo();
    nuevo->info = valor;
    nuevo->sgte= pila;
    pila = nuevo;
}

char pop(Nodo* &pila) {
    char ret = pila->info;
    Nodo* aux = pila;
    pila = aux->sgte;
    delete(aux);
    return ret;
}

bool inversa(Nodo* pila, Nodo* pila2) {
    Nodo* aux = NULL;
    char valor1, valor2;
    bool coinciden;

    while(pila != NULL) {
        valor1 = pop(pila);
        push(aux, valor1);
    }

    while(aux != NULL && pila2 != NULL) {
        valor1 = pop(aux);
        valor2 = pop(pila2);
        if(valor1 == valor2) {
            coinciden = true;
        } else {
            coinciden = false;
            return coinciden;
        }
    }

    return coinciden;
}