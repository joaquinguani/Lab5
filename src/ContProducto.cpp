#include "ContProducto.h"
#include "Promocion.h"
#include "TFechaActual.h"
#include <cstdio>
#include <iostream>


ContProducto::ContProducto(){

};


std::map<int, Producto*> ContProducto::getProductos() {
    return Productos;}

std::set<Promocion*> ContProducto::listarPromosVigentes(){
    std::set<Promocion*> promos;
    TFechaActual* fecha;
    fecha = TFechaActual::getInstanciaFecha();
    //iterador que vaya por toda la coleccion de promociones
    std::map<std::string, Promocion *>::iterator it;
    for (it= colPromocion.begin(); it != colPromocion.end(); ++it){
        //va preguntando si la fechaVenc>TfechaActual, si es asi lo agrega a promos
        if (it->second->getFechaVenc().mayoroIgual(fecha)){
            promos.insert(it->second);
         }
               
    }
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

void ContProducto::listarProductosDisp(Vendedor* vendedor) {
    for ( auto pair : colProducto) {
        if (pair.second->getStock() > 0 && pair.second->getVendAsociado() == vendedor) {
            printf("Código: %d, Producto: %s\n", pair.first, pair.second->getNombre());
        }
    }
};
