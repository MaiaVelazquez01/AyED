#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

struct Empleado {
    int legajo;
    int codemp;
    float sueldo;
};

float calcularPromedio(float sueldos, int cantEmpleados);

int main() {
    // // Creo el archivo empleados.dat
    // FILE *Emp;
    // Empleado rcarga;
    // int len = 7;
    // int i = 0;
    // Emp = fopen("empleados.dat", "wb");
    // cout << "Ingrese el legajo del alumno (0 para finalizar): ";
    // cin >> rcarga.legajo;
    // while (rcarga.legajo != 0 && i < len)
    // {
    //     cout << "Ingrese codigo del empleado: ";
    //     cin >> rcarga.codemp;
    //     cout << "Ingrese sueldo del empleado: ";
    //     cin >> rcarga.sueldo;
    //     fwrite(&rcarga, sizeof(Empleado), 1, Emp);
    //     i++;
    //     if (i < len) {
    //         cout << "Ingrese el legajo del empleado (0 para finalizar): ";
    //         cin >> rcarga.legajo;
    //     }
    // }
    // fclose(Emp);

    FILE *Emps;
    Empleado raux;
    int cantEmpleados = 0;
    float sumatoria = 0;
    int cantEmpleadosConSueldoSuperior = 0;

    Emps = fopen("empleados.dat", "rb");

    fread(&raux, sizeof(struct Empleado), 1, Emps);
    while(!feof(Emps)) {

        sumatoria += raux.sueldo;

        if(raux.sueldo > 1500000.00) {
            cantEmpleadosConSueldoSuperior++;
        }

        cantEmpleados++;
        fread(&raux, sizeof(struct Empleado), 1, Emps);
    }

    fclose(Emps);

    cout << fixed << setprecision(2);
    cout << "Cantidad total de empleados: " << cantEmpleados << endl;
    cout << "Sueldo promedio: " << calcularPromedio(sumatoria, cantEmpleados) << endl;
    cout << "Cantidad de empleados con sueldo superior a $1.500.000: " << cantEmpleadosConSueldoSuperior << endl;

    return 0;
}

float calcularPromedio(float sueldos, int cantEmpleados) {
    return sueldos / cantEmpleados;
}