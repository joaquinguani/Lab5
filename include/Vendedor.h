#ifndef VENDEDOR
#define VENDEDOR
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include "Producto.h"
#include "Usuario.h"
#include "DataVendedor.h"
#include "ISuscripciones.h"

class Vendedor:public Usuario, public ISuscripciones{
    private:std::string RUT;
        std::map<std::string,ISuscripciones*> suscriptores;
        void notificar(ISuscripciones *); //en el teorico dice que es privada
        std::set<Producto*> productos;// 
        //std::map<std::string, Producto*> productos; //mapa mejor
    public:
    
        Vendedor(std::string  ,std::string ,TFecha , std::string );
        Vendedor(DataVendedor);
        virtual void imprimirUsuario();
        std::string getRut();
        std::set<Producto*> getProductos();



        virtual~Vendedor();
           
        bool esVendedor() const override { return true; };
           
           std::string getRUT();
           void setRUT(std::string);
           std::set<std::string> getsuscriptores();
           void setsuscriptores(std::set<std::string>);
           bool estaSuscrito(std::string);
           void agregarSuscriptor(Cliente *);
           void eliminar(ISuscripciones *);
           void insertarProducto(Producto*);
           void imprimirProdsVendedorCodNom(Vendedor);
           void imprimirProdsConCompraPendDeEnvio();
           void listarProductosEnVenta(); 
           void listarPromocionesVigentes();
};


#endif
