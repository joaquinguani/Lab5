#ifndef ICONTUSUARIO
#define ICONTUSUARIO
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include "TNotificacion.h"


class IContUsuario {
public:
    static ContUsuario* getInstanciaContUsu();

    //otros metodos
    virtual int getCantComen()=0;
    virtual void sumarComentario()=0;
    virtual int sizeCol()=0;
    virtual void imprimirUsuarios()=0; //casos: a,

    //funciones del MAPA Usuario
    Usuario* find(std::string);
    virtual bool estaUsuario(std::string)=0; 
    virtual void ingresarDatosVendedor(DataVendedor data)=0; //agrega un vendedor
    virtual void ingresarDatosCliente(DataCliente data)=0; //agrega un cliente 
    virtual Vendedor* findVend(std::string)=0;
    virtual bool esVaciaVendedor()=0;
    //funciones del MAPA Coment
    virtual Comentario* findComen(int ID)=0;

    
    virtual void imprimirVendedores()=0;
    virtual void imprimirClientes()=0;
    
    virtual std::map<std::string, Usuario *> getUsuarios()=0; // ESTO TE DEVUELVE UNA COPIA, SOLO SIRVE PARA VER SI HAY COSAS, NO PARA AGREGAR NI SACAR!!(soy el pelado jeje)
    virtual void listarVendedoresNoSubsXCliente(Cliente* cli)=0;
    virtual void listarVendSuscripto(Cliente* cli)=0;
    virtual std::map<std::string, Cliente*> getColClientes()=0;
    virtual std::map<std::string, Vendedor*> getColVendedores()=0;
    virtual Cliente* buscarClientePorNombre(std::string cli)=0;
    virtual Vendedor* buscarVendPorNombre(std::string vend)=0;
    virtual Usuario* buscarPorNombre(std::string)=0;
    virtual ~IContUsuario(){}; //destructor 
};

#endif