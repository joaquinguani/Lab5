#include <iostream> // Para std::cin y std::getline
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <set>
#include "Fabrica.h"
#include "ContUsuario.h"
#include "ContProducto.h"

 
 Fabrica::Fabrica(){
    //contUsuario* contUsu = new ContUsuario();
    //contProducto* = new ContProducto();
}


Fabrica* Fabrica::getInstancia() {
    if (instancia == nullptr) {
        instancia = new Fabrica();
    }
    return instancia;
}

IContUsuario* Fabrica::getIContUsuario() {
    return ContUsuario::getInstanciaContUsu();
};

IContProducto* Fabrica::getIContProducto() {
    return ContProducto::getInstanciaContProd(); 
;}


Fabrica::~Fabrica() {
    delete contUsuario;
    delete contProducto;
}