#include <iostream>
#include <stdio.h>
using namespace std;

// 1. Un registro es una estructura hetrogénea que puede aguapar distintos tipos de datos. Se accede a los campos del registro mediante el operador punto (.). Mientras que un vector es una estructura homogénea que almacena datos del mismo tipo en posiciones consecutivas de memoria. Se accede a cada elemento del vector mediante un índice.
// 2. Procedimiento y función son subprogramas que nos permiten modularizar un problema. La diferencia entre ellos es que el procedimiento no retorna un valor, en cambio, una función sí.
// 3. Parámetro por valor es cuando el subprograma recibe una copia del dato. Cualquier cambio que le haga en el subprograma, estoy modificando la copia del dato, no el dato en sí mismo. Parámetro por referencia es cuando el subprograma accede a la dirección de memoria de la variable original (usando el símbolo &), por lo que las modificaciones si afectan la variable original.

// Ejercicio 1

    bool esMundialista(int anio) {
        if(anio % 2 == 0 && anio % 4 != 0) {
            return true;
        } else {
            return false;
        }
    }

// Ejercicio 2

    void distancia(float kms) {
        float promedio = kms / 3;
        cout << "La distancia recorrida es: " << promedio << endl;
    }

// Ejercicio 3

    struct Biblioteca {
        int codigoLibro;
        char titulo[50];
        char autor[30];
        int ejemplares;
    };

    struct Empleado {
        int legajo;
        char nombreApellido[80];
        char sector[30];
        int sueldo;
    };

// Ejercicio 4

    struct Vehiculo {
        int codigo;
        int kmRecorridos;
    };

    int mayor(Vehiculo vec[], int len);
    int menor(Vehiculo vec[], int len);
    float promedio(Vehiculo vec[], int len);

// Ejercicio 5

    struct Articulo {
        int cod;
        char categoria;
        int precio;
    };

    struct Hogar {
        int codH;
        int precioH;
    };

int main()
{
    // Ejercicio 3

    Biblioteca libro;
    cout << "Ingrese codigo del libro: ";
    cin >> libro.codigoLibro;
    cout << "Ingrese titulo del libro: ";
    cin >> libro.titulo;
    cout << "Ingrese autor del libro: ";
    cin >> libro.autor;
    cout << "Ingrese ejemplares del libro: ";
    cin >> libro.ejemplares;

    Empleado emp;
    cout << "Ingrese legajo del empleado: ";
    cin >> emp.legajo;
    cout << "Ingrese nombre y apellido del empleado: ";
    cin >> emp.nombreApellido;
    cout << "Ingrese sector del empleado: ";
    cin >> emp.sector;
    cout << "Ingrese sueldo del empleado: ";
    cin >> emp.sueldo;

    // Ejercicio 4

    Vehiculo vec[500];
    int len;

    int posMay = mayor(vec, len);
    int posMen = menor(vec, len);
    float promedioKms = 0;

    cout << "El vehiculo con mayor cantidad de kilometros: " << vec[posMay].codigo << " con " << vec[posMay].kmRecorridos << endl;
    cout << "El vehiculo con menor cantidad de kilometros: " << vec[posMen].codigo << " con " << vec[posMen].kmRecorridos << endl;
    if(len == 0) {
        cout << "Error. No se puede obtener promedio." << endl;
    } else {
        promedioKms = promedio(vec, len);
        cout << "El promedio es " << promedio << endl;
    }

    // Ejercicio 5

    FILE *Arts, *Elec, *Hog;
    Articulo raux;
    Hogar raux2;

    Elec = fopen("electronicos.dat", "wb");
    Hog = fopen("hogar.dat", "wb");
    Arts = fopen("articulos.dat", "rb");

    fread(&raux, sizeof(struct Articulo), 1, Arts);
    
    while(!feof(Arts)) {
        if(raux.categoria == 'E') {
            fwrite(&raux, sizeof(struct Articulo), 1, Elec);
        } else {
            raux2.codH = raux.cod;
            raux2.precioH = raux.precio;
            fwrite(&raux2, sizeof(struct Hogar), 1, Hog);
        }
        fread(&raux, sizeof(struct Articulo), 1, Arts);
    }

    fclose(Elec);
    fclose(Hog);
    fclose(Arts);

    return 0;
}

int mayor(Vehiculo vec[], int len) {
    int may = -1000;
    for(int i = 0; i < len; i++) {
        if(vec[i].kmRecorridos > may) {
            may = i;
        }
    }
    return may;
}

int menor(Vehiculo vec[], int len) {
    int men = 1000;
    for(int i = 0; i < len; i++) {
        if(vec[i].kmRecorridos < men) {
            men = i;
        }
    }
    return men;
}

float promedio(Vehiculo vec[], int len) {
    float prom = 0;
    int sumatoria = 0;
    for(int i = 0; i < len; i++) {
        sumatoria =+ vec[i].kmRecorridos;
    }
    prom = sumatoria / len;
    return prom;
}