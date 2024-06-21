#include <iostream> // Para std::cin y std::getline
#include "Vendedor.h"


Vendedor::Vendedor(std::string nickname ,std::string contrasena,TFecha fecha, std::string RUT): Usuario(nickname, contrasena, fecha){
    this->RUT = RUT;
}

Vendedor::Vendedor(DataVendedor data):Usuario(data.getNickname(), data.getContrasena(), data.getFecha()){
    this->RUT = data.getRut();
};

Vendedor::~Vendedor(){

}
std::set<Producto*> Vendedor::getProductos(){
    return this->productos;
}
std::string Vendedor::getRut(){
    return this->RUT;
}

void Vendedor::imprimirUsuario(){
    printf("\n_______________\n| ");
    std::string nombre = getNickname();
    std::cout << nombre << std::endl;
    printf("|\n|");
    imprimirFecha();
    printf("\n| Rut:\n|          ");
    std::string raut = getRut();
    std::cout << raut << std::endl;
    printf("|_____________");
}

void Vendedor::insertarProducto(Producto* nuevoProducto){
    productos[nuevoProducto->getCodigo()] = nuevoProducto; 
};


// bool esVendedor(){
//     return true;


// }:


void imprimirProdsVendedorCodNom(Vendedor v){
    std::set<Producto*>::iterator it;
    std::set<Producto*> prods=v->getProductos();
        for (it=prods.begin(); it != prods.end(); ++it){
                (*it)->imprimirProductoCodNom(); //segun chatgpt va asi el it
        }


void imprimirDatosVend(){
    
}


void Vendedor::imprimirProdsConCompraPendDeEnvio(){
    std::set<Producto*>::iterator it;
    std::set<Producto*> prods = this->getProductos();
    for (it=prods.begin(); it != prods.end(); ++it){
        if ((*it)->getCompraProducto()->getEnviado()){
            (*it)->imprimirProducto(); 
        }
    }
}

void Vendedor::listarProductosEnVenta() {
    if (productos.empty()) {
        std::cout << "No hay productos en venta.\n";
    } else {
        for (const auto& prod : productos) {
            std::cout << "Producto: " << prod->getNombre() << std::endl;
        }
    }}

void Vendedor::listarPromocionesVigentes() {
        for (const auto& promo : promociones) {
            if (promo->getFechaVencimiento().mayoroIgual(fechaActual))
            std::cout << "Promoción: " << promo->getNombre() << ", Descuento: " << promo->getDescuento() << "%" << std::endl;
        }
    }
}