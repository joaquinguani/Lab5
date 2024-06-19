#include <iostream> // Para std::cin y std::getline
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <set>
#include "Cliente.h"


Cliente::Cliente(std::string nickname, std::string contrasena , TFecha fecha, TDireccion direccion,std::string ciudad):Usuario(nickname, contrasena, fecha), direccion(direccion){
    this->ciudad = ciudad;
};

Cliente::Cliente(DataCliente data):Usuario(data.getNickname(), data.getContrasena(), data.getFecha()), direccion(data.getDireccion()){
    this->ciudad = data.getCiudad();
};

std::string Cliente::getCiudad() {
    return this->ciudad;
};

TDireccion Cliente::getDireccion() {
    return this->direc;
};

void Cliente::setDireccion(TDireccion &direccion){ //estaba mal el &
    this->direc = direccion; // es direc no direccion
};

Usuario Cliente::creadorUsuario(DataCliente data){
    return Cliente(data.getNickname(), data.getContrasena(),data.getFecha(),data.getDireccion(),data.getCiudad());
};


void Cliente::imprimirUsuario(){
    std::string nombre = nickname;
    std::cout << nombre << std::endl;
    imprimirFecha();
    imprimirDireccion();
}

void Cliente::imprimirDireccion(){
    std::string calle = direccion.getCalle();
    std::cout << nombre << std::endl;
    int numero = direccion.getNumero();
    printf("%d",numero);
    std::string ciudadd = ciudad;
    std::cout << ciudadd << std::endl;
}

bool esVendedor(){
    return false;
};