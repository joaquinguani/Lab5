#include "ContProducto.h"
#include "Promocion.h"
#include "TFechaActual.h"
#include <cstdio>
#include <iostream>
#include <utility> // Para std::pair
#include <string>


ContProducto::ContProducto(){

};


std::map<int, Producto*> ContProducto::getProductos() {
    return Productos;}

std::set<Compra*> ContProducto::getColCompra(){
    return colCompra;
}


std::set<Promocion*> ContProducto::listarPromosVigentes(){
    std::set<Promocion*> promosVigentes;
    TFechaActual* fecha;
    fecha = TFechaActual::getInstanciaFecha();
    //iterador que vaya por toda la coleccion de promociones
    std::map<std::string, Promocion *>::iterator it;
    for (it= colPromocion.begin(); it != colPromocion.end(); ++it){
        //va preguntando si la fechaVenc>TfechaActual, si es asi lo agrega a promos
        if (it->second->getFechaVenc().mayoroIgual(fecha)){
            promosVigentes.insert(it->second);
         }
    };
    promosVigentes.imprimirPromocion();
};


Promocion* ContProducto::buscarPromoPorNombre(std::string promo){ //aca decia Usuario*, puse Vendedor*
    return colPromocion[promo];
};

void ContProducto::listarProductos()  {
    for (auto pair : colProducto) {
        printf("Código: %d, Producto: %s\n", pair.first, pair.second->getNombre());
    }};

void ContProducto::listarProductosDisp() {
    for ( auto pair : colProducto ) {
        if (pair.second->getStock() > 0) {
            printf("Código: %d, Producto: %s\n", pair.first, pair.second->getNombre());
        }
    }
}


Producto* ContProducto::buscarProducto(int clave){
    std::map<int, Producto*>::iterator it = Productos.find(clave);
    Producto* p = it->second;
};


Producto* ContProducto::buscarProdPorNombre(std::string produ){
    return colProductos[produ];
}

void ContProducto::listarProductosDisp(Vendedor* vendedor) {
    for ( auto pair : colProducto) {
        if (pair.second->getStock() > 0 && pair.second->getVendAsociado() == vendedor) {
            printf("Código: %d, Producto: %s\n", pair.first, pair.second->getNombre());
        }
    }
};


void ContProducto::imprimirComprasConProdPendiente(std::string prod){
    std::set<Compra*>::iterator it;
    std::set<Compra*> compras = this->getColCompra();
    for (it=compras.begin(); it != compras.end(); ++it){
        auto iterProd = (*it)->getProductos().find(prod); 
        if(iterProd != (*it)->getProductos().end()){ //si tiene al producto
            if(!iterProd->second->getCompraProducto()->getEnviado()){ //si no fue enviado
                std::string nickCli = (*it)->getClienteAsociado()->getNickname();
                TFecha* fecha = (*it)->getFecha();
                std::pair<std::string, TFecha*> par;
                par.first = nickCli;
                par.second = fecha;
                std::cout << "(";
                std::cout << par.first << ","; 
                par.second->imprimirFecha();
                std::cout << ")";
            }
        }else{}
    }
}
