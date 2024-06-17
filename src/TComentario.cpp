#include "TComentario.h"

TComentario::TComentario(int id, std::string texto, TFecha* fecha){
    this->fecha = fecha;
    this->texto = texto;
    this->id = id;
};


std::string TComentario::getTexto(){
    return texto
};
Fecha TComentario::getFecha(){
    return *fecha
};

int TComentario::getID(){
    retunr id
};