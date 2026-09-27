#include <iostream>
#include <string>
#include "funciones.hpp"
using namespace std;

// listas
void agregarNodo(Nodo*& lista, int x) {
	Nodo* nuevo = new Nodo();
	nuevo->info = x;
	nuevo->sgte = NULL;
	if(lista == NULL){
		lista = nuevo;
	} else {
		Nodo* aux = lista;
		while(aux->sgte != NULL){ // me posiciono en el último nodo
			aux = aux->sgte;
		}
		aux->sgte = nuevo;
	}
}

void mostrar(Nodo* lista) {
	Nodo* aux = lista;
	while(aux != NULL){
		cout << aux->info << endl;
		aux = aux->sgte;
	}
}

void liberar(Nodo*& lista) {
	Nodo* aux;
	while(lista != NULL) {
		aux = lista;
		lista = lista->sgte;
		delete aux;
	}
}

Nodo* buscar(Nodo* lista, int v) {
	Nodo* aux = lista;
	while(aux != NULL && aux->info != v){
		aux = aux->sgte;
	}
	return aux;
}

void eliminar(Nodo*& lista, int v) {
	Nodo* aux = lista;
	Nodo* ant = NULL;
	while(aux != NULL && aux->info != v){
		ant = aux;
		aux = aux->sgte;
	}
	if(ant != NULL){
		ant->sgte = aux->sgte;
	} else {
		lista = aux->sgte;
	}
	delete aux;
}

int eliminarPrimerNodo(Nodo*& lista) {
	int retorno = lista->info;
	Nodo* aux = lista;
	lista = aux->sgte;
	delete aux;
	return retorno;
}

Recuperatorios eliminarPrimerNodoR(NodoR*& lista) {
	Recuperatorios retorno = lista->r;
	NodoR* aux = lista;
	lista = aux->sgte;
	delete aux;
	return retorno;
}

Nodo* insertarOrdenado(Nodo*& lista, int v) {
	Nodo* nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sgte = NULL;
	Nodo* aux = lista;
	Nodo* ant = NULL;
	while(aux != NULL && aux->info <= v){
		ant = aux;
		aux = aux->sgte;
	}
	if(ant != NULL){
		ant->sgte = nuevo;
	} else {
		lista = nuevo;
	}
	nuevo->sgte = aux;
	return nuevo;
}

void ordenar(Nodo*& lista) {
	Nodo* listaAux = NULL;
	int v;
	while(lista != NULL){
		v = eliminarPrimerNodo(lista);
		insertarOrdenado(listaAux,v);
	}
	lista = listaAux;
}

Nodo* buscaEInsertaOrdenado(Nodo*& lista, int v, bool& enc) {
	Nodo* nodoBuscado = buscar(lista,v);
	if(nodoBuscado != NULL){
		enc = true;
	} else {
		enc = false;
		nodoBuscado = insertarOrdenado(lista,v);
	}
	return nodoBuscado;
}

// pilas
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

// colas
void agregar(Nodo* &cfte, Nodo* &cfin, int a) {
   Nodo*nuevo=new Nodo();
   nuevo->info = a;
   nuevo->sgte = NULL;
   if(cfte == NULL){
      cfte = nuevo;
   } else {
      cfin->sgte = nuevo;
   }
   cfin=nuevo;
}

int suprimir (Nodo* &cfte, Nodo* &cfin) {
   int ret;
   ret = cfte->info;
   Nodo* aux = cfte;
   cfte = aux->sgte;
   if(cfte == NULL){
      cfin = NULL;
   }
   delete(aux);
   return ret;
}

// vectores
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

int buscarVectorA(Alumno arr[], int len, int v) {
	int pos;
	int i =0;
	while(i < len && arr[i].legajo != v){
		i++;
	}
	if(i != len){ // i != len condición alternativa
		pos = i;
	} else {
		pos = -1;
	}
	return pos;	
}