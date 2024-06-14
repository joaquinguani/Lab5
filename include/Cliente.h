#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "Usuario.h"
#include "ISuscripciones.h"
#include "TDireccion.h"
#include "TNotificacion.h"

class Cliente:public Usuario,public ISuscripciones {
    private: 
        TDireccion direc;
        std::string ciudad;
        std::set<TNotificacion*> notificaciones; // el * va adentro o afuera??
    public:
        // Constructor
        Cliente(TDireccion direc,std::string ciudad ,std::set<TNotificacion> notifiaciones):Usuario(nickname,contrasena,fecha);
        ~Cliente ();

        // Getters
        TDireccion getDireccion();
        std::string getCiudad();
        std::set<TNotificacion> getNotificaciones();

        // Setters
        void setCiudad();
        void setDireccion();
        void agregarSuscripcion(n);


        // Métodos
        std::set<TNotificacion> listarNotificaciones();
        void eliminarNotificaciones();
        void notificar(TNotificacion);
};