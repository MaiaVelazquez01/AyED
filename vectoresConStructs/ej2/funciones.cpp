#include <iostream>
#include <string>
#include "funciones.hpp"
using namespace std;

int calcularMaxInscriptos(Comision vec[], int len) {
    int cantMaxInsc = 0;
    int pos = 0;

    for (int i = 0; i < len; i++) {
        if (vec[i].cantInscriptos > cantMaxInsc) {
            cantMaxInsc = vec[i].cantInscriptos;
            pos = i;
        }
    }
    
    return pos;
}

int calcularMinInscriptos(Comision vec[], int len) {
    int cantMinInsc = 99999;
    int pos = 0;

    for (int i = 0; i < len; i++) {
        if (vec[i].cantInscriptos < cantMinInsc) {
            cantMinInsc = vec[i].cantInscriptos;
            pos = i;
        }
    }

    return pos;
}

float calcularPromedioInscriptos(Comision vec[], int len) {
    float sumaInscriptos = 0;

    for (int i = 0; i < len; i++) {
        sumaInscriptos += vec[i].cantInscriptos;
    }

    return sumaInscriptos / len;
}