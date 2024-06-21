
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
#include "Cliente.h"


class Compra {
private:
    TFecha* fecha;
    int MontoFinal;
    //std::set<CompraProd*> compraProducto; //chequear 
    std::map<std::string, CompraProd*> compraProducto; //la clave es el cod del producto??
    std::map<std::string,Producto*> productos; //la clave es el codigo
    Cliente* clienteAsociado;
    
public:
    // Constructor
    Compra(TFecha f, int monto);


    // Getters
    TFecha getFecha();
    float getMontoFinal();
    std::map<std::string,Producto*> getProductos();
    
    std::set<CompraProd*> getCompraProducto();
    Cliente* getClienteAsociado();

    // Setters
    void setFecha(const TFecha& f);
    void setMontoFinal(int monto);

    // Métodos
    void agregarProdACompra(Producto prod, int cod, int cant);
    int aplicarDescuento(int precio, int cant, int codProd, Producto* prod);
    void sumarAlMonto(int pre);
    void asociarCompraProd(CompraProd* cp);
    void imprimirCompraCompleto();
};

#endif