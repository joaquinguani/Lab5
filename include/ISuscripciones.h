#ifndef ISUSCRIPCIONES
#define ISUSCRIPCIONES
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include "Cliente.h"
#include "TNotificacion.h"


class ISuscripciones{
    public: 
        // virtual void notificar(TNotificacion);
        ISuscripciones();
        virtual ~ISuscripciones(){};
        virtual void agregarSuscriptor(Cliente* cliente);
};

#endif