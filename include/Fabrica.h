
#ifndef FABRICA_H
#define FABRICA_H
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "IContUsuario.h"
#include "IContProducto.h"

class Fabrica {
public:
    // Constructor y Destructor
    Fabrica();
    ~Fabrica();

    IContUsuario* getIContUsuario();
    IContProducto* getIContProducto();
};

#endif 