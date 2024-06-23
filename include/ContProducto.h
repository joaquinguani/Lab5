#ifndef CONTPRODUCTO
#define CONTPRODUCTO
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include "TFecha.h"
#include "Producto.h"
#include "Compra.h"
#include "Promocion.h"
#include <cstdio>


class ContProducto : public IContProducto {
private:
    int codigoProducto;
    std::map<int, Producto *> colProductos; //cambie a col de nuevo jeje
    ContProducto();
    static ContProducto * instanciaContProd;
    std::set<Compra *> colCompra; //cambie a set
    std::map<std::string, Promocion *> colPromocion;
public:
    //constructor
    static ContProducto* getInstanciaContProd();

    //getters
    std::map<int, Producto*> getColProductos();
    std::set<Compra*> getColCompra();
    std::map<std::string, Promocion *> getcolPromocion();
    int getCodigoProducto();

    //mapaProducto
    void insertarProducto(Producto*);
    bool estaProd(int);
    Producto* find(int);

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
    Promocion* buscarPromoPorNombre(std::string promo);
    Promocion* findPromocion(std::string);
    void agregarPromocion(Promocion* promo);
    void sumarCodigoProducto();

    Producto* buscarProdPorNombre(std::string produ);
    //caso j
    void imprimirComprasConProdPendiente(Producto*);

    virtual ~ContProducto(){}; //destructor
    std::set<Promocion*> listarPromosVigentes();
};

#endif