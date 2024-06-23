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
#include "Vendedor.h"
#include "ContProducto.h"

#include "CompraProd.h"

#include "ContUsuario.h"
#include "Compra.h"


class Promocion; //forward declaration
class Producto {
private:
    int codigo;
    int stock;
    int precio;
    std::string nombre;
    std::string descripcion;
    char categoria; //a: ropa   b: electrodomestrico   c: otros
    std::map<int,Comentario*> comentarios;
    Vendedor* vendAsociado;
    Promocion* promo;
    std::map<int, CompraProd*> compraProd; // la clave es el codigo de la compra
    //std::set<Compra*> comprasAsociadas;
public:
    // Constructor
    Producto(int stk, int pre, std::string nom, std::string desc, char cat);

    // Getters
    int getCodigo();
    int getStock();
    float getPrecio();
    std::string getNombre();
    std::string getDescripcion();
    char getCategoria();

    Vendedor* getVendAsociado();
    Promocion* getPromo();
    std::map<int, CompraProd*> getCompraProd();
    //Compra* getCompraAsociada();



    // Setters
    void setCodigo(int cod);
    void setStock(int stk);
    void setPrecio(int pre);
    void setNombre(std::string nom);
    void setPromo(Promocion* promo);
    void setDescripcion(std::string desc);
    void setCategoria(char cat);
    Vendedor* setVendAsociado();
    

    // Métodos
    Producto getDatos();
    bool vendedor(std::string vendedor);
    void eliminarRefComen(int);
    void imprimirProducto();
    void imprimirProductoCodNom();
    CompraProd* findCompraProd(int);
    void ingresarCompraProd(CompraProd* compraP);
    void crearComentario(std::string, Usuario*);
    void imprimirComDeProd();
    bool estaComen(int);

    //Destructor
    ~Producto();
    

};

#endif