#ifndef COMPRAPROD
#define COMPRAPROD
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "Producto.h"
#include "Compra.h"

class Compra; //forward declaration
class CompraProd{
private:
    int cantidad;
    bool enviado;
    //Producto *producto; //REVISAR
    Compra* compraAsociada;
public:
    //constructor
    CompraProd(int, bool, Producto*); 

    //metodos de acceso
    int getCantidad();
    bool getEnviado();
    //Producto* getProducto();
    Compra* getCompraAsociada();

    void setCantidad(int cant);
    void setEnviado(bool env);

    //destructor
    virtual ~CompraProd(){}; 
};

#endif