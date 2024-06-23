#ifndef ISUSCRIPCIONES
#define ISUSCRIPCIONES
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include "Cliente.h"
#include "TNotificacion.h"
#include "Vendedor.h"

class ISuscripciones{
    public: 
        //CLIENTE
        virtual void agregarNotificacion(TNotificacion*)=0;
        virtual void consultarNotificaciones()=0;
        virtual void agregarSuscripcion(Vendedor*)=0;
        virtual void eliminarSuscripcion(Vendedor*)=0;
        //VENDEDOR
        virtual void notificarClientes(TNotificacion*)=0;
        virtual void agregarSuscriptor(Cliente*)=0;
        virtual void eliminarSuscriptor(Cliente*)=0;
        // CREADOR Y DESTRUCTOR
        ISuscripciones();
        virtual ~ISuscripciones(){};
};

#endif