#ifndef VENDEDOR
#define VENDEDOR
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "Producto.h"
#include "Usuario.h"
#include "DataVendedor.h"
#include "ISuscripciones.h"

class Vendedor:public Usuario{
    private:std::string RUT;
        std::set<ISuscripciones*> suscriptores;
        void notificar(ISuscripciones *); //en el teorico dice que es privada
        //std::set<Producto*> productos;// 
        std::map<int, Producto*> productos; //mapa mejor
    public:
    
        Vendedor(std::string  ,std::string ,TFecha , std::string );
        Vendedor(DataVendedor);
        virtual void imprimirUsuario();
        std::string getRut();

        virtual~Vendedor();
           
        bool esVendedor() const override { return true; };
           
           std::string getRUT();
           std::set<Producto*> getProductos();
           void setRUT(std::string);
           std::set<std::string> getsuscriptores();
           void setsuscriptores(std::set<std::string>);
           bool estaSuscrito(std::string);
           void agregar(ISuscripciones *);
           void eliminar(ISuscripciones *);
           void insertarProducto(Producto*);
           void imprimirProdsVendedorCodNom(Vendedor);
           void imprimirProdsConCompraPendDeEnvio();
           void listarProductosEnVenta(); 
           void listarPromocionesVigentes();
};


#endif
