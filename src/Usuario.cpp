#include <iostream> // Para std::cin y std::getline
#include "Usuario.h"

Usuario::~Usuario(){}

Usuario::Usuario(std::string nickname ,std::string contrasena,TFecha fecha): fecha(fecha){
    this->nickname = nickname;
    this->nickname = nickname;
    //this->fecha(fecha.getDia(),fecha.getMes(),fecha.getAnio());//no se como asignarle a fecha su fecah
};

void Usuario::imprimirFecha(){
    int dia = fecha.getDia();
    int mes = fecha.getMes();
    int ano = fecha.getAno();
    printf("\n| Fecha:\n|          %d/%d/%d\n|",dia,mes,ano);
}

void Usuario::imprimirUsuario(){};

std::string Usuario::getNickname(){
    return this->nickname;
};

/*
bool esVendedor(){
    return false;
};
*/