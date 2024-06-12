#ifndef TCOMPRAPRODS
#define TCOMPRAPRODS
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include "TFecha.h"
#include "Producto.h"

class TCompraProds{
private:
    TFecha fecha;
    int montoFinal;
    std::set<Producto> productos;
public:
    TCompraProds(TFecha, int, std::set<Producto>);
    TFecha getFecha();
    int getMontoFinal();
    std::set<Producto> getProductos();
};  


#endif