/*#ifndef PRODUCTO
#define PRODUCTO
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "Promocion.h"
#include "Comentario.h"
#include "TCategoria.h"


class Promocion; //forward declaration
class Producto {
private:
    int codigo;
    int stock;
    int precio;
    std::string nombre;
    std::string descripcion;
    TCategoria categoria; //decia string
    std::set<Comentario> *comentarios;
    
    

public:
    // Constructor
    Producto(int cod, int stk, int pre, std::string nom, std::string desc, TCategoria cat);

    // Getters
    int getCodigo();
    int getStock();
    int getPrecio();
    std::string getNombre();
    std::string getDescripcion();
    std::string getCategoria();

    // Setters
    void setCodigo(int cod);
    void setStock(int stk);
    void setPrecio(int pre);
    void setNombre(std::string nom);
    void setDescripcion(std::string desc);
    void setCategoria(std::string cat);

    // Métodos
    Producto getDatos();
    bool vendedor(std::string vendedor);
    void eliminarCom(int codigoProducto);
};

#endif*/