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
void generarColaPorApareo(Nodo* &cfte, Nodo* &cfin, Nodo* &cfte2, Nodo* &cfin2);

int main() {

    Nodo*colafte = NULL;
	Nodo*colafin = NULL;
    Nodo*colafte2 = NULL;
	Nodo*colafin2 = NULL;

    Alumno a1, a2, a3, a4;

    a1.legajo = 111111;
    strcpy(a1.nombreApellido, "Maia Velazquez");
    strcpy(a1.curso, "K5968");
    a2.legajo = 111113;
    strcpy(a2.nombreApellido, "Pepe Gonzalez");
    strcpy(a2.curso, "K5978");
    a3.legajo = 111112;
    strcpy(a3.nombreApellido, "Ana Benitez");
    strcpy(a3.curso, "K5869");
    a4.legajo = 111114;
    strcpy(a4.nombreApellido, "Ana Benitez");
    strcpy(a4.curso, "K5869");

    agregar(colafte, colafin, a1);
    agregar(colafte, colafin, a2);
    agregar(colafte2, colafin2, a3);
    agregar(colafte2, colafin2, a4);

    generarColaPorApareo(colafte, colafin, colafte2, colafin2);

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

Alumno suprimir(Nodo* &cfte, Nodo* &cfin) {
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

void generarColaPorApareo(Nodo* &cfte, Nodo* &cfin, Nodo* &cfte2, Nodo* &cfin2) {

    Nodo* cfteC = NULL;
    Nodo* cfinC = NULL;

    Alumno a1, a2, a;

    a1 = suprimir(cfte, cfin);
    a2 = suprimir(cfte2, cfin2);

    while(cfte != NULL && cfte2 != NULL) {
        if(a1.legajo < a2.legajo) {
            agregar(cfteC, cfinC, a1);
            a1 = suprimir(cfte, cfin);
        } else {
            agregar(cfteC, cfinC, a2);
            a2 = suprimir(cfte2, cfin2);
        }
    }

    if(a1.legajo < a2.legajo) {
        agregar(cfteC, cfinC, a1);
        agregar(cfteC, cfinC, a2);
    } else {
        agregar(cfteC, cfinC, a2);
        agregar(cfteC, cfinC, a1);
    }

    while(cfte != NULL) {
        a1 = suprimir(cfte, cfin);
        agregar(cfteC, cfinC, a1);
    }

    while(cfte2 != NULL) {
        a2 = suprimir(cfte2, cfin2);
        agregar(cfteC, cfinC, a2);
    }


    cout << "------ Cola resultante ------" << endl;
    while(cfteC != NULL) {
        a = suprimir(cfteC, cfinC);
        cout << "Legajo: " << a.legajo << " - Nombre y Apellido: " << a.nombreApellido << " - Curso: " << a.curso << endl;
    }

}