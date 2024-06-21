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
#include <map>

class Promocion {
private:
    std::string nombre;
    std::string descripcion;
    TFecha fechaVenc;
    int descuento;
    std::set<ProductosEnPromo*> promProductos;
    std::set<Producto*> productos;

public:
    // Constructor
    Promocion(std::string nom, std::string desc, TFecha* fVenc, int descu);

    // Getters

    std::string getNombre();
    std::string getDescripcion(); 
    TFecha getFechaVenc();
    int getDescuento();
    std::set<Producto*> getProductos();


    // Setters
    void setNombre(const std::string& nom);
    void setDescripcion(const std::string& desc);
    void setFechaVenc(const TFecha& fVenc);
    void setDescuento(int descu);

    // Métodos
    void agregarProdAPromo(Producto* producto);
    void agregarProdAPromoCantMin(Producto* producto,std::string cantMin);
    void aplicarDescuento(int idProducto, int descuento);
    void devolverDatosProdsPromo();
    void imprimirPromocion();
};


#endif