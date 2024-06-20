#ifndef PRODUCTO
#define PRODUCTO
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "Promocion.h"
#include "Comentario.h"
//#include "TCategoria.h"
#include "Vendedor.h"
#include "Compra.h"

enum TCategoria {
    ropa,
    electrodomesticos,
    otros
};

class Promocion; //forward declaration
class Producto {
private:
    int codigo;
    int stock;
    int precio;
    std::string nombre;
    std::string descripcion;
    TCategoria categoria; //decia string
    std::set<Comentario*> comentarios;
    Vendedor* vendAsociado;
    Promocion* promo;
    CompraProd* compraProducto;

public:
    // Constructor
    Producto(int cod, int stk, int pre, std::string nom, std::string desc, TCategoria cat);

    // Getters
    int getCodigo();
    int getStock();
    float getPrecio();
    std::string getNombre();
    std::string getDescripcion();
    TCategoria getCategoria();

    Vendedor* getVendAsociado();
    Promocion* getPromo();
    CompraProd* getCompraProducto();



    // Setters
    void setCodigo(int cod);
    void setStock(int stk);
    void setPrecio(int pre);
    void setNombre(std::string nom);
    void setPromo(Promocion* promo);
    void setDescripcion(std::string desc);
    void setCategoria(TCategoria cat);
    Vendedor* setVendAsociado();

    // Métodos
    Producto getDatos();
    bool vendedor(std::string vendedor);
    void eliminarCom(int codigoProducto);
    void imprimirProducto();
    void imprimirProductoCodNom();

    //Destructor
    ~Producto();
};

#endif