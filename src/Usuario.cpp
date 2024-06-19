#include <iostream> // Para std::cin y std::getline
#include "Usuario.h"

Usuario::Usuario(std::string nickname ,std::string contrasena,TFecha fecha): fecha(fecha){
    this->nickname = nickname;
    this->contrasena = contrasena;
    //this->fecha(fecha.getDia(),fecha.getMes(),fecha.getAnio());//no se como asignarle a fecha su fecah
};

void Usuario::imprimirFecha(){
    int dia = *fecha.getDia();
    printf("%d",dia);
    int mes = *fecha.getMes();
    printf("%d",mes);
    int ano = *fecha.getAno();
    printf("%d",Ano);
};

bool esVendedor(){
    return false;
};