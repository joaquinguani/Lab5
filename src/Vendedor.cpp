#include <iostream> // Para std::cin y std::getline
#include "Vendedor.h"


Vendedor::Vendedor(std::string nickname ,std::string contrasena,TFecha fecha, std::string RUT): Usuario(nickname, contrasena, fecha){
    this->RUT = RUT;
}

Vendedor::Vendedor(DataVendedor data):Usuario(data.getNickname(), data.getContraseña(), data.getFecha()){
    this->RUT = data.getRut();
};

Usuario Vendedor::creadorUsuario(DataVendedor data){
    return Vendedor(data.getNickname(), data.getContraseña(),data.getFecha(),data.getRut());
};

std::set<Producto*> Vendedor::getProductos(){
    return this->productos;
}

void Cliente::imprimirUsuario(){
    std::string nombre = nickname;
    std::cout << nombre << std::endl;
    imprimirFecha();
    std::string RUT = rut;
    std::cout << RUT << std::endl;
};

void Vendedor::insertarProducto(Producto* nuevoProducto){
    productos.insert(nuevoProducto);
};

bool esVendedor(){
    return true;
}:

void imprimirProdsVendedor(Vendedor v){
    std::set<Producto*>::iterator it;
    std::set<Producto*> prods=v->getProductos();
        for (it=prods.begin(); it != prods.end(); ++it){
                it->imprimirProducto();
        }
}
