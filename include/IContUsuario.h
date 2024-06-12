#ifndef ICONTUSUARIO
#define ICONTUSUARIO
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
//#include <sstream>


class IContUsuario {
public:
    virtual void ingresarDatosUsuario(DataUsuario data) = 0;
    virtual std::set<std::string> listarVendedores() = 0;
    virtual void seleccionarCliente(Cliente cliente) = 0;
    virtual std::set<std::string> listarNombreDeUsuarios() = 0;
    virtual std::set<std::string> listarComDeUsuarios(std::string nombre) = 0;
    virtual void eliminarComentario(int ID) = 0;
    virtual std::set<std::string> listarNicknamesClientes() = 0;
    virtual std::set<std::string> listarVendedoresNoSubsXCliente(std::string cli) = 0;
    virtual void agregarSuscripcion() = 0;
    virtual std::set<TNotificacion> listarNotificaciones(std::string nickname) = 0;
    virtual std::set<std::string> listarVendSuscripto(std::string nickC) = 0;
    virtual void eliminarSuscripciones() = 0;

    virtual ~IContUsuario(){}; //destructor 
};

#endif