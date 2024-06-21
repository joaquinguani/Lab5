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
    int ID = NuevoComen->getID();
    this->respuestas[ID] = NuevoComen;
}


void Comentario::setUsuario(Usuario* usu){
    this->usuario = usu;
}

void Comentario::setProdPadre(Producto* prod){
    ProdPadre = prod;
}

Comentario* Comentario::getComPadre(){
    return ComenPadre;
}

std::string Comentario::getTexto(){
    return texto;
};
TFecha Comentario::getFecha(){
    return fecha;
};

int Comentario::getID(){
    return ID;
};

void Comentario::eliminarRefCom(int ID){
    respuestas.erase(ID);
}

Producto* Comentario::getProducto(){
    return ProdPadre;
}

void Comentario::imprimirComentario(){
    std::string nickk = usuario->getNickname();
    int dia = fecha.getDia();
    int mes = fecha.getMes();
    int anio = fecha.getAnio();
    
    printf("ID: %d        %d/%d/%d \n",ID,dia,mes,anio);
    std::cout << nickk << std::endl;
    std::cout << texto << std::endl;
}

void Comentario::imprimirComenYHijos(){
    imprimirComentario();
    std::map<int, Comentario *>::iterator it;
    for (it= respuestas.begin(); it != respuestas.end(); ++it){
        Comentario* comen = it->second;
        comen->imprimirComenYHijos();
    }
}

bool Comentario::getTieneComPadre(){
    return tieneComPadre
}