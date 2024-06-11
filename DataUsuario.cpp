#include <iostream> // Para std::cin y std::getline
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <set>
#include "DataUsuario.h"


DataUsuario::DataUsuario(std::string nickname, std::string contraseña, TFecha fecha): fecha(fecha){
    this->nickname = nickname;
    this->contraseña = contraseña;
};

std::string DataUsuario::getNickname() {
    return this->nickname;
};

std::string DataUsuario::getContraseña() {
    return this->contraseña;
};

TFecha DataUsuario::getFecha() {
    return this->fecha;
};