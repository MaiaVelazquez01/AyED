#include <iostream>
#include <string.h>
using namespace std;

struct Alumno {
    int legajo;
    char nombreApellido[100];
    char curso[6];
};

struct Nodo {
	Alumno alumno;
    Nodo* sgte;
};

void agregar(Nodo* &cfte,Nodo* &cfin, Alumno a);
Alumno suprimir(Nodo* &cfte,Nodo* &cfin);
int cantidadNodos(Nodo* &cfte, Nodo* &cfin);
void imprimirSegunCondicion(Nodo* &cfte,Nodo* &cfin);

int main() {

    Nodo*colafte = NULL;
	Nodo*colafin = NULL;

    Alumno a1, a2, a3;

    a1.legajo = 1744669;
    strcpy(a1.nombreApellido, "Maia Velazquez");
    strcpy(a1.curso, "K5968");
    a2.legajo = 1744589;
    strcpy(a2.nombreApellido, "Pepe Gonzalez");
    strcpy(a2.curso, "K5978");
    a3.legajo = 1744779;
    strcpy(a3.nombreApellido, "Ana Benitez");
    strcpy(a3.curso, "K5869");

    agregar(colafte, colafin, a1);
    agregar(colafte, colafin, a2);
    agregar(colafte, colafin, a3);

    imprimirSegunCondicion(colafte, colafin);

    return 0;

}

void agregar(Nodo* &cfte, Nodo* &cfin, Alumno a) {
   Nodo*nuevo=new Nodo();
   nuevo->alumno = a;
   nuevo->sgte = NULL;

   if(cfte == NULL){
      cfte = nuevo;
   } else {
      cfin->sgte = nuevo;
   }
   cfin=nuevo;
}

Alumno suprimir (Nodo* &cfte, Nodo* &cfin) {
   Alumno ret;
   ret = cfte->alumno;
   Nodo* aux = cfte;
   cfte = aux->sgte;
   if(cfte == NULL){
      cfin = NULL;
   }
   delete(aux);
   return ret;
}

int cantidadNodos(Nodo* &cfte, Nodo* &cfin) {

    Nodo*cola2fte = NULL;
	Nodo*cola2fin = NULL;
    Alumno a;
    int i = 0;
    while(cfte != NULL) {
        a = suprimir(cfte, cfin);
        i++;
        agregar(cola2fte, cola2fin, a);
    }

    while(cola2fte != NULL) {
        a = suprimir(cola2fte, cola2fin);
        agregar(cfte, cfin, a);
    }

    return i;

}

void imprimirSegunCondicion(Nodo* &cfte, Nodo* &cfin) {

    Alumno a;
    Nodo* cfte2 = NULL;
    Nodo* cfin2 = NULL;

    int cantNodos = cantidadNodos(cfte,cfin);

    if(cantNodos > 100) {
        a = suprimir(cfte, cfin);
        cout << "Legajo: " << a.legajo << " - Nombre y Apellido: " << a.nombreApellido << " - Curso: " << a.curso << endl;
    } else if (cantNodos == 0) {
        return;
    } else {
        while(cfte != NULL) {
            a = suprimir(cfte, cfin);
            if(cfte == NULL) {
                cout << "Legajo: " << a.legajo << " - Nombre y Apellido: " << a.nombreApellido << " - Curso: " << a.curso << endl;
                imprimirSegunCondicion(cfte2, cfin2);
            } else {
                agregar(cfte2, cfin2, a);
            }
        }
    }
}