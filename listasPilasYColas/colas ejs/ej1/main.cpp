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
void eliminarDosNodos(Nodo* &cfte, Nodo* &cfin, char &posible);

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
    agregar(colafte, colafin, a2);

    char esPosible;
    eliminarDosNodos(colafte, colafin, esPosible);
    
    return 0;
}

void agregar(Nodo* &cfte, Nodo* &cfin, Alumno a){
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

Alumno suprimir (Nodo* &cfte, Nodo* &cfin){
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

void eliminarDosNodos(Nodo* &cfte, Nodo* &cfin, char &posible) {

    Alumno a1, a2;

    while(cfte != NULL) {
        if(cfte->sgte != NULL) {
            cout << "------ Eliminados ------" << endl;
            a1 = suprimir(cfte, cfin);
            cout << "Legajo: " << a1.legajo << " - Nombre y Apellido: " << a1.nombreApellido << " - Curso: " << a1.curso << endl;
            a2 = suprimir(cfte, cfin);
            cout << "Legajo: " << a2.legajo << " - Nombre y Apellido: " << a2.nombreApellido << " - Curso: " << a2.curso << endl;
            posible = 'S';
            cout << "Fue posible eliminar dos nodos? " << posible << endl;
            break;
        } else {
            cout << "Solo hay un nodo en la cola" << endl;
            break;
        }
    }

    if(posible != 'S') {
        posible = 'N';
        cout << "Fue posible eliminar dos nodos? " << posible << endl;
    }
}