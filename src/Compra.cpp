#include <iostream>
#include "Compra.h"
#include "TFecha.h"


Compra::Compra(TFecha f, int monto){
    this->fecha = f;
    this->MontoFinal = monto;
};

//getters
TFecha* Compra::getFecha(){
    return this->fecha;
};

int Compra::getMontoFinal(){
    return this->MontoFinal;
};

std::map<std::string,Producto*> Compra::getProductos(){
    return this->productos;
}

std::set<CompraProd*> Compra::getCompraProducto(){
    return this->compraProducto;
}

Cliente* Compra::getClienteAsociado(){
    return clienteAsociado;
}

//setters
void Compra::setFecha(const TFecha& f){
    this->fecha = f;
};

void Compra::setMontoFinal(int monto){
    this->MontoFinal = monto;
};

//void Compra::agregarProdACompra(Producto prod, int cod, int cant){}; creo que no hay que usar nunca

int Compra::aplicarDescuento(int precio, int cant, int codProd, Producto* prod){
    int precioNuevo = precio;
    Promocion* promo = prod->getPromo();
    if (promo != NULL) {
        //SI CANT ES MAYOR O IGUAL A CANT MINIMA 
            int desc = promo->getDescuento();
            precioNuevo = (desc*precio)/100;
    }
    return precioNuevo;
};

void Compra::sumarAlMonto(int pre){
    this->MontoFinal += pre;
};


