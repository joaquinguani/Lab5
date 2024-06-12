#ifndef INFOCLIENTE
#define INFOCLIENTE
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include "TDireccion.h"
#include "TCompraProds.h"

class InfoCliente{
private:
    TDireccion direccion;
    std::string ciudad;
    TCompraProds compra;
public:
    InfoCliente(TDireccion, std::string, TCompraProds);
    TDireccion getDireccion();
    std::string getCiudad();
    TCompraProds getCompra();
};  

#endif