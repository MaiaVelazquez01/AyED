#include <iostream>
#include <stdio.h>
using namespace std;

struct Venta
{
    int nro_venta;
    int cod_vend;
    int importe;
};

int main()
{
    // // Creo el archivo ventas.dat
    // FILE *Ven;
    // Venta rcarga;
    // int i = 0;
    // int len = 4;
    // Ven = fopen("ventas.dat", "wb");
    // cout << "Ingrese nro de venta (0 para finalizar): ";
    // cin >> rcarga.nro_venta;
    // while (rcarga.nro_venta != 0 && i < len) {
    //     cout << "Ingrese codigo de vendedor: ";
    //     cin >> rcarga.cod_vend;
    //     cout << "Ingrese importe: ";
    //     cin >> rcarga.importe;
    //     fwrite(&rcarga, sizeof(struct Venta), 1, Ven);
    //     i++;
    //     if (i < len) {
    //         cout << "Ingrese nro de venta (0 para finalizar): ";
    //         cin >> rcarga.nro_venta;
    //     }
    // }
    // fclose(Ven);

    FILE *Altas, *Bajas, *Ventas;
    Venta ven;

    Ventas = fopen("ventas.dat", "rb");
    Altas = fopen("ventas_altas.dat", "wb");
    Bajas = fopen("ventas_bajas.dat", "wb");

    fread(&ven, sizeof(struct Venta), 1, Ventas);

    while(!feof(Ventas)) {
        if(ven.importe > 100000) {
            fwrite(&ven, sizeof(struct Venta), 1, Altas);
        } else {
            fwrite(&ven, sizeof(struct Venta), 1, Bajas);
        }
        fread(&ven, sizeof(struct Venta), 1, Ventas);
    }

    fclose(Ventas);
    fclose(Altas);
    fclose(Bajas);

    //Abro los archivos en modo lectura

    Altas = fopen("ventas_altas.dat", "rb");
    Bajas = fopen("ventas_bajas.dat", "rb");

    cout << "Ventas con importe superior a $100000:" << endl;

    fread(&ven, sizeof(struct Venta), 1, Altas);
    
    while(!feof(Altas)) {
        cout << "Nro venta: " << ven.nro_venta << endl;
        cout << "Cod de vendedor: " << ven.cod_vend << endl;
        cout << "Importe: " << ven.importe << endl;
        fread(&ven, sizeof(struct Venta), 1, Altas);
    }

    fclose(Altas);

    cout << "Ventas con importe menor o igual a $100000:" << endl;

    fread(&ven, sizeof(struct Venta), 1, Bajas);
    
    while(!feof(Bajas)) {
        cout << "Nro venta: " << ven.nro_venta << endl;
        cout << "Cod de vendedor: " << ven.cod_vend << endl;
        cout << "Importe: " << ven.importe << endl;
        fread(&ven, sizeof(struct Venta), 1, Bajas);
    }

    fclose(Bajas);

    return 0;
}