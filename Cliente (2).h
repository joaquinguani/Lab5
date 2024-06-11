#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "usuario.h"
#include "ISuscripciones.h"

class Cliente:public Usuario,public ISuscripciones {////// DUDA
    private: 
        direccion direc;
        std::string ciudad;
        std::set<notificacion> notificaciones;
    public:
        // Constructor
        Cliente(direcion direc,std::string ciudad ,std::set<notificacion> notifiaciones):Usuario(nickname,contrasena,fecha);
        ~Cliente ();

        // Getters
        direccion getDireccion();
        std::string getCiudad();
        std::set<notificacion> getNotificaciones();

        // Setters
        void setCiudad();
        void setDireccion();
        void agregarSuscripcion(n);


        // Métodos
        std::set<TNotificacion> listarNotificaciones();
        void eliminarNotificaciones();
        void notificar(TNotificacion);
};