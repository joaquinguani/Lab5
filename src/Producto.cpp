
#include <iostream>
#include "Producto.h"
#include "TCategoria.h"
#include "Producto.h"

Producto::Producto(int cod, int stk, int pre, std::string nom, std::string desc, TCategoria cat){
    this->codigo = cod;
    this->stock = stk;
    this->precio = pre;
    this->nombre = nom;
    this->descripcion = desc;
    this->categoria = cat;
    this->promo = NULL;
};

Vendedor* Producto::getVendAsociado(){
    return this->vendAsociado;
};


int Producto::getCodigo()  {
    return codigo;
}


int Producto::getStock()  {
    return stock;
}


float Producto::getPrecio() {
    return precio;
}


std::string Producto::getNombre()  {
    return nombre;
}


std::string Producto::getDescripcion()  {
    return descripcion;
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

void Producto::crearComentario(std::string txt, Usuario* usu){
    ContUsuario* contUsuari = ContUsuario::getInstanciaContUsu();
    Comentario* NuevoComen = new Comentario(txt);
    NuevoComen->setUsuario(usu);
    usu->agregarComen(NuevoComen);
    int ID = NuevoComen->getID();
    comentarios[ID] = NuevoComen;
    NuevoComen->setProdPadre(this);
};

void Producto::imprimirComDeProd(){
    std::map<int, Comentario *>::iterator it;
    for (it= comentarios.begin(); it != comentarios.end(); ++it){
            Comentario* comen = it->second;
            comen->imprimirComenYHijos();
    }
}

bool Producto::estaComen(int ID){
    return comentarios[ID]!=NULL
}