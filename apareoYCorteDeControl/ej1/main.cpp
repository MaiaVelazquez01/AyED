#include <iostream>
#include <stdio.h>
using namespace std;

struct Alumno {
    int legajo;
    char codigoMateria;
    int nota;
};

int main() {

    // Creo el archivo con los datos
    // FILE *Alum;
    // Alumno rcarga;
    // Alum = fopen("alumnos.dat", "wb");
    // cout << "Ingrese un legajo o 0 para terminar:" << endl;
    // cin >> rcarga.legajo;
    // while (rcarga.legajo != 0)
    // {
    //     cout << "Ingrese el codigo de la materia:" << endl;
    //     cin >> rcarga.codigoMateria;
    //     cout << "Ingrese la nota:" << endl;
    //     cin >> rcarga.nota;
    //     fwrite(&rcarga, sizeof(struct Alumno), 1, Alum);
    //     cout << "Ingrese un legajo o 0 para terminar" << endl;
    //     cin >> rcarga.legajo;
    // }
    // fclose(Alum);

    // Verifico la informacion guardada en el archivo
    // FILE *Alum;
    // Alumno raux;
    // Alum = fopen("alumnos.dat", "rb");
    // fread(&raux, sizeof(struct Alumno), 1, Alum);
    // while(!feof(Alum)) {
    //     cout << "Legajo: " << raux.legajo << " - Codigo de Materia: " << raux.codigoMateria << " - Nota: " << raux.nota << endl;
    //     fread(&raux, sizeof(struct Alumno), 1, Alum);
    // }
    // fclose(Alum);

    FILE *Alum;
    Alum = fopen("alumnos.dat", "rb");

    Alumno raux;
    int ant;
    float sumaNotas;
    int i;

    fread(&raux, sizeof(struct Alumno), 1, Alum);
    while(!feof(Alum)) {
        ant = raux.legajo;
        sumaNotas = 0;
        i = 0;

        while(!feof(Alum) && ant == raux.legajo) {
            sumaNotas = sumaNotas + raux.nota;
            fread(&raux, sizeof(struct Alumno), 1, Alum);
            i++;
        }

        cout << "El promedio del legajo " << ant << " es de " << sumaNotas / i << endl;
    }

    fclose(Alum);
    return 0;
}