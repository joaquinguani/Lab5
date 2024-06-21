#ifndef TNOTIFICACION
#define TNOTIFICACION
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
//#include <sstream>
#include "Producto.h"

class TNotificacion {
private:
    std::string nickVend;
    std::string nomProm;
    std::set<Producto> productos;
public:
    //constructor
    TNotificacion(std::string, std::string,  std::set<Producto>);

    //getters
    std::string getNickVend();
    std::string getNomProm();
    std::set<Producto> getProductos();
};


#endif