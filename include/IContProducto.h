#ifndef ICONTPRODUCTO
#define ICONTPRODUCTO
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include "TCodNomProd.h"
#include "TFecha.h"
#include "Producto.h"
#include "Compra.h"

class IContProducto {
public:
     //constructor
    static ContProducto* getInstanciaContProd();
    //getters
    virtual std::map<int, Producto*> getColProductos() = 0;
    virtual std::set<Compra*> getColCompra() = 0;
    virtual int getCodigoProducto() = 0;
    //mapaProducto
    virtual void insertarProducto(Producto*) = 0;
    virtual bool estaProd(int) = 0;
    virtual Producto* find(int) = 0;
    //otros metodos
    virtual void listarProductosDisp() = 0;
    virtual void listarProductosDisp(Vendedor* vendedor) = 0; //una con vendedor asociado para el caso E
    virtual void listarProductos() = 0; //que sea void y despues dentro de la funcion imprima
    virtual std::set<Promocion*> listarPromosVigentes() = 0;
    virtual Producto* buscarProducto(int clave) = 0;
    virtual Promocion* buscarPromoPorNombre(std::string promo) = 0;
    virtual Promocion* findPromocion(std::string) = 0;
    virtual void agregarPromocion(Promocion* promo) = 0;
    virtual void sumarCodigoProducto() = 0;
    //caso j
    virtual void imprimirComprasConProdPendiente(Producto*) = 0;

    virtual ~IContProducto(){}; //destructor
};

#endif