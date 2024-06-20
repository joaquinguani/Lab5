#include "Comentario.h"
#include "TFechaActual.h"
#include "TFecha.h"



Comentario::Comentario(std::string txt){
    texto = txt;
    TFechaActual* fechaAct = TFechaActual::getInstanciaFecha();
    int dia = fechaAct->getDia();
    int mes = fechaAct->getMes();
    int anio = fechaAct->getAnio();
    TFecha* fechaDef = new TFecha(dia,mes,anio);
    fecha = *fechaDef;
    
}


std::string Comentario::getTexto(){
    return texto
};
Fecha Comentario::getFecha(){
    return *fecha
};

int Comentario::getID(){
    retunr id
};