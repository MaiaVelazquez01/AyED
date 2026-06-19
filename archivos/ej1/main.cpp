#include <iostream>
#include <stdio.h>
using namespace std;

struct Alumno {
    int legajo;
    int nota;
};

void inicializar(Alumno vec[], int len, Alumno valorIni);
void insertarOrdenado (Alumno vec [], int &len, Alumno valor);
void insertar (Alumno vec[], int &len, Alumno valor, int pos);
void mostrarVector(Alumno vec[], int len);

int main() {
    
    Alumno vec_aprobados[100];
    Alumno vec_desaprobados[100];

    int lenA = 0;
    int lenD = 0;

    Alumno valIni;
    valIni.legajo = 0;
    valIni.nota = 0;

    inicializar(vec_aprobados, lenA, valIni);
    inicializar(vec_desaprobados, lenD, valIni);
    
    FILE* Alum;
    Alumno raux;

    Alum = fopen("alumnos.dat", "rb");

    fread(&raux, sizeof(struct Alumno), 1, Alum);
    while(!feof(Alum)) {
        if(raux.nota >= 6) {
            insertarOrdenado(vec_aprobados, lenA, raux);
        } else {
            insertarOrdenado(vec_desaprobados, lenD, raux);
        }
        fread(&raux, sizeof(struct Alumno), 1, Alum);
    }

    fclose(Alum);

    cout << "Alumnos aprobados: " << endl;
    mostrarVector(vec_aprobados, lenA);
    cout << "Alumnos desaprobados: " << endl;
    mostrarVector(vec_desaprobados, lenD);

    return 0;
}

// int main() {
//    FILE *Alum;
//    Alumno rcarga;

//    Alum=fopen("alumnos.dat","wb");
  
//    cout << "Ingrese un legajo o 0 para terminar"<< endl;
//    cin >> rcarga.legajo;
//    while(rcarga.legajo!=0){
//       cout << "Ingrese la nota" << endl;
//       cin >> rcarga.nota;
//       fwrite(&rcarga,sizeof(struct Alumno),1,Alum);
//       cout << "Ingrese un legajo o 0 para terminar" << endl;
//       cin >> rcarga.legajo;
//    }
//    fclose(Alum);

//    return 0;
// }

void inicializar(Alumno vec[], int len, Alumno valorIni) {
    for(int i = 0; i < len; i++){
        vec[i].legajo = valorIni.legajo;
        vec[i].nota = valorIni.nota;
    }
}

void insertar (Alumno vec[], int &len, Alumno valor, int pos){
   for (int i= len; i>pos; i--){
    vec [i].legajo = vec [i-1].legajo;
    vec [i].nota = vec [i-1].nota;
   }
   vec[pos].legajo= valor.legajo;
   vec[pos].nota= valor.nota;
   len ++;
}

void insertarOrdenado (Alumno vec [], int &len, Alumno valor){
   int i =0;
   while (i < len && vec[i].legajo <= valor.legajo){
      i ++;
   }

   if (i==len){
    vec [len].legajo=valor.legajo;
    vec [len].nota=valor.nota;
    len ++;
   } else {
    insertar (vec,len,valor,i);
   }
}


void mostrarVector(Alumno vec[], int len) {
    for(int i = 0; i < len; i++) {
        cout << "Legajo: " << vec[i].legajo << endl;
        cout << "Nota: " << vec[i].nota << endl;
    }
}
