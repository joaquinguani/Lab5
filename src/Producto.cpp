
#include <iostream>
#include <string>
#include <set>
#include "Producto.h"
//#include "TCategoria.h"

Producto::Producto( int stk, int pre, std::string nom, std::string desc, char cat){
    ContProducto* contProdu = ContProducto::getInstanciaContProd();
    this->codigo = contProdu->getCodigoProducto();
    contProdu->sumarCodigoProducto();
    this->stock = stk;
    this->precio = pre;
    this->nombre = nom;
    this->descripcion = desc;
    this->categoria = cat;
};

// Getters
int Producto::getCodigo() {
    return this->codigo;
};

Producto::~Producto(){}

int Producto::getStock() {
    return this->stock;
};

float Producto::getPrecio() {
    return this->precio;
};

std::string Producto::getNombre() {
    return this->nombre;
};

std::string Producto::getDescripcion() {
    return this->descripcion;
};

char Producto::getCategoria() {
    return this->categoria;
};

Vendedor* Producto::getVendAsociado() {
    return this->vendAsociado;
};

Promocion* Producto::getPromo() {
    return this->promo;
};

std::map<int, CompraProd*> Producto::getCompraProd(){
    return this->compraProd;
};

/*Compra* Producto::getCompraAsociada(){
    return compraAsociada;
}*/

// Setters
void Producto::setCodigo(int cod) {
    codigo = cod;
};

void Producto::setStock(int stk) {
    stock = stk;
};

void Producto::setPrecio(int pre) {
    precio = pre;
};

void Producto::setNombre(std::string nom) {
    nombre = nom;
};

void Producto::setDescripcion(std::string desc) {
    descripcion = desc;
};

void Producto::setCategoria(char cat) {
    categoria = cat;
};


// Getter para obtener la categoría del producto
char Producto::getCategoria()  {
    return categoria;
};


void Producto::imprimirProducto(){
    int cod = cod;
    std::cout << cod << std::endl;
    int stck = stock;
    std::cout << stck << std::endl;
    int pre = precio;
    std::cout << pre << std::endl;
    std::string nom = nombre;
    std::cout << nom << std::endl;
    std::string des = descripcion;
    std::cout << des << std::endl;
    if (categoria = 'a'){printf("\nRopa\n");}
    if (categoria = 'b'){printf("\nElectrodomestico\n");}
    if (categoria = 'c'){printf("\nOtro\n");}
};


void Producto::imprimirProductoCodNom(){
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
};


CompraProd* Producto::findCompraProd(int ID){
    return compraProd[ID];
};

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
};

bool Producto::estaComen(int ID){
    return comentarios[ID]!=NULL;
};

void Producto::eliminarRefComen(int ID){
    comentarios.erase(ID);
};

void Producto::ingresarCompraProd(CompraProd* compraP){
    this->compraProd[this->getCodigo()] = compraP;
};
