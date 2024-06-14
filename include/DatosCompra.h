#ifndef DATOSCOMPRA
#define DATOSCOMPRA
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include "Producto.h"

class DatosCompra{
private:
    int precio;
    TFecha fecha;
    std::set<Producto> productos;
public:
    DatosCompra(int, TFecha, std::set<Producto>);
    int getPrecio();
    TFecha getFecha();
    std::set<Producto> getProductos;
};  

#endif