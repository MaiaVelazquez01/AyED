#include <iostream>
#include <stdio.h>
using namespace std;

struct Articulo {
    int codigo;
    char tipo;
    int stock;
};

void mostrarVector(int vec[], int len);

int main() {
    // // Creo el archivo articulos.dat
    // FILE *Arts;
    // Articulo rcarga;
    // int i = 0;
    // int len = 6;
    // Arts = fopen("articulos.dat", "wb");
    // cout << "Ingrese codigo del articulo (0 para finalizar): ";
    // cin >> rcarga.codigo;
    // while(rcarga.codigo != 0 && i < len) {
    //     cout << "Ingrese tipo del articulo: ";
    //     cin >> rcarga.tipo;
    //     cout << "Ingrese stock del articulo: ";
    //     cin >> rcarga.stock;
    //     fwrite(&rcarga, sizeof(struct Articulo), 1, Arts);
    //     i++;
    //     if(i < len) {
    //         cout << "Ingrese codigo del articulo (0 para finalizar): ";
    //         cin >> rcarga.codigo;
    //     }
    // }    
    // fclose(Arts);

// articulos.dat
// codigo: 111111, tipo: A, stock: 5
// codigo: 222222, tipo: B, stock: 70
// codigo: 333333, tipo: C, stock: 30
// codigo: 444444, tipo: B, stock: 20
// codigo: 555555, tipo: A, stock: 88
// codigo: 666666, tipo: C, stock: 14

    FILE *Arts;
    Articulo raux;

    int artsMenorA20[100];
    int artsMayorA20[100];
    int posMenor = 0;
    int posMayor = 0;

    Arts = fopen("articulos.dat", "rb");

    fread(&raux, sizeof(struct Articulo), 1, Arts);

    while(!feof(Arts)) {
        if(raux.stock < 20) {
            artsMenorA20[posMenor] = raux.codigo;
            posMenor++;
        } else {
            artsMayorA20[posMayor] = raux.codigo;
            posMayor++;
        }
        fread(&raux, sizeof(struct Articulo), 1, Arts);
    }

    fclose(Arts);

    cout << "El codigo de los articulos cuyo stock es menor a 20:" << endl;
    mostrarVector(artsMenorA20, posMenor);
    cout << "El codigo de los articulos cuyo stock es mayor o igual a 20:" << endl;
    mostrarVector(artsMayorA20, posMayor);
    cout << "La cantidad total de articulos con stock menor a 20 es: " << posMenor << endl;

    return 0;
}

void mostrarVector(int vec[], int len) {
    for(int i = 0; i < len; i++) {
        cout << vec[i] << endl;
    }
}