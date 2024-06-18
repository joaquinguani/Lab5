#include "Producto.h"

Producto::Producto(int cod, int stk, int pre, std::string nom, std::string desc, std::string cat{
    this->codigo = cod;
    this

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
    std::string cat = categoria;
    std::cout << cat << std::endl;
}
