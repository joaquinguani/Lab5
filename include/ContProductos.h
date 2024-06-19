/*#ifndef COMPRAPROD
#define COMPRAPROD
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>

#include "TFecha.h"
#include "TCodNomProd.h"
#include "Producto.h"
#include "Compra.h"

main

class ContProducto {
private:
    
public:
    //constructor
    ContProducto();

    //otros metodos
    void ingresarDatosPromo(std::string nombre, std::string descripcion, TFecha fechaVenc, int descuento);
    std::set<std::string> listarNicknamesVendedores();
    void seleccionarNickname(std::string nombre);
    std::set<TCodNomProd> listarProductosDisp();
    void confirmarAltaPromo();
    std::set<Producto> listarProductos();
    void ingresarProducto(std::string cod, int cantidad);
    Compra mostrarCompra();
    void eliminarComDeProd(std::string cod, int ID);

    virtual ~ContProducto(){}; //destructor
};

#endif*/