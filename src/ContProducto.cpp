#include "ContProducto.h"
#include "Promocion.h"
#include "TFechaActual.h"
#include <cstdio>
#include <iostream>
#include <utility> // Para std::pair
#include <string>


ContProducto * ContProducto::instanciaContProd = NULL;

ContProducto::ContProducto(){
    codigoProducto = 0;
};

ContProducto* ContProducto::getInstanciaContProd() {
    if (instanciaContProd == nullptr) {
        instanciaContProd = new ContProducto();
    }
    return instanciaContProd;
};


std::map<int, Producto*> ContProducto::getColProductos() {
    return this->colProductos;
};

int ContProducto::getCodigoProducto(){
    return codigoProducto;
}

std::set<Compra*> ContProducto::getColCompra(){
    return colCompra;
};

void ContProducto::insertarProducto(Producto* prod){
    int codigoo = prod->getCodigo();
    colProductos[codigoo] = prod;
}


Promocion* ContProducto::findPromocion(std::string string){
    return colPromocion[string];
}

void ContProducto::agregarPromocion(Promocion* promo){
    std::string nombre = promo->getNombre();
    colPromocion[nombre] = promo;
}

std::set<Promocion*> ContProducto::listarPromosVigentes(){
    std::set<Promocion*> promosVigentes;
    TFechaActual* fecha;
    fecha = TFechaActual::getInstanciaFecha();
    //iterador que vaya por toda la coleccion de promociones
    std::map<std::string, Promocion *>::iterator it;
    for (it= colPromocion.begin(); it != colPromocion.end(); ++it){
        //va preguntando si la fechaVenc>TfechaActual, si es asi lo agrega a promos
        if (it->second->getFechaVenc()->mayoroIgual(fecha)){ //NO FUNCA PQ SON DE DISTINTO TIPO LAS FECHAS
            promosVigentes.insert(it->second);
            it->second->imprimirPromocion();
            //se podria imprimir aca o afuera recorriendo la lista
            //creo q es mas facil asi, la lista pierde sentido
         }
    };
};


void ContProducto::sumarCodigoProducto(){
    ++codigoProducto;
}


Promocion* ContProducto::buscarPromoPorNombre(std::string promo){ //aca decia Usuario*, puse Vendedor*
    return colPromocion[promo];
};

void ContProducto::listarProductos()  {
    for (auto pair : colProductos) {
        printf("Código: %d, Producto: %s\n", pair.first, pair.second->getNombre());
    }
    std::map<int, Producto *>::iterator it;
    for (it= colProductos.begin(); it != colProductos.end(); ++it){
            printf("Código: %d, Producto: %s\n", it->first, it->second->getNombre());
        }
};

// void ContProducto::listarProductosDisp() {
//     for ( auto pair : colProductos ) {
//         if (pair.second->getStock() > 0) {
//             printf("Código: %d, Producto: %s\n", pair.first, pair.second->getNombre());
//         }
//     }
// }; //ESTA DOS VECES PERO FUNCIONAN DISTINTO


Producto* ContProducto::buscarProducto(int clave){
    std::map<int, Producto*>::iterator it = colProductos.find(clave);
    Producto* p = it->second;
};


/*Producto* ContProducto::buscarProdPorNombre(std::string produ){     //v-creo que esta no sirve
    return colProductos[produ];
}*/


void ContProducto::listarProductosDisp(Vendedor* vendedor) {
    for ( auto pair : colProductos) {
        if (pair.second->getStock() > 0 && pair.second->getVendAsociado() == vendedor) {
            printf("Código: %d, Producto: %s\n", pair.first, pair.second->getNombre());
        }
    }
};

bool ContProducto::estaProd(int codigoProd){
    return colProductos[codigoProd] !=NULL;
};

Producto* ContProducto::find(int codigo){
    return colProductos[codigo];
};

void ContProducto::imprimirComprasConProdPendiente(Producto* prod){
    std::map<int, CompraProd*>::iterator it;
    std::map<int, CompraProd*> comProd = prod->getCompraProd(); //obtengo el mapa de compraprod
    for(it=comProd.begin(); it != comProd.end(); ++it){
        if(!it->second->getEnviado()){
            std::string nickCli = it->second->getCompraAsociada()->getClienteAsociado()->getNickname(); //obtengo el nick del cliente asociado a la compra asociada al compraProd
            int id = it->second->getCompraAsociada()->getId();     
            TFechaActual* fecha = it->second->getCompraAsociada()->getFechaCompra();
            std::cout << "(";
            std::cout << nickCli << "," << id << ","; 
            fecha->imprimirFecha();
            std::cout << ")";
        }
    }
};

void ContProducto::listarProductosDisp(){
    for (auto it = this->colProductos.begin(); it != this->colProductos.end(); it++) {
        if (it->second->getStock() > 0){
            it->second->imprimirProducto();
        }
    } 
};


// std::set<Promocion*> ContProducto::listarPromosVigentes(){  YA ESTA ARRIBA
//     std::set<Promocion*> promosVigentes;
//     TFechaActual* fecha;
//     fecha = TFechaActual::getInstanciaFecha();
//     //iterador que vaya por toda la coleccion de promociones
//     std::map<std::string, Promocion *>::iterator it;
//     for (it= colPromocion.begin(); it != colPromocion.end(); ++it){
//         //va preguntando si la fechaVenc>TfechaActual, si es asi lo agrega a promos
//         if (it->second->getFechaVenc()->mayoroIgual(fecha)){
//             promosVigentes.insert(it->second);
//             it->second->imprimirPromocion();
//             //se podria imprimir aca o afuera recorriendo la lista
//             //creo q es mas facil asi, la lista pierde sentido
//          }
//     };
// };

