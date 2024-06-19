#ifndef PRODUCTOSENPROMO
#define PRODUCTOSENPROMO
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
//#include <sstream>

class ProductosEnPromo{
private:
    int cantidadMin;
    Producto *producto;
public:
    //constructor
    ProductosEnPromo(); // y esto?

    //metodos de acceso
    int getCantidadMin();

    //destructor
    virtual ~ProductosEnPromo(){};
};

#endif