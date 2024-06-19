/*#ifndef DATOSPRODUCTO
#define DATOSPRODUCTO
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include "TCategoria.h"

class DatosProducto{
private:
    int precio;
    int stock;
    std::string descripcion;
    TCategoria categoria;
    std::string nicknameVend;
public:
    DatosProducto(int, int, std::string, TCategoria, std::string);
    int getPrecio();
    int getStock();
    std::string getDescripcion();
    TCategoria getCategoria();
    std::string getNicknameVend();
};  

#endif*/