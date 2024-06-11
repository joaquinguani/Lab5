#include <iostream> // Para std::cin y std::getline
#include "TComentario.h"

TComentario::TComentario(int id, std::string texto, TFecha* fecha){
    this->fecha = fecha;
    this->texto = texto;
    this->id = id;
};


//faltan getesr