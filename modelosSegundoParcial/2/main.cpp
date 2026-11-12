#include <iostream>
using namespace std;

struct Nodo {
    int info;
    Nodo* sgte;
};

struct Alumno {
    int legajo;
    int primerP;
    int segundoP;
};

struct Recuperatorio {
    int legajoR;
    int segundoR;
};

struct NodoR {
    Recuperatorio info;
    NodoR* sgte;
};

struct Resultado {
    int idPais;
    int mOro;
    int mPlata;
    int mBronce;
};

struct NodoRM {
    Resultado info;
    NodoRM* sgte;
};

Nodo* insertarOrdenado(Nodo*& lista, int v);
int suprimir (Nodo* &cfte, Nodo* &cfin);
void unionDosColas(Nodo*& cfte1, Nodo*& cfin1, Nodo*& cfte2, Nodo*& cfin2);
int buscarVector(int arr[], int len, int v);
Nodo* interseccionColaVector(Nodo*& cfte, Nodo*& cfin, int vec[], int len);
int buscarVectorA(Alumno arr[], int len, int v);
NodoRM* insertarOrdenadoR(NodoRM*& lista, Resultado v);
NodoRM* insertarOrdenadoM(NodoRM*& lista, Resultado v);
void liberar(NodoRM*& lista);

int main() {

    //1a
    Nodo* cfte1;
    Nodo* cfin1;
    Nodo* cfte2;
    Nodo* cfin2;
    unionDosColas(cfte1, cfin1, cfte2, cfin2);

    //1b
    Nodo* cfte3;
    Nodo* cfin3;
    int vec[100];
    int len;
    interseccionColaVector(cfte3, cfin3, vec, len);

    //2a
    Alumno k1151[50];
    int lenA;
    NodoR* listaR;
    NodoR* aux = listaR;
    int notaR, posL;

    while(aux != NULL) {
        notaR = aux->info.segundoR;
        posL = buscarVectorA(k1151, lenA, aux->info.legajoR);

        if(notaR >= 6 && posL != -1) {
            k1151[posL].segundoP = notaR;
        }

        aux = aux->sgte;
    }

    //3
    FILE* Rdos;
    Resultado raux;
    NodoRM* lista = NULL;
    NodoRM* ganoMedallasDeOro = NULL;

    Rdos = fopen("Medallero.dat", "rb");

    fread(&raux, sizeof(struct Resultado), 1, Rdos);
    while(!feof(Rdos)){
        insertarOrdenadoR(lista, raux);
        if(raux.mOro >= 1) {
            insertarOrdenadoM(ganoMedallasDeOro, raux);
        }
        fread(&raux, sizeof(struct Resultado), 1, Rdos);
    }
    fclose(Rdos);

    NodoRM* auxR = lista;

    Rdos = fopen("Medallero.dat", "wb");
    while(auxR != NULL) {
        raux = auxR->info;
        fwrite(&raux, sizeof(struct Resultado), 1, Rdos);
        auxR = auxR->sgte;
    }
    fclose(Rdos);
    liberar(lista);

    return 0;
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

void unionDosColas(Nodo*& cfte1, Nodo*& cfin1, Nodo*& cfte2, Nodo*& cfin2) {
    Nodo* lista = NULL;
    int v;

    while(cfte1 != NULL) {
        v = suprimir(cfte1, cfin1);
        insertarOrdenado(lista, v);
    }

    while(cfte2 != NULL) {
        v = suprimir(cfte2, cfin2);
        insertarOrdenado(lista, v);
    }
}

int buscarVector(int arr[], int len, int v) {
	int pos;
	int i =0;
	while(i < len && arr[i] != v){
		i++;
	}
	if(i != len){
		pos = i;
	} else {
		pos = -1;
	}
	return pos;	
}

Nodo* interseccionColaVector(Nodo*& cfte, Nodo*& cfin, int vec[], int len) {
    Nodo* lista = NULL;
    int v;

    while(cfte != NULL) {
        v = suprimir(cfte, cfin);
        if(buscarVector(vec, len, v) != -1) {
            insertarOrdenado(lista, v);
        }
    }

    return lista;
}

int buscarVectorA(Alumno arr[], int len, int v) {
	int pos;
	int i =0;
	while(i < len && arr[i].legajo != v){
		i++;
	}
	if(i != len){
		pos = i;
	} else {
		pos = -1;
	}
	return pos;	
}

NodoRM* insertarOrdenadoR(NodoRM*& lista, Resultado v) {
	NodoRM* nuevo = new NodoRM();
	nuevo->info = v;
	nuevo->sgte = NULL;
	NodoRM* aux = lista;
	NodoRM* ant = NULL;
	while(aux != NULL && aux->info.idPais <= v.idPais){
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

NodoRM* insertarOrdenadoM(NodoRM*& lista, Resultado v) {
	NodoRM* nuevo = new NodoRM();
	nuevo->info = v;
	nuevo->sgte = NULL;
	NodoRM* aux = lista;
	NodoRM* ant = NULL;
	while(aux != NULL && aux->info.mOro <= v.mOro){
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

void liberar(NodoRM*& lista) {
	NodoRM* aux;
	while(lista != NULL) {
		aux = lista;
		lista = lista->sgte;
		delete aux;
	}
}