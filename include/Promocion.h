#ifndef PROMOCION
#define PROMOCION
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "ProductosEnPromo.h"
#include "TFecha.h"

class Promocion {
private:
    std::string nombre;
    std::string descripcion;
    TFecha fechaVenc;
    int descuento;
    std::set<ProductosEnPromo*> promproductos;
    std::set<Producto*> productos;
    

public:
    // Constructor
    Promocion(std::string nom, std::string desc, TFecha fVenc, int descu);

    // Getters

    std::string getNombre();
    std::string getDescripcion(); 
    TFecha getFechaVenc();
    int getDescuento();
 main

    // Setters
    void setNombre(const std::string& nom);
    void setDescripcion(const std::string& desc);
    void setFechaVenc(const TFecha& fVenc);
    void setDescuento(int descu);

    // Métodos
    void agregarProdAPromo(int idProducto, int idPromocion);

    void aplicarDescuento(int idProducto, int descuento);
};


#endif