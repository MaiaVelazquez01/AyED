#include <string>
using namespace std;

struct VelPais {
    string pais;
    int velMax;
    int velMin;
};

#ifndef funciones
#define funciones

int calcularMaxVelocidad (VelPais vec[], int len);
float calcularPromedio (VelPais vec[], int len);
int calcularMinVelocidad (VelPais vec[], int len);

#endif