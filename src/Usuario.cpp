#include <iostream> // Para std::cin y std::getline
#include "Usuario.h"

Usuario::~Usuario(){}

Usuario::Usuario(std::string nickname ,std::string contrasena,TFecha fecha): fecha(fecha){
    this->nickname = nickname;
    this->contrasena = contrasena;
    //this->fecha(fecha.getDia(),fecha.getMes(),fecha.getAnio());//no se como asignarle a fecha su fecah
};

void Usuario::agregarComen(Comentario* coment){
    int id = coment->getID();
    comentarios[id] = coment;
}

void Usuario::imprimirFecha(){
    int dia = fecha.getDia();
    int mes = fecha.getMes();
    int ano = fecha.getAnio();
    printf("\n| Fecha:\n|          %d/%d/%d\n|",dia,mes,ano);
}


std::string Usuario::getNickname(){
    return this->nickname;
};




void Usuario::imprimirUsuario(){};



bool esVendedor(){
    return false;
};



