#include <string>
using namespace std;

struct Comision {
    string nombreMateria;
    int cantInscriptos;
};

#ifndef funciones
#define funciones

int calcularMaxInscriptos(Comision vec[], int len);
int calcularMinInscriptos(Comision vec[], int len);
float calcularPromedioInscriptos(Comision vec[], int len);

#endif