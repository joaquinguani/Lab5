#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "TFecha.h" 

TFecha* TFecha::instanciaFecha = NULL;

TFecha::TFecha(int Dia, int Mes, int Ano){
    this->Dia=Dia;
    this->Mes=Mes;
    this->Ano=Ano;
};

TFecha::~TFecha(){}

TFecha * TFecha::getInstanciaFecha(int Dia, int Mes, int Anio){
    if (instanciaFecha == NULL)
        instanciaFecha = new TFecha(Dia , Mes, Anio);
    return instanciaFecha;
}

int TFecha::getDia() {
    return this->Dia;
};

int TFecha::getMes() {
    return this->Mes;
};

int TFecha::getAno() {
    return this->Ano;
};


void TFecha::modificarFecha(int dia, int mes, int anio) {
    if (dia > 0 && dia <= 31 && mes > 0 && mes <= 12 && anio > 0) {
        this->Dia = dia;
        this->Mes = mes;
        this->Anio = anio;
        std::cout << "Fecha modificada a: " << dia << "/" << mes << "/" << anio << std::endl;
    } else {
        std::cerr << "Fecha no válida." << std::endl; //cerr es para imprimir errores 
    }

};

void TFecha::imprimirFecha(){
    int dia = getDia();
    printf("%d",dia);
    int mes = getMes();
    printf("%d",mes);
    int ano =getAnio();
    printf("%d",ano);
};

