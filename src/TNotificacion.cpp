#include "TNotificacion.h"
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include "Producto.h"

TNotificacion::TNotificacion(std::string nickVend, std::string nomPromocion,  std::set<Producto> prodNoti){ //que ondis 

};

std::string TNotificacion::getNickVend(){
    return this->nickVend;
}

std::string TNotificacion::getNomPromocion(){
    return this->nomPromocion;
};

std::set<Producto> TNotificacion::getProductos(){
    return this->prodNoti;
};