#include <iostream> // Para std::cin y std::getline
#include "Usuario.h"

Usuario::Usuario(std::string nickname ,std::string contrasena,TFecha fecha): fecha(fecha){
    this->nickname = nickname;
    this->nickname = nickname;
    //this->fecha(fecha.getDia(),fecha.getMes(),fecha.getAnio());//no se como asignarle a fecha su fecah
};