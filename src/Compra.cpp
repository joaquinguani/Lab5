#include <iostream>
#include "Compra.h"
#include "TFecha.h"


Compra::Compra(TFecha f, int monto){
    this->fecha = f;
    this->MontoFinal = monto;
};

TFecha Compra::getFecha(){
    return this->fecha;
};

int Compra::getMontoFinal(){
    return this->MontoFinal;
};

void Compra::setFecha(const TFecha& f){
    this->fecha = f;
};

void Compra::setMontoFinal(int monto){
    this->MontoFinal = monto;
};

//void Compra::agregarProdACompra(Producto prod, int cod, int cant){}; creo que no hay que usar nunca

int Compra::aplicarDescuento(int precio, int cant){
    int precioNuevo;
    
    return precioNuevo;
};

void Compra::sumarAlMonto(int pre){
    this->MontoFinal += pre;
};
