#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "TFechaActual.h" 


TFechaActual* TFechaActual::instanciaFecha = NULL; 

/*//creador sin parametros
TFechaActual::TFechaActual(){
};*/

TFechaActual::TFechaActual(int dia, int mes, int anio){
    this->Dia=dia;
    this->Mes=mes;
    this->Anio=anio;
};

TFechaActual* TFechaActual::getInstanciaFecha(int dia, int mes, int anio) {
    if (instanciaFecha == nullptr) {
        instanciaFecha = new TFechaActual(dia, mes, anio);
    }
    return instanciaFecha;
}

int TFechaActual::getDia() {
    return this->Dia;
};

int TFechaActual::getMes() {
    return this->Mes;
};

int TFechaActual::getAnio() {
    return this->Anio;
};


void TFechaActual::modificarFecha(int dia, int mes, int anio) {
    if (dia > 0 && dia <= 31 && mes > 0 && mes <= 12 && anio > 0) {
        this->Dia = dia;
        this->Mes = mes;
        this->Anio = anio;
        std::cout << "Fecha modificada a: " << dia << "/" << mes << "/" << anio << std::endl;
    } else {
        std::cerr << "Fecha no válida." << std::endl; //cerr es para imprimir errores 
    }

};

void TFechaActual::imprimirFecha(){
    int dia = getDia();
    printf("%d",dia);
    int mes = getMes();
    printf("%d",mes);
    int anio =getAnio();
    printf("%d",anio);
};

