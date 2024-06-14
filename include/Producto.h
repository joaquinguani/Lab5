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

class Promocion; //forward declaration
class Producto {
private:
    std::string codigo;
    int stock;
    int precio;
    std::string nombre;
    std::string descripcion;
    std::string categoria;
    std::set<Comentario> *comentarios;
    
    

public:
    // Constructor
    Producto(std::string cod, int stk, int pre, std::string nom, std::string desc, std::string cat);

    // Getters
    std::string getCodigo();
    int getStock();
    int getPrecio();
    std::string getNombre();
    std::string getDescripcion();
    std::string getCategoria();

    // Setters
    void setCodigo(std::string cod);
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

#endif