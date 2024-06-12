#include <iostream> // Para std::cin y std::getline
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <set>
#include "DataUsuario.h"


DataUsuario::DataUsuario(std::string nickname, std::string contrasena, TFecha fecha): fecha(fecha){
    this->nickname = nickname;
    this->contraseña = contrasena;
};

std::string DataUsuario::getNickname() {
    return this->nickname;
};

std::string DataUsuario::getContrasena() {
    return this->contraseña;
};

TFecha DataUsuario::getFecha() {
    return this->fecha;
};
