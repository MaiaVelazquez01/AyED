#include <iostream>
#include <stdio.h>
using namespace std;

// 1. Un algoritmo es la secuencia de pasos para resolver un problema. Un programa es la implementación de ese algoritmo en un lenguaje concreto que puede ser ejecutado por la computadora.
// 2. Procedimiento y función son subprogramas que nos permiten modularizar un problema. La diferencia entre ellos es que el procedimiento no retorna un valor, en cambio, una función sí.
// 3. Un registro es una estructura heterogenéa que agrupa distintos tipos de datos, se usan para guardar datos en la memoria mientras el programa está en ejecución. En cambio, un archivo refiere a un conjunto de datos almacenado de forma permanente.

// Ejercicio 1

    bool promociona(int nota1, int nota2, char apr) {
        if(nota1 >= 8 && nota2 >= 8 && apr == 'A') {
            return true;
        } else {
            return false;
        }
    }

// Ejercicio 2

    void cuatrimestre(int mes) {
        if (mes > 0 && mes <= 4) {
            cout << "Primer cuatrimestre" << endl;
        } else if(mes >= 5 && mes <= 8) {
            cout << "Segundo cuatrimestre" << endl;
        } else if(mes >= 9 && mes <= 12) {
            cout << "Tercer cuatrimestre" << endl;
        } else {
            cout << "Mes inválido" << endl;
        }
    }

// Ejercicio 3

    struct Laboratorio {
        int fecha;
        int dni;
        char nombreApellido[50];
        int nroOrden;
        int cantEstudios;
    };

    struct Deposito {
        int id;
        char tipo[10];
        char desc[100];
        int stock;
        float peso;
    };

// Ejercicio 4

    struct Corredor {
        int nro;
        int tiempoPrimeraEtapa;
        int tiempoSegundaEtapa;
    };

    float promedio(Corredor vec[], int len);
    int clasificacionDirecta(Corredor vec[], int len);
    int quedanEliminados(Corredor vec[], int len);

// Ejercicio 5

    struct Socio {
        int nro;
        char categoria;
        int antiguedad;
    };

int main() {

    // Ejercicio 3

    Laboratorio labo;
    cout << "Ingrese fecha del laboratorio: ";
    cin >> labo.fecha;
    cout << "Ingrese dni del paciente: ";
    cin >> labo.dni;
    cout << "Ingrese nombre y apellido del paciente: ";
    cin >> labo.nombreApellido;
    cout << "Ingrese nro de orden del laboratorio: ";
    cin >> labo.nroOrden;
    cout << "Ingrese cant de estudios del paciente: ";
    cin >> labo.cantEstudios;

    Deposito art;
    cout << "Ingrese ID del articulo: " << endl;
    cin >> art.id;
    cout << "Ingrese tipo del articulo: " << endl;
    cin >> art.tipo;
    cout << "Ingrese descripcion del articulo: " << endl;
    cin >> art.desc;
    cout << "Ingrese stock del articulo: " << endl;
    cin >> art.stock;
    cout << "Ingrese peso del articulo: " << endl;
    cin >> art.peso;

    // Ejercicio 4

    Corredor vec[100];
    int len;

    float prom = promedio(vec, len);
    int clasificaron = clasificacionDirecta(vec, len);
    int eliminados = quedanEliminados(vec, len);

    cout << "El promedio de tiempos de la segunda etapa es: " << prom << endl;
    cout << clasificaron << " corredores obtuvieron clasificacion directa" << endl;
    cout << eliminados << " corredores quedaron eliminados" << endl;

    // Ejercicio 5

    FILE *Soc;
    Socio s;

    int menorAntiguedad[100];
    int mayorAntiguedad[100];
    int posMen = 0;
    int posMay = 0;

    Soc = fopen("socios.dat", "rb");

    fread(&s, sizeof(struct Socio), 1, Soc);

    while(!feof(Soc)){
        if(s.antiguedad < 5) {
            menorAntiguedad[posMen] = s.nro;
            posMen++;
        } else {
            mayorAntiguedad[posMay] = s.nro;
            posMay++;
        }
        fread(&s, sizeof(struct Socio), 1, Soc);
    }

    fclose(Soc);

    cout << "La cantidad total de socios con antiguedad menor a 5 es: " << posMen << endl;

    return 0;
}

float promedio(Corredor vec[], int len) {
    float sumatoria = 0;
    for(int i = 0; i < len; i++) {
        sumatoria += vec[i].tiempoSegundaEtapa;
    }
    return sumatoria / len;
}

int clasificacionDirecta(Corredor vec[], int len) {
    int clasifican = 0;
    for(int i = 0; i < len; i++) {
        if(vec[i].tiempoPrimeraEtapa <= 60 && vec[i].tiempoSegundaEtapa <= 60) {
            clasifican++;
        }
    }
    return clasifican;
}

int quedanEliminados(Corredor vec[], int len) {
    int eliminados = 0;
    for(int i = 0; i < len; i++) {
        if(vec[i].tiempoPrimeraEtapa > 60 && vec[i].tiempoSegundaEtapa > 60) {
            eliminados++;
        }
    }
    return eliminados;
}