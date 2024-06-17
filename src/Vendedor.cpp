#include <iostream> // Para std::cin y std::getline
#include "Vendedor.h"

Vendedor::Vendedor(std::string nickname ,std::string contrasena,TFecha fecha, std::string RUT): Usuario(nickname, contrasena, fecha){
    this->RUT = RUT;
}

Vendedor::Vendedor(DataVendedor data):Usuario(data.getNickname(), data.getContraseña(), data.getFecha()){
    this->RUT = data.getRut();
};

Usuario Vendedor::creadorUsuario(DataVendedor data){
    return Vendedor(data.getNickname(), data.getContraseña(),data.getFecha(),data.getRut());
};

void Cliente::imprimirUsuario(){
    std::string nombre = nickname;
    std::cout << nombre << std::endl;
    imprimirFecha();
    std::string RUT = rut;
    std::cout << RUT << std::endl;
}

bool esVendedor(){
    return true;
}