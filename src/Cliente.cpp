#include <iostream> // Para std::cin y std::getline
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <set>
#include "Cliente.h"


Cliente::~Cliente(){

}

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
    return this->direccion;
};
/*
void Cliente::setDireccion():direccion(direccion){

};
*/

void Cliente::imprimirUsuario(){
    printf("\n_______________\n| ");
    std::string nombre = getNickname();
    std::cout << nombre << std::endl;
    printf("|\n|");
    imprimirFecha();
    printf("\n| Direccion:\n|    Ciudad: ");
    imprimirDireccion();
    printf("\n|___________\n\n");
};

void Cliente::imprimirDireccion(){
    std::string ciudadd = ciudad;
    std::cout << ciudadd << std::endl;
    printf("|    Calle:  ");
    std::string calle = direccion.getCalle();
    std::cout << calle << std::endl;
    printf("|    Numero: ");
    int numero = direccion.getNumero();
    printf("%d",numero);
}


// bool esVendedor(){
//     return false;
// };
