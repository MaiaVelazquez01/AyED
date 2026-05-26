#include <iostream>
#include <string>
#include "funciones.hpp"
using namespace std;

int main () {
    Comision vec[50] = {{"Algebra", 3000}, {"Analisis 1", 150}, {"AyED", 70}, {"Discreta", 200}};
    int n = 50;
    int len = 4;

    int posMax = calcularMaxInscriptos(vec, len);
    int posMin = calcularMinInscriptos(vec, len);
    float promedio = calcularPromedioInscriptos(vec, len);

    cout << "-------- EJERCICIO 2 --------" << endl;
    cout << "a - La materia que mas incriptos tuvo fue " << vec[posMax].nombreMateria << endl;
    cout << "b - La materia que menos inscriptos tuvo fue " << vec[posMin].nombreMateria << endl;
    cout << "c - El promedio de inscriptos en todas las materias fue " << promedio << endl;
    cout << endl;

    return 0;
}