#include <iostream>
#include <stdio.h>
using namespace std;

struct Producto {
    int codigo;
    int uVendidas;
};

int main() {

    // Creo los archivos con los datos
    // FILE *PrimerT, *SegundoT, *TercerT;
    // Producto rcarga;
    // cout << "--------- 1erTrimestre.dat ---------" << endl;
    // PrimerT = fopen("1erTrimestre.dat", "wb");
    // cout << "Ingrese codigo del producto o 0 para terminar:" << endl;
    // cin >> rcarga.codigo;
    // while (rcarga.codigo != 0) {
    //     cout << "Ingrese unidades vendidas:" << endl;
    //     cin >> rcarga.uVendidas;
    //     fwrite(&rcarga, sizeof(struct Producto), 1, PrimerT);
    //     cout << "Ingrese codigo del producto o 0 para terminar:" << endl;
    //     cin >> rcarga.codigo;
    // }
    // fclose(PrimerT);
    // cout << "--------- 2doTrimestre.dat ---------" << endl;
    // SegundoT = fopen("2doTrimestre.dat", "wb");
    // cout << "Ingrese codigo del producto o 0 para terminar:" << endl;
    // cin >> rcarga.codigo;
    // while (rcarga.codigo != 0) {
    //     cout << "Ingrese unidades vendidas:" << endl;
    //     cin >> rcarga.uVendidas;
    //     fwrite(&rcarga, sizeof(struct Producto), 1, SegundoT);
    //     cout << "Ingrese codigo del producto o 0 para terminar:" << endl;
    //     cin >> rcarga.codigo;
    // }
    // fclose(SegundoT);
    // cout << "--------- 3erTrimestre.dat ---------" << endl;
    // TercerT = fopen("3erTrimestre.dat", "wb");
    // cout << "Ingrese codigo del producto o 0 para terminar:" << endl;
    // cin >> rcarga.codigo;
    // while (rcarga.codigo != 0) {
    //     cout << "Ingrese unidades vendidas:" << endl;
    //     cin >> rcarga.uVendidas;
    //     fwrite(&rcarga, sizeof(struct Producto), 1, TercerT);
    //     cout << "Ingrese codigo del producto o 0 para terminar:" << endl;
    //     cin >> rcarga.codigo;
    // }
    // fclose(TercerT);

    // Verifico la informacion guardada en cada archivo
    // FILE *PrimerT, *SegundoT, *TercerT;
    // Producto raux;
    // cout << "--------- 1erTrimestre.dat ---------" << endl;
    // PrimerT = fopen("1erTrimestre.dat", "rb");
    // fread(&raux, sizeof(struct Producto), 1, PrimerT);
    // while(!feof(PrimerT)) {
    //     cout << "Codigo: " << raux.codigo << " - Unidades vendidas: " << raux.uVendidas << endl;
    //     fread(&raux, sizeof(struct Producto), 1, PrimerT);
    // }
    // fclose(PrimerT);
    // cout << "--------- 2doTrimestre.dat ---------" << endl;
    // SegundoT = fopen("2doTrimestre.dat", "rb");
    // fread(&raux, sizeof(struct Producto), 1, SegundoT);
    // while(!feof(SegundoT)) {
    //     cout << "Codigo: " << raux.codigo << " - Unidades vendidas: " << raux.uVendidas << endl;
    //     fread(&raux, sizeof(struct Producto), 1, SegundoT);
    // }
    // fclose(SegundoT);
    // cout << "--------- 3erTrimestre.dat ---------" << endl;
    // TercerT = fopen("3erTrimestre.dat", "rb");
    // fread(&raux, sizeof(struct Producto), 1, TercerT);
    // while(!feof(TercerT)) {
    //     cout << "Codigo: " << raux.codigo << " - Unidades vendidas: " << raux.uVendidas << endl;
    //     fread(&raux, sizeof(struct Producto), 1, TercerT);
    // }
    // fclose(TercerT);

    FILE *PrimerT, *SegundoT, *TercerT, *Inter, *Anual;
    Producto prodP, prodS, prodI, prodT;

    PrimerT = fopen("1erTrimestre.dat", "rb");
    SegundoT = fopen("2doTrimestre.dat", "rb");
    Inter = fopen("intermedio.dat", "wb");

    fread(&prodP, sizeof(struct Producto), 1, PrimerT);
    fread(&prodS, sizeof(struct Producto), 1, SegundoT);

    while(!feof(PrimerT) && !feof(SegundoT)) {
        if(prodP.codigo < prodS.codigo) {
            fwrite(&prodP, sizeof(struct Producto), 1, Inter);
            fread(&prodP, sizeof(struct Producto), 1, PrimerT);
        } else {
            fwrite(&prodS, sizeof(struct Producto), 1, Inter);
            fread(&prodS, sizeof(struct Producto), 1, SegundoT);
        }
    }

    while(!feof(PrimerT)) {
        fwrite(&prodP, sizeof(struct Producto), 1, Inter);
        fread(&prodP, sizeof(struct Producto), 1, PrimerT);
    }

    while(!feof(SegundoT)) {
        fwrite(&prodS, sizeof(struct Producto), 1, Inter);
        fread(&prodS, sizeof(struct Producto), 1, SegundoT);
    }

    fclose(PrimerT);
    fclose(SegundoT);
    fclose(Inter);

    TercerT = fopen("3erTrimestre.dat", "rb");
    Inter = fopen("intermedio.dat", "rb");
    Anual = fopen("2018.dat", "wb");

    fread(&prodT, sizeof(struct Producto), 1, TercerT);
    fread(&prodI, sizeof(struct Producto), 1, Inter);

    while(!feof(TercerT) && !feof(Inter)) {
        if(prodT.codigo < prodI.codigo) {
            fwrite(&prodT, sizeof(struct Producto), 1, Anual);
            fread(&prodT, sizeof(struct Producto), 1, TercerT);
        } else {
            fwrite(&prodI, sizeof(struct Producto), 1, Anual);
            fread(&prodI, sizeof(struct Producto), 1, Inter);
        }
    }

    while(!feof(TercerT)) {
        fwrite(&prodT, sizeof(struct Producto), 1, Anual);
        fread(&prodT, sizeof(struct Producto), 1, TercerT);
    }

    while(!feof(Inter)) {
        fwrite(&prodI, sizeof(struct Producto), 1, Anual);
        fread(&prodI, sizeof(struct Producto), 1, Inter);
    }

    fclose(Inter);
    fclose(TercerT);
    fclose(Anual);

    // Verifico la informacion guardada en el archivo
    cout << "--------- 2018.dat ---------" << endl;
    Producto raux;
    Anual = fopen("2018.dat", "rb");
    fread(&raux, sizeof(struct Producto), 1, Anual);
    while(!feof(Anual)) {
        cout << "Codigo: " << raux.codigo << " - Unidades vendidas: " << raux.uVendidas << endl;
        fread(&raux, sizeof(struct Producto), 1, Anual);
    }
    fclose(Anual);

    return 0;
}