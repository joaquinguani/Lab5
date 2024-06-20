#include <iostream> // Para std::cin y std::getline
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <set>
#include "Promocion.h"
#include "TFecha.h"
#include "Producto.h"

// Constructor
Promocion::Promocion(std::string nombre, std::string descripcion, TFecha fechaVenc, int descuento){
    this->nombre = nombre;
    this->descripcion= descripcion;                                                          
    this->fechaVenc =fechaVenc;
    this->descuento = descuento;   
};

// Getters
std::string Promocion::getNombre() {
    return nombre;
}

std::string Promocion::getDescripcion() {
    return descripcion;
}

TFecha Promocion::getFechaVenc() {
    return fechaVenc;
}

int Promocion::getDescuento() {
    return descuento;
}

std::set<Producto*> Promocion::getProductos() {
    return productos;
}

// Setters
void Promocion::setNombre(const std::string& nom) {
    nombre = nom;
}

void Promocion::setDescripcion(const std::string& desc) {
    descripcion = desc;
}

void Promocion::setFechaVenc(const TFecha& fVenc) {
    fechaVenc = fVenc;
}

void Promocion::setDescuento(int descu) {
    descuento = descu;
}

// Métodos
void Promocion::agregarProdAPromo(int idProducto, int idPromocion) {
    // Aquí se debe implementar la lógica para agregar un producto a la promoción.
    // Ejemplo de implementación básica:
    // ProductosEnPromo* nuevoProductoEnPromo = new ProductosEnPromo(idProducto, idPromocion);
    // promproductos.insert(nuevoProductoEnPromo);
}

void Promocion::aplicarDescuento(int idProducto, int descuento) {
    // Aquí se debe implementar la lógica para aplicar un descuento a un producto específico.
    // Ejemplo de implementación básica:
    // for (auto& producto : promproductos) {
    //     if (producto->getIdProducto() == idProducto) {
    //         producto->setDescuento(descuento);
    //         break;
    //     }
    // }
}

void Promocion::devolverDatosProdsPromo(){
    std::set<Producto*>::iterator it;
    std::set<Producto*> prods = this->getProductos();
    for (it= prods.begin(); it != prods.end(); ++it){
        //imprimir datos prod
        (*it)->imprimirProducto();
        //imprimir datos vendedor
        Vendedor* vnd = (*it)->getVendAsociado();
        vnd->imprimirUsuario();
    }
}