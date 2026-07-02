#include <iostream>
#include <stdio.h>
using namespace std;

// 1. Un registro es una estructura heterogenéa que agrupa distintos tipos de datos, se usan para guardar datos en la memoria mientras el programa está en ejecución. En cambio, un archivo refiere a un conjunto de datos almacenado de forma permanente.
// 2. Un algoritmo es la secuencia de pasos para resolver un problema. Un programa es la implementación de ese algoritmo en un lenguaje concreto que puede ser ejecutado por la computadora.
// 3. Parámetro por valor es cuando el subprograma recibe una copia del dato. Cualquier cambio que le haga en el subprograma, estoy modificando la copia del dato, no el dato en sí mismo. Parámetro por referencia es cuando el subprograma accede a la dirección de memoria de la variable original (usando el símbolo &), por lo que las modificaciones si afectan la variable original.

// Ejercicio 1

    bool esBisiesto(int anio) {
        if (anio % 4 == 0) {
            if (anio % 100 != 0) {
                return true;
            } else {
                if (anio % 400 == 0) {
                    return true;
                } else {
                    return false;
                }
            }
        } else {
            return false;
        }
    }

// Ejercicio 2

    void clasificacion(int p1, int p2, int p3) {
        if(p1 == p2 && p2 == p3) {
            cout << "Categoría A" << endl;
        } else if(p1 == p2 || p2 == p3 || p3 == p1) {
            cout << "Categoría B" << endl;
        } else {
            cout << "Categoría C" << endl;
        }
    }

// Ejericio 3

    struct Vehiculo {
        char patente[8];
        char marca[50];
        char modelo[50];
        int anioFabricacion;
    };

    struct Empleado {
        int legajo;
        char nombreApellido[50];
        char sector[30];
        int sueldoBasico;
        int antiguedad;
        char permanente;
    };

// Ejercicio 4

    struct Encuesta {
        int codParticipante;
        char ciudad[50];
        char respuesta;
    };

    int calcularCantidadTipoRespuesta(Encuesta vec[], int len, char tipoRespuesta);

// Ejercicio 5

    struct Aspirante {
        int dni;
        int puntaje;
        char resultado;
    };

    struct Aprobado {
        int dniA;
        int puntajeA;
    };

int main() {

    // Ejercicio 3

    Vehiculo automovil;
    cout << "Ingrese patente del automóvil: ";
    cin >> automovil.patente;
    cout << "Ingrese marca del automóvil: ";
    cin >> automovil.marca;
    cout << "Ingrese modelo del automóvil: ";
    cin >> automovil.modelo;
    cout << "Ingrese anio de fabricación del automóvil: ";
    cin >> automovil.anioFabricacion;

    Empleado emp;
    cout << "Ingrese legajo del empleado: ";
    cin >> emp.legajo;
    cout << "Ingrese nombre y apellido del empleado: ";
    cin >> emp.nombreApellido;
    cout << "Ingrese sector del empleado: ";
    cin >> emp.sector;
    cout << "Ingrese sueldo básico del empleado: ";
    cin >> emp.sueldoBasico;
    cout << "Ingrese antigüedad del empleado: ";
    cin >> emp.antiguedad;
    cout << "Ingrese si es de planta permanente (Y/N): ";
    cin >> emp.permanente;

    // Ejercicio 4
    
    Encuesta vec[2500];
    int len;

    int cantS = calcularCantidadTipoRespuesta(vec, len, 'S');
    int cantN = calcularCantidadTipoRespuesta(vec, len, 'N');
    int cantI = calcularCantidadTipoRespuesta(vec, len, 'I');

    if (cantS > cantN) {
        cout << "Resultado de la encuesta: gana el si" << endl;
    } else if (cantN > cantS) {
        cout << "Resultado de la encuesta: gana el no" << endl;
    } else {
        cout << "Resultado de la encuesta: empate" << endl;
    }

    cout << "La cantidad de respuesta si es: " << cantS << endl;
    cout << "La cantidad de respuesta no es: " << cantN << endl;
    cout << "La cantidad de respuesta indeciso es: " << cantI << endl;

    // Ejercicio 5

    FILE *Resultados, *Aprobados;
    Aspirante raux;
    Aprobado raux2;
    
    int totalDeAspirantes = 0;
    float sumatoria = 0;
    int cantRechazados = 0;

    Resultados = fopen("resultados.dat", "rb");
    Aprobados = fopen("aprobados.dat", "wb");

    fread(&raux, sizeof(struct Aspirante), 1, Resultados);

    while(!feof(Resultados)) {
        if(raux.resultado == 'A') {
            raux2.dniA = raux.dni;
            raux2.puntajeA = raux.puntaje;
            fwrite(&raux2, sizeof(struct Aprobado), 1, Aprobados);
        } else if(raux.resultado == 'R') {
            cantRechazados++;
        }
        
        sumatoria += raux.puntaje;
        totalDeAspirantes++;

        fread(&raux, sizeof(struct Aspirante), 1, Resultados);
    }

    fclose(Resultados);
    fclose(Aprobados);

    if(totalDeAspirantes == 0) {
        cout << "Error. No se puede obtener promedio." << endl;
    } else {
        float promedio = sumatoria / totalDeAspirantes;
        cout << "El promedio de los puntajes de todos los aspirantes es: " << promedio << endl;
    }
    cout << "La cantidad de aspirantes rechazados es: " << cantRechazados << endl;

    return 0;
}

int calcularCantidadTipoRespuesta(Encuesta vec[], int len, char tipoRespuesta) {
    int cant = 0;
    for(int i = 0; i < len; i++) {
        if(vec[i].respuesta == tipoRespuesta) {
            cant++;
        }
    }
    return cant;
}