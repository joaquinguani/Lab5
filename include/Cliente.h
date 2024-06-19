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

class Cliente:public Usuario/*,public ISuscripciones */{
    private: 
        TDireccion direccion;
        std::string ciudad;
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
/*
        // Setters
        void setCiudad();
        void setDireccion();
        
        void agregarSuscripcion();


        // Métodos
        
        virtual bool esVendedor();
        
        std::set<TNotificacion> listarNotificaciones();
        void eliminarNotificaciones();
        void notificar(TNotificacion);
        */
};


#endif
