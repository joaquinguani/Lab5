#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "TFecha.h" 


TFecha::TFecha(int Dia, int Mes, int Anio){
    this->Dia=Dia;
    this->Mes=Mes;
    this->Anio=Anio;
};

int TFecha::getDia() {
    return this->Dia;
};

int TFecha::getMes() {
    return this->Mes;
};

int TFecha::getAnio() {
    return this->Anio;
};