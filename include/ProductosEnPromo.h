#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include "Producto (1).h"

class ProductosEnPromo{
private:
    int cantidadMin;
    Producto *producto
public:
    //constructor
    ProductosEnPromo();

    //metodos de acceso
    int getCantidadMin();

    //destructor
    virtual ~ProductosEnPromo(){};
};