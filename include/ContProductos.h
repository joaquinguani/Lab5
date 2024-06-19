#ifndef CONTPRODUCTO
#define CONTPRODUCTO
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include "TFecha.h"
#include "TCodNomProd.h"
#include "Producto.h"
#include "Compra.h"


class ContProducto {
private:
    std::map<int, Producto *> colProducto;
    std::map<std::string, Compra *> colCompra;
    std::map<std::string, Promocion *> colPromocion;
public:
    //constructor
    ContProducto();

    //otros metodos
    void ingresarDatosPromo(std::string nombre, std::string descripcion, TFecha fechaVenc, int descuento);
    std::set<std::string> listarNicknamesVendedores();
    void seleccionarNickname(std::string nombre);
    std::set<TCodNomProd> listarProductosDisp(); 
    void confirmarAltaPromo();
    std::set<Producto> listarProductos(); //porque no TCodNomProd? 
    void ingresarProducto(std::string cod, int cantidad);
    Compra mostrarCompra();
    void eliminarComDeProd(std::string cod, int ID);

    virtual ~ContProducto(){}; //destructor
};

#endif