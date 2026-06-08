#include <iostream>
#include <stdio.h>
using namespace std;

struct Alumno {
    int legajo;
    int nota;
};

void mostrarVector(int vec[], int len);

int main() {
    // FILE *Alum;
    // Alumno rcarga;
    // int len = 3;
    // int i = 0;
    // Alum = fopen("alumnos.dat", "wb");
    // cout << "Ingrese el legajo del alumno (0 para finalizar): ";
    // cin >> rcarga.legajo;
    // while (rcarga.legajo != 0 && i < len)
    // {
    //     cout << "Ingrese la nota del alumno: ";
    //     cin >> rcarga.nota;
    //     fwrite(&rcarga, sizeof(Alumno), 1, Alum);
    //     i++;
    //     if (i < len) {
    //         cout << "Ingrese el legajo del alumno (0 para finalizar): ";
    //         cin >> rcarga.legajo;
    //     }
    // }
    // fclose(Alum);
    
    int vec_aprobados[100];
    int vec_desaprobados[100];
  
    int iA = 0;
    int iD = 0;

    FILE* Alum;
    Alumno raux;

    Alum = fopen("alumnos.dat", "rb");

    fread(&raux, sizeof(struct Alumno), 1, Alum);
    while(!feof(Alum)) {
        if(raux.nota >= 6) {
            vec_aprobados[iA] = raux.legajo;
            iA++;
        } else {
            vec_desaprobados[iD] = raux.legajo;
            iD++;
        }
        fread(&raux, sizeof(struct Alumno), 1, Alum);
    }

    fclose(Alum);

    cout << "Legajos de alumnos aporbados: " << endl;
    mostrarVector(vec_aprobados, iA);
    cout << "Legajos de alumnos desaprobados: " << endl;
    mostrarVector(vec_desaprobados, iD);

    return 0;
}

void mostrarVector(int vec[], int len) {
    for(int i = 0; i < len; i++) {
        cout << vec[i] << endl;
    }
}