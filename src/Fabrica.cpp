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
#include "ContProductos.h"



IContUsuario* Fabrica::getIContUsuario() {
    return ContUsuario.getInstancia();
};

IContProducto* Fabrica::getIContProducto() {
    return ContProductos.getInstancia(); //??????? es lo que dice el teorico pero aparece mal!!!!
;}
