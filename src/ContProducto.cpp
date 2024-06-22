#include "ContProducto.h"
#include "Promocion.h"
#include "TFechaActual.h"
#include <cstdio>
#include <iostream>
#include <utility> // Para std::pair
#include <string>


ContProducto::ContProducto(){
    codigoProducto = 0;
};


std::map<int, Producto*> ContProducto::getColProductos() {
    return this->colProductos;
};


std::set<Compra*> ContProducto::getColCompra(){
    return colCompra;
};

void ContProducto::insertarProducto(Producto* prod){
    int codigoo = prod->getCodigo();
    colProductos[codigoo] = prod;
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
            it->second->imprimirPromocion();
            //se podria imprimir aca o afuera recorriendo la lista
            //creo q es mas facil asi, la lista pierde sentido
         }
    };
};

int ContProducto::getCodigoProducto(){
    return codigoProducto;
}

void ContProducto::sumarCodigoProducto(){
    ++codigoProducto;
}

ContProducto* ContProducto::getInstanciaContProd() {
    if (instanciaContProd == nullptr) {
        instanciaContProd = new ContProducto();
    }
    return instanciaContProd;
};


Promocion* ContProducto::buscarPromoPorNombre(std::string promo){ //aca decia Usuario*, puse Vendedor*
    return colPromocion[promo];
};

void ContProducto::listarProductos()  {
    for (auto pair : colProductos) {
        printf("Código: %d, Producto: %s\n", pair.first, pair.second->getNombre());
    }
};

void ContProducto::listarProductosDisp() {
    for ( auto pair : colProductos ) {
        if (pair.second->getStock() > 0) {
            printf("Código: %d, Producto: %s\n", pair.first, pair.second->getNombre());
        }
    }
};


Producto* ContProducto::buscarProducto(int clave){
    std::map<int, Producto*>::iterator it = colProductos.find(clave);
    Producto* p = it->second;
};


/*Producto* ContProducto::buscarProdPorNombre(std::string produ){     //v-creo que esta no sirve
    return colProductos[produ];
}*/


void ContProducto::listarProductosDisp(Vendedor* vendedor) {
    for ( auto pair : colProducto) {
        if (pair.second->getStock() > 0 && pair.second->getVendAsociado() == vendedor) {
            printf("Código: %d, Producto: %s\n", pair.first, pair.second->getNombre());
        }
    }
};

bool ContProducto::estaProd(int codigoProd){
    return Productos[codigoProd] !=NULL;
};

Producto* ContProducto::find(int codigo){
    return Productos[codigo]
};

void ContProducto::imprimirComprasConProdPendiente(Producto* prod){
    std::map<int, CompraProd*>::iterator it;
    std::map<int, CompraProd*> comProd = prod->getCompraProd();
    for(it=comProd.begin(); it != comProd.end(); ++it){
        if(!it->second->getEnviado()){
            std::string nickCli = it->second->getCompraAsociada()->getClienteAsociado()->getNickname();
            int id = it->second->getCompraAsociada()->getId();     
            TFecha* fecha = it->second->getCompraAsociada()->getFecha();
            std::cout << "(";
            std::cout << nickCli << "," << id << ","; 
            fecha->imprimirFecha();
            std::cout << ")";
        }
    }
};

void ContProducto::listarProductosDisp(){
    for (auto it = this->Productos.begin(); it != this->Productos.end(); it++) {
        if (it->second->getStock() > 0){
            it->second->imprimirProducto();
        }
    } 
};

