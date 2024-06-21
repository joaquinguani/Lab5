
#include <iostream>
#include <string>
#include <set>
#include "Producto.h"
//#include "TCategoria.h"
#include "Producto.h"

Producto::Producto(std::string cod, int stk, int pre, std::string nom, std::string desc, TCategoria cat){
    this->codigo = cod;
    this->stock = stk;
    this->precio = pre;
    this->nombre = nom;
    this->descripcion = desc;
    this->categoria = cat;
    this->promo = NULL;
};

// Getters
std::string Producto::getCodigo() {
    return this->codigo;
}

int Producto::getStock() {
    return this->stock;
}

float Producto::getPrecio() {
    return this->precio;
}

std::string Producto::getNombre() {
    return this->nombre;
}

std::string Producto::getDescripcion() {
    return this->descripcion;
}

TCategoria Producto::getCategoria() {
    return this->categoria;
}

Vendedor* Producto::getVendAsociado() {
    return this->vendAsociado;
}

Promocion* Producto::getPromo() {
    return this->promo;
}

std::map<int, CompraProd*> Producto::getCompraProd(){
    return this->compraProd;
}

/*Compra* Producto::getCompraAsociada(){
    return compraAsociada;
}*/

// Setters
void Producto::setCodigo(int cod) {
    codigo = cod;
}

void Producto::setStock(int stk) {
    stock = stk;
}

void Producto::setPrecio(int pre) {
    precio = pre;
}

void Producto::setNombre(std::string nom) {
    nombre = nom;
}

void Producto::setDescripcion(std::string desc) {
    descripcion = desc;
}

void Producto::setCategoria(TCategoria cat) {
    categoria = cat;
}


// Getter para obtener la categoría del producto
TCategoria Producto::getCategoria()  {
    return categoria;
}


void Producto::imprimirProducto(){
    int cod = codigo;
    std::cout << cod << std::endl;
    int stck = stock;
    std::cout << stck << std::endl;
    int pre = precio;
    std::cout << pre << std::endl;
    std::string nom = nombre;
    std::cout << nom << std::endl;
    std::string des = descripcion;
    std::cout << des << std::endl;
    TCategoria cat = categoria;
    std::cout << cat << std::endl;
};



void Producto::imprimirProductoCodNom(){
//>>>>>>>>> Temporary merge branch 2
    int cod = codigo;
    std::cout << cod << std::endl;
    std::string nom = nombre;
    std::cout << nom << std::endl;
};


Promocion* Producto::getPromo(){
    return this->promo;
};


void Producto::setPromo(Promocion* promo){
    this->promo=promo;
}

CompraProd* Producto::findCompraProd(int ID){
    return compraProd[ID];
}