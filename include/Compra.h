
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
    TFechaActual* fecha;
    int MontoFinal;
    //std::set<CompraProd*> compraProducto; //chequear 
    std::map<int, CompraProd*> compraProducto; //la clave es el cod del producto
    std::map<int,Producto*> productos; //la clave es el codigo 
    Cliente* clienteAsociado;
    int id; //para identificar cada compra
    
public:
    // Constructor
    Compra(TFechaActual* f, int monto, int id);


    // Getters
    TFechaActual* getFechaCompra();
    float getMontoFinal();
    std::map<int,Producto*> getProductos();
    int getId();
    std::map<int, CompraProd*> getCompraProducto();
    Cliente* getClienteAsociado();

    // Setters
    void setFecha(const TFecha& f);
    void setMontoFinal(int monto);

    // Métodos
    void agregarProdACompra(Producto prod, int cod, int cant);
    int aplicarDescuento(int precio, int cant, int codProd, Producto* prod);
    void sumarAlMonto(int pre);
    void asociarCompraProd(CompraProd* cp, int cod);
    void imprimirCompraCompleto();
    void asociarCliente(Cliente* cli);
};

#endif