#include <iostream>
#include <string>
#include "funciones.hpp"
using namespace std;

int main()
{
    Producto vec[10] = {{1, "Coca", 1500.50, 100}, {2, "Alfajor", 100.25, 200}, {3, "Figuritas", 2000, 1000}};
    int n = 10;
    int len = 3;
    int opcion;

    mostrarMenu();
    cin >> opcion;

    while(opcion != 0) {
        cout << endl;
        switch (opcion)
        {
        case 1:
            darAltaNuevoProducto(vec, n, len);
            break;
        case 2:
            buscarEImprimirProducto(vec, len);
            break;
        case 3:
            modificarProducto(vec, len);
            break;
        }

        mostrarMenu();
		cin >> opcion;
    }

    return 0;
}