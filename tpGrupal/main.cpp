#include <iostream>
using namespace std;

struct Jugador {
    int codigo;
    int edad;
    int goles;
    int posicion;
};

struct Nodo {
	Jugador info;
    Nodo* sgte;
};

Nodo* insertarOrdenado(Nodo*& lista, Jugador j);
void tieneMenosDe23(Jugador vec[], int &len, Jugador j);
void push(Nodo* &pila, Jugador j);
Jugador pop(Nodo* &pila);
void eliminar(Nodo*& lista, Jugador j);
Jugador maximoGoleador(Nodo* &lista);
void topGoleadores(Nodo* &lista, Nodo* &pila);

int main() {

	Nodo* lista = NULL;
	Jugador menoresA23[26];
	int len = 0;
	Nodo* pila = NULL;

    FILE* plantel;
    Jugador raux;

	plantel = fopen("plantel.dat", "rb");

	fread(&raux, sizeof(struct Jugador), 1, plantel);
	while(!feof(plantel)) {
		tieneMenosDe23(menoresA23, len, raux);
		insertarOrdenado(lista, raux);
		fread(&raux, sizeof(struct Jugador), 1, plantel);
	}

	fclose(plantel);

	plantel = fopen("plantel.dat", "wb");

	Nodo* aux = lista;

	while(aux != NULL) {
		raux = aux->info;
		fwrite(&raux, sizeof(struct Jugador), 1, plantel);
		aux = aux->sgte;
	}

	fclose(plantel);

	cout << "------- Jugadores cuya edad es menor a 23 anios -------" << endl;
	for(int i = 0; i < len; i++) {
		cout << "Codigo: " << menoresA23[i].codigo << " - Edad: " << menoresA23[i].edad << " Goles: " << menoresA23[i].goles << " Posicion: " << menoresA23[i].posicion << endl;
	}

	cout << "------- Top Goleadores -------" << endl;
	topGoleadores(lista, pila);

	return 0;
}

Nodo* insertarOrdenado(Nodo*& lista, Jugador j) {
	Nodo* nuevo = new Nodo();
	nuevo->info = j;
	nuevo->sgte = NULL;
	Nodo* aux = lista;
	Nodo* ant = NULL;
	while(aux != NULL){
		if(aux->info.posicion < j.posicion) {
			ant = aux;
			aux = aux->sgte;
		} else if(aux->info.posicion == j.posicion && aux->info.edad <= j.edad) {
			ant = aux;
			aux = aux->sgte;
		} else {
			break;
		}
	}
	if(ant != NULL){
		ant->sgte = nuevo;
	} else {
		lista = nuevo;
	}
	nuevo->sgte = aux;
	return nuevo;
}

void tieneMenosDe23(Jugador vec[], int &len, Jugador j) {
	if(j.edad < 23) {
		vec[len] = j;
		len++;
	}
}

void push(Nodo* &pila, Jugador j) {
    Nodo* nuevo = new Nodo();
    nuevo->info = j;
    nuevo->sgte= pila;
    pila = nuevo;
}

Jugador pop(Nodo* &pila) {
    Jugador ret = pila->info;
    Nodo* aux = pila;
    pila = aux->sgte;
    delete(aux);
    return ret;
}

void eliminar(Nodo*& lista, Jugador j) {
	Nodo* aux = lista;
	Nodo* ant = NULL;
	while(aux != NULL && aux->info.codigo != j.codigo){
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

Jugador maximoGoleador(Nodo* &lista) {

	Nodo* aux = lista;
	Jugador max = aux->info;

	while(aux != NULL) {
		if(aux->info.goles > max.goles) {
			max = aux->info;
		}
		aux = aux->sgte;
	}

	return max;
}

void topGoleadores(Nodo* &lista, Nodo* &pila) {
	int top = 5;
	int i;
	Jugador max;

	for(i = 0; i < top && lista != NULL; i++) {
		max = maximoGoleador(lista);
		push(pila, max);
		eliminar(lista, max);
	}

	if(i < top) {
		cout << "No se pudo completar el Top 5 porque hay " << i + 1 << " jugadores en el archivo" << endl;
	}

	while(pila != NULL) {
		max = pop(pila);
		cout << "Codigo: " << max.codigo << " - Goles: " << max.goles << endl;
	}
}