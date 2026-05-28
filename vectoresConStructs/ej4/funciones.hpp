#include <string>
using namespace std;

struct Estudiante {
    int legajo;
    string nombre;
    int nota;
};

#ifndef funciones
#define funciones

void mostrarMenu();
int buscar(Estudiante vec[], int len, string nombre);
void buscarEImprimirAlumno(Estudiante vec[], int len);
void modificarNota(Estudiante vec[], int len);
void promedioDeNotas(Estudiante vec[], int len);
int buscarMejorNota(Estudiante vec[], int len);
void buscarEstudianteConMejorNota(Estudiante vec[], int len);
int buscarMenorNota(Estudiante vec[], int len);
void buscarEstudianteConMenorNota(Estudiante vec[], int len);

#endif