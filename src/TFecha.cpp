#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "TFecha.h" 


TFecha::TFecha(int Dia, int Mes, int Ano){
    this->Dia=Dia;
    this->Mes=Mes;
    this->Ano=Ano;
};

int TFecha::getDia() {
    return this->Dia;
};

int TFecha::getMes() {
    return this->Mes;
};

int TFecha::getAno() {
    return this->Ano;
};