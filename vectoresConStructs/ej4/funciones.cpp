#include <iostream>
#include <string>
#include "funciones.hpp"
using namespace std;

void mostrarMenu() {
    cout << "-------- MENU --------" << endl;
    cout << "Ingrese opcion:" << endl;
	cout << "1: para Buscar alumno por su nombre" << endl;
	cout << "2: para Modificar nota de alumno por su nombre" << endl;
    cout << "3: para Mostrar el promedio de todas las notas" << endl;
	cout << "4: para Mostrar estudiante con la mejor nota" << endl;
	cout << "5: para Mostrar estudiante con la menor nota " << endl;
    cout << "0: para Salir" << endl;
    cout << endl;
}

int buscar(Estudiante vec[], int len, string nombre) {
    int pos;

    for(int i = 0; i < len; i++) {
        if(vec[i].nombre == nombre) {
            pos = i;
            return pos;
        }
    }

    return -1;
}

void buscarEImprimirAlumno(Estudiante vec[], int len) {
    int pos;
    string alumno;

    cout << "Ingrese nombre del alumno: ";
    cin >> alumno;

    pos = buscar(vec, len, alumno);

    if(pos == -1) {
        cout << "No se encontro alumno con ese nombre" << endl;
        cout << endl;
    } else {
        cout << "Nombre: " << vec[pos].nombre << endl;
        cout << "Legajo: " << vec[pos].legajo << endl;
        cout << "Nota: " << vec[pos].nota << endl;
        cout << endl;
    }
}

void modificarNota(Estudiante vec[], int len) {
    int pos;
    string alumno;
    
    cout << "Ingrese nombre del alumno: ";
    cin >> alumno;

    pos = buscar(vec, len, alumno);

    if(pos == -1) {
        cout << "No se encontro alumno con ese nombre" << endl;
        cout << endl;
    } else {
        cout << "Ingrese nueva nota: ";
        cin >> vec[pos].nota;
        cout << endl;
    }
}

void promedioDeNotas(Estudiante vec[], int len) {
    float sumaDeNotas = 0;

    for(int i = 0; i < len; i++) {
        sumaDeNotas += vec[i].nota;
    }

    cout << "Promedio de todas las notas: " << sumaDeNotas / len << endl;
    cout << endl;
}

int buscarMejorNota(Estudiante vec[], int len){
    int pos;
    int max = -9999;

    for(int i = 0; i < len; i++) {
        if(vec[i].nota > max) {
            pos = i;
        }
    }

    return pos;
}

void buscarEstudianteConMejorNota(Estudiante vec[], int len) {
    int pos;
    pos = buscarMejorNota(vec, len);
    cout << "Estudiante con mejor nota" << endl;
    cout << "Nombre: " << vec[pos].nombre << endl;
    cout << "Legajo: " << vec[pos].legajo << endl;
    cout << "Nota: " << vec[pos].nota << endl;
    cout << endl;
}

int buscarMenorNota(Estudiante vec[], int len){
    int pos;
    int min = 9999;

    for(int i = 0; i < len; i++) {
        if(vec[i].nota < min) {
            min = vec[i].nota;
            pos = i;
        }
    }

    return pos;
}

void buscarEstudianteConMenorNota(Estudiante vec[], int len) {
    int pos;
    pos = buscarMenorNota(vec, len);
    cout << "Estudiante con menor nota" << endl;
    cout << "Nombre: " << vec[pos].nombre << endl;
    cout << "Legajo: " << vec[pos].legajo << endl;
    cout << "Nota: " << vec[pos].nota << endl;
    cout << endl;
}