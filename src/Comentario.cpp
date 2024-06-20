#include "Comentario.h"
#include "TFechaActual.h"
#include "TFecha.h"
#include "ContUsuario.h"



Comentario::Comentario(std::string txt){
    texto = txt;
    TFechaActual* fechaAct = TFechaActual::getInstanciaFecha();
    int dia = fechaAct->getDia();
    int mes = fechaAct->getMes();
    int anio = fechaAct->getAnio();
    TFecha* fechaDef = new TFecha(dia,mes,anio);
    fecha = *fechaDef;
    ContUsuario* contUsuari = ContUsuario::getInstanciaContUsu();
    contUsuari->sumarComentario();
    ID =  contUsuari->getCantComen();
    tieneComPadre = false;
}

void Comentario::CrearHijo(std::string txt,Usuario* usu){
    Comentario* NuevoComen = new Comentario(txt);
    NuevoComen->tieneComPadre = true;
    NuevoComen->ComenPadre = this;
    NuevoComen->usuario = usu;
    usu->agregarComen(NuevoComen);
    NuevoComen->ProdPadre = ProdPadre;
}


std::string Comentario::getTexto(){
    return texto
};
TFecha Comentario::getFecha(){
    return fecha
};

int Comentario::getID(){
    return ID;
};