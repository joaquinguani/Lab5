#include <iostream>
#include "Compra.h"
#include "TFecha.h"


Compra::Compra(TFechaActual* f, int monto, int id){
    this->fecha = f;
    this->MontoFinal = monto;
    this->id= id;
};

//getters
TFechaActual* Compra::getFechaCompra(){
    return this->fecha;
};

float Compra::getMontoFinal(){
    return this->MontoFinal;
};

std::map<int,Producto*> Compra::getProductos(){
    return this->productos;
};

std::map<int, CompraProd*> Compra::getCompraProducto(){
    return this->compraProducto;
};

Cliente* Compra::getClienteAsociado(){
    return clienteAsociado;
};

int Compra::getId(){
    return id;
}

//setters
/*void Compra::setFecha(const TFechaActual& f){
    this->fecha = f;
};*/

void Compra::setMontoFinal(int monto){
    this->MontoFinal = monto;
};

//void Compra::agregarProdACompra(Producto prod, int cod, int cant){}; creo que no hay que usar nunca

int Compra::aplicarDescuento(int precio, int cant, int codProd, Producto* prod){
    int precioNuevo = precio;
    Promocion* promo = prod->getPromo();
    std::map<int, ProductosEnPromo*> prodsProm = promo->getPromProductos();
    if (promo != NULL && prodsProm[codProd]->getCantidadMin() >= cant) { 
        int desc = promo->getDescuento();
        precioNuevo = (desc*precio)/100;
    }
    return precioNuevo;
};

void Compra::sumarAlMonto(int pre){
    this->MontoFinal += pre;
};

void Compra::asociarCompraProd(CompraProd* cp, int cod){
    this->compraProducto[cod] = cp;
};

void Compra::imprimirCompraCompleto(){
    printf("/nResumen Compra:/n");
    TFechaActual* fecha = this->fecha;
    fecha->imprimirFecha();
    int monto = this->MontoFinal;
    printf("/nMonto Final: $%d/n", monto);
    printf("/nDetalle productos:/n");
    for (auto it = this->productos.begin(); it != this->productos.end(); it++) {
        it->second->imprimirProducto(); 
        int codP = it->second->getCodigo();
        std::map<int, CompraProd*> compraPro = it->second->getCompraProd();
        compraPro[codP]->imprimirCompraProd();
    }
};

void Compra::asociarCliente(Cliente* cli){
    clienteAsociado=cli;
}