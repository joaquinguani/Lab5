#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>


class Cliente:public Usuario {
    private: 
        direccion: direccion
        ciudad: std::string
        notificaciones: std::set<notificacion>;

    public:
        // Constructor
        Cliente(std::string,std::string,TFecha,direccion,std::string,std::set<notificacion>);
        ~Cliente ();

        // Getters
        direccion getDireccion();
        std::string getCiudad();
        std::set<notificacion> getNotificaciones();

        // Setters
        void setCiudad();
        void setDireccion();
        vodi agregarSuscripcion(n);


        // Métodos
        Set(TNotificacion) listarNotificaciones();
        void eliminarNotificaciones();
        void notificar(TNotificacion);
};