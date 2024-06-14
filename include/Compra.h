
#ifndef COMPRA
#define COMPRA
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>

#include "TFecha.h"
#include"CompraProd.h"

main

class Compra {
private:
    TFecha fecha;
    int MontoFinal;
    std::set<CompraProd*> compraproducto; //chequear
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

    void sumarAlMonto(int pre);
};

#endif