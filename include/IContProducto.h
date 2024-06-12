#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "TFecha.h"

class IContProducto {
public:
    virtual void ingresarDatosPromo(std::string nombre, std::string descripcion, TFecha fechaVenc, int descuento) = 0;
    virtual std::set<std::string> listarNicknamesVendedores() = 0;
    virtual void seleccionarNickname(std::string nombre) = 0;
    virtual std::set<TCodNomProd> listarProductosDisp() = 0;
    virtual void confirmarAltaPromo() = 0;
    virtual std::set<Producto> listarProductos() = 0;
    virtual void ingresarProducto(std::string cod, int cantidad) = 0;
    virtual Compra mostrarCompra() = 0;
    virtual void eliminarComDeProd(std::string cod, int ID) = 0;

    virtual ~IContProducto(){}; //destructor
};