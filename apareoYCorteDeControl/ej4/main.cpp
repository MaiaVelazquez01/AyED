#include <iostream>
#include <stdio.h>
using namespace std;

struct Combo {
    int codigo;
    int mesVenta;
    int uVendidas;
};

int main() {

    // Creo el archivo con los datos
    // FILE *Local;
    // Combo rcarga;
    // Local = fopen("BurgerFast.dat", "wb");
    // cout << "Ingrese codigo de combo o 0 para terminar:" << endl;
    // cin >> rcarga.codigo;
    // while(rcarga.codigo != 0) {
    //     cout << "Ingrese mes de venta:" << endl;
    //     cin >> rcarga.mesVenta;
    //     cout << "Ingrese unidades vendidas para ese mes:" << endl;
    //     cin >> rcarga.uVendidas;
    //     fwrite(&rcarga, sizeof(struct Combo), 1, Local);
    //     cout << "Ingrese codigo de combo o 0 para terminar:" << endl;
    //     cin >> rcarga.codigo;
    // }
    // fclose(Local);

    // Verifico la informacion guardada en el archivo
    // FILE *Local;
    // Combo raux;
    // Local = fopen("BurgerFast.dat", "rb");
    // fread(&raux, sizeof(struct Combo), 1, Local);
    // while(!feof(Local)) {
    //     cout << "Codigo de combo: " << raux.codigo << " - Mes de venta: " << raux.mesVenta << " - Unidades vendidas para ese mes: " << raux.uVendidas << endl;
    //     fread(&raux, sizeof(struct Combo), 1, Local);
    // }
    // fclose(Local);

    FILE *Local;
    Local = fopen("BurgerFast.dat", "rb");

    Combo raux;
    int ant;
    int sumaUVendidas;

    fread(&raux, sizeof(struct Combo), 1, Local);
    while(!feof(Local)) {
        ant = raux.codigo;
        sumaUVendidas = 0;

        while(!feof(Local) && ant == raux.codigo) {
            sumaUVendidas = sumaUVendidas + raux.uVendidas;
            fread(&raux, sizeof(struct Combo), 1, Local);
        }

        cout << "El total de unidades vendidas para el combo " << raux.codigo << " es de " << sumaUVendidas << endl;
    }

    fclose(Local);
    return 0;
}