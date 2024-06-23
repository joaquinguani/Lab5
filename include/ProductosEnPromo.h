#ifndef PRODUCTOSENPROMO
#define PRODUCTOSENPROMO
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "Producto.h"

class ProductosEnPromo{
private:
    int cantidadMin;
    Producto* producto;
public:
    //constructor
    ProductosEnPromo(Producto* prod, int cantMin); // y esto?

    //metodos de acceso
    int getCantidadMin();

    //destructor
    virtual ~ProductosEnPromo(){};
    
};

#endif