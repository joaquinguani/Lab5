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


class CompraProd{
private:
    int cantidad;
    bool enviado;
    Producto *producto; 
    Compra* compraAsociada;
public:
    //constructor
    CompraProd(int, bool, Producto*); 

    //metodos de acceso
    int getCantidad();
    bool getEnviado();
    //Producto* getProducto();
    Compra* getCompraAsociada();
    void setCompraAsociada(Compra* compra);

    void setCantidad(int cant);
    void setEnviado(bool env);
    void imprimirCompraProd();

    //destructor
    virtual ~CompraProd(){}; 
};

#endif