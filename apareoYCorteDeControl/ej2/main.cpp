#include <iostream>
#include <stdio.h>
using namespace std;

struct Producto {
    int codigo;
    int stock;
};

int main() {

    // Creo los archivos con los datos
    // FILE *Este, *Oeste;
    // Producto rcarga;
    // cout << "--------- este.dat ---------" << endl;
    // Este = fopen("este.dat", "wb");
    // cout << "Ingrese codigo del producto o 0 para terminar:" << endl;
    // cin >> rcarga.codigo;
    // while (rcarga.codigo != 0) {
    //     cout << "Ingrese stock:" << endl;
    //     cin >> rcarga.stock;
    //     fwrite(&rcarga, sizeof(struct Producto), 1, Este);
    //     cout << "Ingrese codigo del producto o 0 para terminar" << endl;
    //     cin >> rcarga.codigo;
    // }
    // fclose(Este);
    // cout << "--------- oeste.dat ---------" << endl;
    // Oeste = fopen("oeste.dat", "wb");
    // cout << "Ingrese codigo del producto o 0 para terminar:" << endl;
    // cin >> rcarga.codigo;
    // while (rcarga.codigo != 0) {
    //     cout << "Ingrese stock:" << endl;
    //     cin >> rcarga.stock;
    //     fwrite(&rcarga, sizeof(struct Producto), 1, Oeste);
    //     cout << "Ingrese codigo del producto o 0 para terminar" << endl;
    //     cin >> rcarga.codigo;
    // }
    // fclose(Oeste);

    // Verifico la informacion guardada en el archivo
    // FILE *Este, *Oeste;
    // Producto raux;
    // cout << "--------- este.dat ---------" << endl;
    // Este = fopen("este.dat", "rb");
    // fread(&raux, sizeof(struct Producto), 1, Este);
    // while(!feof(Este)) {
    //     cout << "Codigo: " << raux.codigo << " - Stock: " << raux.stock << endl;
    //     fread(&raux, sizeof(struct Producto), 1, Este);
    // }
    // fclose(Este);
    // cout << "--------- oeste.dat ---------" << endl;
    // Oeste = fopen("oeste.dat", "rb");
    // fread(&raux, sizeof(struct Producto), 1, Oeste);
    // while(!feof(Oeste)) {
    //     cout << "Codigo: " << raux.codigo << " - Stock: " << raux.stock << endl;
    //     fread(&raux, sizeof(struct Producto), 1, Oeste);
    // }
    // fclose(Oeste);

    FILE *Prods, *Este, *Oeste;
    Producto prodE, prodO;

    Este = fopen("este.dat", "rb");
    Oeste = fopen("oeste.dat", "rb");
    Prods = fopen("productos.dat", "wb");

    fread(&prodE, sizeof(struct Producto), 1, Este);
    fread(&prodO, sizeof(struct Producto), 1, Oeste);

    while(!feof(Este) && !feof(Oeste)) {
        if(prodE.codigo < prodO.codigo) {
            fwrite(&prodE, sizeof(struct Producto), 1, Prods);
            fread(&prodE, sizeof(struct Producto), 1, Este);
        } else {
            fwrite(&prodO, sizeof(struct Producto), 1, Prods);
            fread(&prodO, sizeof(struct Producto), 1, Oeste);
        }
    }

    while(!feof(Este)) {
        fwrite(&prodE, sizeof(struct Producto), 1, Prods);
        fread(&prodE, sizeof(struct Producto), 1, Este);
    }

    while(!feof(Oeste)) {
        fwrite(&prodO, sizeof(struct Producto), 1, Prods);
        fread(&prodO, sizeof(struct Producto), 1, Oeste);
    }

    fclose(Este);
    fclose(Oeste);
    fclose(Prods);

    Prods = fopen("productos.dat", "rb");
    Producto raux;

    fread(&raux, sizeof(struct Producto), 1, Prods);
    while(!feof(Prods)) {
        cout << "Codigo: " << raux.codigo << " - Stock: " << raux.stock << endl;
        fread(&raux, sizeof(struct Producto), 1, Prods);  
    }

    fclose(Prods);
    return 0;
}