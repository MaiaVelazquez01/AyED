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

void agregar(Nodo*&cfte,Nodo*&cfin, Alumno a);
Alumno suprimir (Nodo*&cfte,Nodo*&cfin);
void unirColas(Nodo* &cfteA, Nodo* &cfinA, Nodo* &cfteB, Nodo* &cfinB);

int main() {

    Nodo* colafte = NULL;
	Nodo* colafin = NULL;
    Nodo* cola2fte = NULL;
	Nodo* cola2fin = NULL;

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
    agregar(cola2fte, cola2fin, a3);

    unirColas(colafte, colafin, cola2fte, cola2fin);

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

void unirColas(Nodo* &cfteA, Nodo* &cfinA, Nodo* &cfteB, Nodo* &cfinB) {

    Nodo* cfteC = NULL;
    Nodo* cfinC = NULL;
    Alumno a;

    while(cfteA != NULL) {
        a = suprimir(cfteA, cfinA);
        agregar(cfteC, cfinC, a);
    }
    while(cfteB != NULL) {
        a = suprimir(cfteB, cfinB);
        agregar(cfteC, cfinC, a);
    }

    cout << "------ Cola resultante ------" << endl;
    while(cfteC != NULL) {
        a = suprimir(cfteC, cfinC);
        cout << "Legajo: " << a.legajo << " - Nombre y Apellido: " << a.nombreApellido << " - Curso: " << a.curso << endl;
    }
}