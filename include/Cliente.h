#ifndef CLIENTE
#define CLIENTE
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "Usuario.h"
//#include "ISuscripciones.h"
#include "TDireccion.h"
#include "TNotificacion.h"
#include "DataCliente.h"
#include "TFecha.h"

class Cliente:public Usuario/*,public ISuscripciones */{
    private: 
        TDireccion direccion;
        std::string ciudad;
        std::set<Compra*> compras; 
        //std::set<TNotificacion*> notificaciones; // el * va adentro o afuera??
    public:
        // Constructor
        Cliente(std::string, std::string, TFecha, TDireccion,std::string); //no deja
        Cliente(DataCliente);
        virtual~Cliente();

        // Getters
        TDireccion getDireccion();
        std::string getCiudad();
        virtual void imprimirUsuario();
        void imprimirDireccion();
        //std::set<TNotificacion> getNotificaciones();

        // Setters
        void setCiudad();
        void setDireccion();
        
        void agregarSuscripcion();
        void listarComprasRealizadas();


        // Métodos
        
        bool esVendedor() const override { return false; };
        
        std::set<TNotificacion> listarNotificaciones();
        void eliminarNotificaciones();
        void notificar(TNotificacion);
        void agregarCompra(Compra* compra);
};


#endif
