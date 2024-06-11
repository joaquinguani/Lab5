#include <iostream> // Para std::cin y std::getline
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <set>
#include "Cliente.h"


Cliente::Cliente(std::string nickname, std::string contraseña , TFecha fecha, TDireccion direccion,std::string ciudad):Usuario(nickname, contraseña, fecha), direccion(direccion){
    this->ciudad = ciudad;
};

Cliente::Cliente(DataCliente data):Usuario(data.getNickname(), data.getContraseña(), data.getFecha()), direccion(data.getDireccion()){
    this->ciudad = data.getCiudad();
};

std::string Cliente::getCiudad() {
    return this->ciudad;
};

TDireccion Cliente::getDireccion() {
    return this->direccion;
};

void Cliente::setDireccion(TDireccion& direccion){
    this->direccion = direccion;
};

Usuario Cliente::creadorUsuario(DataCliente data){
    return Cliente(data.getNickname(), data.getContraseña(),data.getFecha(),data.getDireccion(),data.getCiudad());
};