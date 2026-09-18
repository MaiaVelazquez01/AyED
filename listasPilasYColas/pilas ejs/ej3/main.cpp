#include <iostream>
using namespace std;

struct Nodo {
	int info;
    Nodo* sgte;
};

void push(Nodo* &pila, int valor);
int pop(Nodo* &pila);
void insertarXEnPosicionY(Nodo* &pila, int valor, int pos);

int main() {

    Nodo* pila = NULL;

    push(pila, 1);
    push(pila, 2);
    push(pila, 3);
    push(pila, 4);
    push(pila, 5);

    int x, y;

    cout << "Ingrese el valor a insertar: ";
    cin >> x;
    cout << "Ingrese la posicion en la que lo desea ingresar: ";
    cin >> y;
    insertarXEnPosicionY(pila, x, y);

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

void insertarXEnPosicionY(Nodo* &pila, int valor, int pos) {

    Nodo* aux = NULL;
    int i = pos, valorP;

    if(pila == NULL) {

        cout << "La pila no tiene elementos" << endl;

    } else if(pos == 1) {

        pop(pila);
        push(pila, valor);
        cout << "------- Pila resultante -------" << endl;
        while(pila != NULL) {
            cout << pop(pila) << endl;
        }

    } else {

        while(i > 1 && pila != NULL) {
            valorP = pop(pila);
            push(aux, valorP);
            i--;
        }

        if(pila == NULL) {

            cout << "No existe la posicion " << pos << " en la pila" << endl;
            while(i < pos) {
                push(pila, pop(aux));
                i++;
            }

        } else {

            push(pila, valor);
            i = 1;
            while(i < pos) {
                push(pila, pop(aux));
                i++;
            }

        }

        cout << "------- Pila resultante -------" << endl;
        while(pila != NULL) {
            cout << pop(pila) << endl;
        }
    }

}