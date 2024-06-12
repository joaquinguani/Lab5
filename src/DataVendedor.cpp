#include <iostream> // Para std::cin y std::getline
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <set>
#include "DataVendedor.h"


DataVendedor::DataVendedor(std::string nickname, std::string contraseña, TFecha fecha, std::string RUT): DataUsuario(nickname, contraseña, fecha){
    this->RUT = RUT;
};

std::string DataVendedor::getRut() {
    return this->RUT;
};

//HOLAAA