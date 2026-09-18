#include <iostream>
using namespace std;

struct Nodo {
	int info;
    Nodo* sgte;
};

void push(Nodo* &pila, int valor);
int pop(Nodo* &pila);
void agregar(Nodo*&cfte,Nodo*&cfin,int valor);
int suprimir (Nodo*&cfte,Nodo*&cfin);
void agregarNodo(Nodo* &lista, int x);
int buscarVector(int arr[], int len, int v);

int main() {

    // Combinar pila con cola en una lista
    // Nodo* pila = NULL;
    // push(pila, 3);
    // push(pila, 2);
    // push(pila, 1);
    // Nodo*colafte=NULL;
	// Nodo*colafin=NULL;
    // agregar(colafte, colafin, 7);
    // agregar(colafte, colafin, 9);
    // agregar(colafte, colafin, 11);
    // Nodo* lista = NULL;
    // int valorP, valorC;
    // while(pila != NULL) {
    //     valorP = pop(pila);
    //     agregarNodo(lista, valorP);
    // }
    // while(colafte != NULL) {
    //     valorC = suprimir(colafte, colafin);
    //     agregarNodo(lista, valorC);
    // }

    // Combinar pila con lista en una lista
    // Nodo* pila = NULL;
    // push(pila, 3);
    // push(pila, 2);
    // push(pila, 1);
    // Nodo* lista = NULL;
    // agregarNodo(lista, 7);
    // agregarNodo(lista, 6);
    // agregarNodo(lista, 5);
    // Nodo* lista2 = NULL;
    // lista2 = lista;
    // int valorP;
    // while(pila != NULL) {
    //     valorP = pop(pila);
    //     agregarNodo(lista2, valorP);
    // }

    // Combinar cola con lista en una lista
    // Nodo*colafte=NULL;
	// Nodo*colafin=NULL;
    // Nodo* lista = NULL;
    // Nodo* lista2 = NULL;
    // lista2 = lista;
    // int valorC;
    // while(colafte != NULL) {
    //     valorC = suprimir(colafte, colafin);
    //     agregarNodo(lista, valorC);
    // }

    // Interseccion de una pila y una lista a una lista
    // Nodo* pila = NULL;
    // Nodo* lista = NULL;
    // Nodo* lista2 = NULL;
    // Nodo* aux;
    // int valorP;
    // while(pila != NULL) {
    //     valorP = pop(pila);
    //     aux = buscar(lista, valorP);
    //     if(aux != NULL) {
    //         agregarNodo(lista2, valorP);
    //     }
    // }

    // Interseccion de una cola y una lista a una lista
    // Nodo* colafte=NULL;
	// Nodo* colafin=NULL;
    // Nodo* lista = NULL;
    // Nodo* lista2 = NULL;
    // Nodo* aux;
    // int valorC;
    // while(colafte != NULL) {
    //     valorC = suprimir(colafte, colafin);
    //     aux = buscar(lista, valorC);
    //     if(aux != NULL) {
    //         agregarNodo(lista2, valorC);
    //     }
    // }

    // Interseccion de una pila y un vector a una lista
    // int vec[4];
    // int len;
    // Nodo* pila = NULL;
    // Nodo* lista2 = NULL;
    // int valorP, aux;
    // while(pila != NULL) {
    //     valorP = pop(pila);
    //     aux = buscarVector(vec, len, valorP);
    //     if(aux =! -1) {
    //         agregarNodo(lista2, valorP);
    //     }
    // }

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

void agregar(Nodo*&cfte,Nodo*&cfin,int valor){
   Nodo*nuevo=new Nodo();
   nuevo->info=valor;
   nuevo->sgte=NULL;

   if(cfte==NULL){
      cfte=nuevo;
   }else{
      cfin->sgte=nuevo;
   }
   cfin=nuevo;
}

int suprimir (Nodo*&cfte,Nodo*&cfin){
   int ret;
   ret=cfte->info;
   Nodo*aux=cfte;
   cfte=aux->sgte; //cfte=cfte->sgte;
   if(cfte==NULL){
      cfin=NULL;
   }
   delete(aux);
   return ret;
}

void agregarNodo(Nodo* &lista, int x) {

    Nodo* nuevo = new Nodo();
    nuevo->info = x;
    nuevo->sgte = NULL;

    if(lista == NULL) {
        lista = nuevo;
    } else {
        Nodo* aux = lista;
        while(aux->sgte != NULL) {
            aux = aux->sgte;
        }
        aux->sgte = nuevo;
    }

}

Nodo* buscar(Nodo* lista, int v){
	Nodo* aux = lista;
	
	while(aux != NULL && aux->info != v){
		aux = aux->sgte;
	}
	
	return aux;
}

void mostrar(Nodo* lista){
	Nodo* aux = lista;
	
	while(aux != NULL){
		cout << aux->info << endl;
		aux = aux->sgte;
	}
}

int buscarVector(int arr[], int len, int v) {
	int pos;
	int i =0;
	
	while(i < len && arr[i] != v){
		i++;
	}
	
	if(i != len){ // i != len condición alternativa
		pos = i;
	} else {
		pos = -1;
	}
	
	return pos;	
}