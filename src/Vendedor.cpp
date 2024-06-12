#include <iostream> // Para std::cin y std::getline
#include "Vendedor.h"

Vendedor::Vendedor(std::string nickname ,std::string contrasena,TFecha fecha, std::string RUT): Usuario(nickname, contrasena, fecha){
    this->RUT = RUT;
}

Vendedor::Vendedor(DataVendedor data):Usuario(data.getNickname(), data.getContrasena(), data.getFecha()){
    this->RUT = data.getRut();
};

Usuario Vendedor::creadorUsuario(DataVendedor data){
    return Vendedor(data.getNickname(), data.getContrasena(),data.getFecha(),data.getRut());
};