#ifndef CONTPRODUCTO
#define CONTPRODUCTO
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include "TFecha.h"
#include "TCodNomProd.h"
#include "Producto.h"
#include "Compra.h"
#include "Promocion.h"
#include <cstdio>


class ContProducto {
private:
    std::map<int, Producto *> Productos;
    std::map<std::string, Compra *> colCompra;
    std::map<std::string, Promocion *> colPromocion;
public:
    //constructor
    ContProducto();

    //otros metodos
    void ingresarDatosPromo(std::string nombre, std::string descripcion, TFecha fechaVenc, int descuento);
    std::set<std::string> listarNicknamesVendedores();
    void seleccionarNickname(std::string nombre);
    void listarProductosDisp();
    void listarProductosDisp(Vendedor* vendedor); //una con vendedor asociado para el caso E
    void confirmarAltaPromo();
    void listarProductos(); //que sea void y despues dentro de la funcion imprima
    void ingresarProducto(std::string cod, int cantidad);
    Compra mostrarCompra();
    void eliminarComDeProd(std::string cod, int ID);
    std::set<Promocion*> listarPromosVigentes();
    Producto* buscarProducto(int clave);
    std::map<int, Producto*> getProductos();
    Promocion* buscarPromoPorNombre(std::string promo);
    Producto* buscarProdPorNombre(std::string produ);

    virtual ~ContProducto(){}; //destructor
    std::set<Promocion*> listarPromosVigentes();
};

#endif