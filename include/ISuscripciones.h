#ifndef ISUSCRIPCIONES
#define ISUSCRIPCIONES
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>

#include "TNotificacion.h"


class ISuscripciones{
    public: virtual  void notificar(TNotificacion)=0;
            ISuscripciones();
            virtual ~ISuscripciones(){};
};

#endif