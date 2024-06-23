
/*#ifndef FABRICA_H
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
//------------------------------------------------------------------------//
*/
//version 2.0:
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
#include "ContUsuario.h"
#include "ContProducto.h"

class Fabrica {
private:
    static Fabrica* instancia;
    IContUsuario* contUsuario;
    IContProducto* contProducto;
    Fabrica();
public:
    static Fabrica* getInstancia();
    IContUsuario* getIContUsuario();
    IContProducto* getIContProducto();

    ~Fabrica();
};

#endif
