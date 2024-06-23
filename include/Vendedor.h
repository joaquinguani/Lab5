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
        //virtual void notificar(ISuscripciones *); //en el teorico dice que es privada
        std::set<Producto*> productos;// 
        //std::map<std::string, Producto*> productos; //mapa mejor
    public:
    
        Vendedor(std::string  ,std::string ,TFecha , std::string );
        Vendedor(DataVendedor);
        virtual void imprimirUsuario();
        std::string getRut();
        std::set<Producto*> getProductos();



        virtual~Vendedor();
           
        virtual bool esVendedor();
           
           std::string getRUT();
           std::set<std::string> getsuscriptores();
           
           virtual void agregarSuscriptor(Cliente *);
           void eliminarSuscriptor(Cliente *);
           void notificarClientes(Promocion* ); 
           void insertarProducto(Producto*);
           void imprimirProdsVendedorCodNom();
           void imprimirProdsConCompraPendDeEnvio();
           void listarProductosEnVenta(); 
           void listarPromocionesVigentes();

        //    void setsuscriptores(std::set<std::string>);
        //    bool estaSuscrito(std::string);
        //    void setRUT(std::string);
        //    void eliminar(ISuscripciones *);


};


#endif
