#include <iostream>
#include <string>
#include "funciones.hpp"
using namespace std;

int calcularMaxVelocidad (VelPais vec[], int len) {
    int vMax = -100;
    int pos = 0;

    for (int i = 0; i < len; i++) {
        if (vec[i].velMax > vMax) {
            vMax = vec[i].velMax;
            pos = i;
        }
    }
    
    return pos;
}

float calcularPromedio (VelPais vec[], int len) {
    float sumaVelocidades = 0;

    for (int i = 0; i < len; i++) {
        sumaVelocidades += vec[i].velMax;
    }

    return sumaVelocidades / len;
}

int calcularMinVelocidad (VelPais vec[], int len) {
    int vMin = 99999;
    int pos = 0;

    for (int i = 0; i < len; i++) {
        if (vec[i].velMin < vMin) {
            vMin = vec[i].velMin;
            pos = i;
        }
    }

    return pos;
}