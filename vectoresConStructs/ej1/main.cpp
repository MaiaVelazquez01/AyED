#include <iostream>
#include <string>
#include "funciones.hpp"
using namespace std;

int main () {
    VelPais vec[150] = {{"Argentina", 180, 50}, {"Chile", 220, 60}, {"Uruguay, 100, 40"}};
    int n = 150;
    int len = 3;

    int posMax = calcularMaxVelocidad(vec, len);
    float promedioVelocidades = calcularPromedio(vec, len);
    int posMin = calcularMinVelocidad(vec, len);

    cout << "-------- EJERCICIO 1 --------" << endl;
    cout << "a - El pais que tiene la velocidad maxima mas alta es " << vec[posMax].pais << " con " << vec[posMax].velMax << " Km/h" << endl;
    cout << "b - El promedio de velocidades maximas es de " << promedioVelocidades << endl;
    cout << "c - El pais que tiene la velocidad minima mas baja es " << vec[posMin].pais << " con " << vec[posMin].velMin << " Km/h" << endl;
    cout << endl;

    return 0;
}