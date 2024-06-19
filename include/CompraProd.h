/*#ifndef COMPRAPROD
#define COMPRAPROD
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "Producto.h"

class CompraProd{
private:
    int cantidad;
    bool enviado;
    Producto *productos; //REVISAR
public:
    //constructor
    CompraProd();

    //metodos de acceso
    int getCantidad();
    bool getEnviado();

    //destructor
    virtual ~CompraProd(){}; 
};

#endif*/