
#ifndef COMPRA
#define COMPRA
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>

#include "TFecha.h"
#include"CompraProd.h"
#include "Producto.h"


class Compra {
private:
    TFecha fecha;
    int MontoFinal;
    std::set<CompraProd*> compraProducto; //chequear
    
public:
    // Constructor
    Compra(TFecha f, int monto);


    // Getters
    TFecha getFecha();
    int getMontoFinal();

    // Setters
    void setFecha(const TFecha& f);
    void setMontoFinal(int monto);

    // Métodos
    void agregarProdACompra(Producto prod, int cod, int cant);
    int aplicarDescuento(int precio, int cant, int codProd, Producto* prod);
    void sumarAlMonto(int pre);
};

#endif