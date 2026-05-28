#include <iostream>
#include <string>
#include "funciones.hpp"
using namespace std;

int main() {
    Estudiante vec[20] = {{1744729, "Maia", 7}, {1744993, "Pepe", 4}, {1744329, "Lucrecia", 9}};
    int len = 3;
    int n = 20;
    int opcion;

    mostrarMenu();
    cin >> opcion;

    while(opcion != 0) {
        cout << endl;
        switch (opcion)
        {
        case 1:
            buscarEImprimirAlumno(vec, len);
            break;
        case 2:
            modificarNota(vec, len);
            break;
        case 3:
            promedioDeNotas(vec, len);
            break;
        case 4:
            buscarEstudianteConMejorNota(vec, len);
            break;
        case 5:
            buscarEstudianteConMenorNota(vec, len);
            break;
        }

        mostrarMenu();
		cin >> opcion;
    }

    return 0;
}