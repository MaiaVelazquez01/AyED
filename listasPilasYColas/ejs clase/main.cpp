#include <iostream>
using namespace std;

struct Nodo {
	int info;
    Nodo* sgte;
};

struct NodoP {
    Producto info;
    NodoP* sgte;
};

struct NodoH {
    Reserva info;
    Nodo* sgte;
};

struct Habitacion {
    int id;
    int cantN;
    int cantReservas;
};

struct Reserva {
    int idHabitacion;
    int cantNoches;
};

struct Producto {
    int id;
    int cant;
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

    // Llevar cada elemnento de la lista a un vector (insertar ordenadamente)
    // int vec[10];
    // int len;
    // Nodo* lista = NULL;
    // int aux;
    // while(lista != NULL) {
    //     aux = eliminarPrimerNodo(lista);
    //     insertarOrdenado(vec, len, aux);
    // }

    // Dada la lista con las novedades actualizar el stock del vector
    // Producto vec[10];
    // int len, pos, n;
    // NodoP* novedades;
    // NodoP* aux = novedades;
    // while(aux != NULL) {
    //     pos = buscarVectorP(vec, len, aux->info.id);
    //     if(pos != -1) {
    //         vec[pos].cant += aux->info.cant;
    //     } else {
    //         Producto nuevoProd;
    //         nuevoProd.id = aux->info.id;
    //         nuevoProd.cant = aux->info.cant;
    //         agregarP(vec, n, len, nuevoProd);
    //     }
    //     aux = aux->sgte;
    // }

    // Existe un vector de Habitaciones y una lista de Reservas. Actualizar en el vector los campos cantidad de noches y cantidad de reservas
    // Habitacion vec[10];
    // int len;
    // NodoH* lista;
    // int pos;
    // while(lista != NULL){
    //     pos = buscar(vec, len, lista->info.idHabitacion);
    //     if (pos != -1) {
    //         vec[pos].cantN += lista->info.cantNoches;
    //         vec[pos].cantReservas++;
    //     } else {
    //         cout << "No se encontro habitacion con ese id" << endl;
    //     }
    //     lista = lista->sgte;
    // }

    
    return 0;
}

void agregar(int arr[], int n, int& len, int v){
	if(len < n){
		arr[len] = v;
		len++;
	} else {
		cout << "El vector esta lleno" << endl;
	}
}

void agregarP(Producto arr[], int n, int& len, Producto v){
	if(len < n){
		arr[len] = v;
		len++;
	} else {
		cout << "El vector esta lleno" << endl;
	}
}

int eliminarPrimerNodo(Nodo*& lista){
	int retorno = lista->info;
	Nodo* aux = lista;
	lista = aux->sgte;
	delete aux;
	return retorno;
}

void insertar(int arr[], int& len, int v, int pos){
	
	//for(int i = len-1; i >= pos; i--){
	//	arr[i+1] = arr[i];
	//}
	
	//Opción 2
	for(int i = len; i > pos; i--){
		arr[i]=arr[i-1];
	}
	
	arr[pos] = v;
	len++;
}

int insertarOrdenado(int arr[], int& len, int v){
	int i = 0;
	
	while(i < len && arr[i] < v ){
		i++;
	} 
	
	insertar(arr,len,v,i);
	
	return i;
}

int buscaEInserta(int arr[], int& len, int v, bool& enc){
	int pos = buscarVector(arr,len,v);
	
	if(pos == -1){
		enc = false;
		pos = insertarOrdenado(arr,len,v);
	} else {
		enc = true;
	}
	
	return pos;
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

int buscarVectorP(Producto arr[], int len, Producto v) {
	int pos;
	int i =0;
	
	while(i < len && arr[i].id != v.id){
		i++;
	}
	
	if(i != len){ // i != len condición alternativa
		pos = i;
	} else {
		pos = -1;
	}
	
	return pos;	
}