#include <iostream>
using namespace std;

struct Nodo {
	int info;
    Nodo* sgte;
};

struct Producto {
    int cod;
    int precio;
    int sdisp;
    int smin;
};

struct Venta {
    int codP;
    int cantV;
};

struct NodoV {
    Venta info;
    NodoV* sgte;
};

struct ProductoF {
    int codF;
};

struct NodoF {
    ProductoF info;
    NodoF* sgte;
};

struct ProductoA {
    int codA;
    int sdispA;
};

struct NodoA {
    ProductoA info;
    NodoA* sgte;
};

struct Inscripcion {
    int legajo;
    int curso;
    int nota;
    int inas;
    int anio;
};

struct NodoI {
    Inscripcion info;
    NodoI* sgte;
};

struct Aprobado {
    int legajoA;
    int cursoA;
    int notaA;
};

struct NodoAp {
    Aprobado info;
    NodoAp* sgte;
};

int pop(Nodo* &pila);
void liberarI(NodoI*& lista);
NodoI* insertarOrdenadoI(NodoI*& lista, Inscripcion i);
NodoA* insertarOrdenadoA(NodoA*& lista, ProductoA v);
NodoF* insertarOrdenadoF(NodoF*& lista, int v);
Nodo* insertarOrdenado(Nodo*& lista, int v);
int suprimir (Nodo*&cfte,Nodo*&cfin);
void listaOrdenadaUnion(Nodo*& pila, int vec[], int len);
Nodo* buscar(Nodo* lista, int v);
Nodo* listaOrdenadaInterseccion(Nodo*& cfte, Nodo*& cfin, Nodo*& lista);
int buscarVector(Producto arr[], int len, int v);
NodoAp* insertarOrdenadoAp(NodoAp*& lista, Aprobado a);
void liberarAp(NodoAp*& lista);
void mostrarAp(NodoAp* lista);

int main() {

    //1a
    int vec[100];
    int lenV;
    Nodo* pila;
    listaOrdenadaUnion(pila, vec, lenV);

    //1b
    Nodo* cfte=NULL;
	Nodo* cfin=NULL;
    Nodo* lista = NULL;
    listaOrdenadaInterseccion(cfte, cfin, lista);

    //2
    Producto vecP[100];
    int lenP;
    NodoV* listaV;
    NodoV* aux = listaV;
    NodoF* listaF = NULL;
    NodoA* listaA = NULL;
    int pos, codigo, cantF = 0, importe = 0;

    ProductoA prodA;

    while(aux != NULL){
        pos = buscarVector(vecP, lenP, aux->info.codP);
        if (pos != -1) {
            if(aux->info.cantV <= vecP[pos].sdisp) {
                vecP[pos].sdisp -= aux->info.cantV;
                if(vecP[pos].sdisp < vecP[pos].smin){
                    prodA.codA = vecP[pos].cod;
                    prodA.sdispA = vecP[pos].sdisp;
                    insertarOrdenadoA(listaA, prodA);
                }
            } else {
                codigo = vecP[pos].cod;
                importe += vecP[pos].precio * aux->info.cantV;
                insertarOrdenadoF(listaF, codigo);
                cantF++;
            }
        } else {
            cout << "No se encontro producto con ese id" << endl;
        }
        aux = aux->sgte;
    }
    
    //3
    FILE* Ins;
    Inscripcion raux;
    NodoI* listaI = NULL;
    NodoAp* listaAp = NULL;
    Aprobado a;
    int noCumplen = 0;

    Ins = fopen("Inscripciones.dat", "rb");

    fread(&raux, sizeof(struct Inscripcion), 1, Ins);
    while(!feof(Ins)){
        insertarOrdenadoI(listaI, raux);
        a.legajoA = raux.legajo;
        a.cursoA = raux.curso;
        a.notaA = raux.nota;
        if(raux.nota >= 6 && raux.inas <= 2 && raux.anio == 2026) {
            insertarOrdenadoAp(listaAp, a);
        } else {
            noCumplen++;
        }
        fread(&raux, sizeof(struct Inscripcion), 1, Ins);
    }

    fclose(Ins);

    Ins = fopen("Inscripciones.dat", "wb");

    while(listaI != NULL){
        raux = listaI->info;
        fwrite(&raux, sizeof(struct Inscripcion), 1, Ins);
        listaI = listaI->sgte;
    }

    fclose(Ins);
    liberarI(listaI);

    mostrarAp(listaAp);
    liberarAp(listaAp);

    cout << "Cantidad de alumnos que no cumplen con alguna condicion para formar parte de la lista: " << noCumplen << endl;

    return 0;
}

int pop(Nodo* &pila) {
    int ret = pila->info;
    Nodo* aux = pila;
    pila = aux->sgte;
    delete(aux);
    return ret;
}

void liberarAp(NodoAp*& lista) {
	NodoAp* aux;
	while(lista != NULL) {
		aux = lista;
		lista = lista->sgte;
		delete aux;
	}
}

void mostrarAp(NodoAp* lista) {
	NodoAp* aux = lista;
	while(aux != NULL){
		cout << aux->info.legajoA << endl;
        cout << aux->info.cursoA << endl;
        cout << aux->info.notaA << endl;
		aux = aux->sgte;
	}
}

void liberarI(NodoI*& lista) {
	NodoI* aux;
	while(lista != NULL) {
		aux = lista;
		lista = lista->sgte;
		delete aux;
	}
}

NodoAp* insertarOrdenadoAp(NodoAp*& lista, Aprobado a) {
    NodoAp* nuevo = new NodoAp();
	nuevo->info.legajoA = a.legajoA;
	nuevo->sgte = NULL;
	NodoAp* aux = lista;
	NodoAp* ant = NULL;
	while(aux != NULL && aux->info.legajoA <= a.legajoA){
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

NodoI* insertarOrdenadoI(NodoI*& lista, Inscripcion i) {
    NodoI* nuevo = new NodoI();
	nuevo->info.legajo = i.legajo;
	nuevo->sgte = NULL;
	NodoI* aux = lista;
	NodoI* ant = NULL;
	while(aux != NULL && aux->info.legajo <= i.legajo){
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

NodoA* insertarOrdenadoA(NodoA*& lista, ProductoA v) {
	NodoA* nuevo = new NodoA();
	nuevo->info.codA = v.codA;
	nuevo->sgte = NULL;
	NodoA* aux = lista;
	NodoA* ant = NULL;
	while(aux != NULL && aux->info.codA <= v.codA){
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

NodoF* insertarOrdenadoF(NodoF*& lista, int v) {
	NodoF* nuevo = new NodoF();
	nuevo->info.codF = v;
	nuevo->sgte = NULL;
	NodoF* aux = lista;
	NodoF* ant = NULL;
	while(aux != NULL && aux->info.codF <= v){
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

void listaOrdenadaUnion(Nodo*& pila, int vec[], int len) {
    
    int n;
    Nodo* lista = NULL;

    while(pila != NULL) {
        n = pop(pila);
        insertarOrdenado(lista, n);
    }

    for(int i = 0; i < len; i++){
        insertarOrdenado(lista, vec[i]);
    }

}

int suprimir (Nodo*&cfte,Nodo*&cfin) {
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

Nodo* buscar(Nodo* lista, int v) {
	Nodo* aux = lista;
	
	while(aux != NULL && aux->info != v){
		aux = aux->sgte;
	}
	
	return aux;
}

Nodo* listaOrdenadaInterseccion(Nodo*& cfte, Nodo*& cfin, Nodo*& lista) {
    Nodo* lista2 = NULL;
    Nodo* aux;
    
    int valorC;
    while(cfte != NULL) {
        valorC = suprimir(cfte, cfin);
        aux = buscar(lista, valorC);
        if(aux != NULL) {
            insertarOrdenado(lista2, valorC);
        }
    }
}

int buscarVector(Producto arr[], int len, int v) {
	int pos;
	int i =0;
	
	while(i < len && arr[i].cod != v){
		i++;
	}
	
	if(i != len){ // i != len condición alternativa
		pos = i;
	} else {
		pos = -1;
	}
	
	return pos;	
}