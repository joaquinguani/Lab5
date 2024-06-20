#ifndef COMPRAPROD
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
    Producto *producto; //REVISAR
public:
    //constructor
    CompraProd(int, bool, Producto*); 

    //metodos de acceso
    int getCantidad();
    bool getEnviado();
    Producto* getProducto();

    void setCantidad(int cant);
    void setEnviado(bool env);

    //destructor
    virtual ~CompraProd(){}; 
};

#endif