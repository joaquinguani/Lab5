#ifndef ICONTUSUARIO
#define ICONTUSUARIO
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include "TNotificacion.h"


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
    static ContUsuario* getInstanciaContUsu();
    //otros metodos
    int getCantComen();
    void sumarComentario();



    int sizeCol();
    

    void imprimirUsuarios(); //casos: a,

    //funciones del MAPA Usuario
    Usuario* find(std::string);
    bool estaUsuario(std::string); 
    void ingresarDatosVendedor(DataVendedor data); //agrega un vendedor
    void ingresarDatosCliente(DataCliente data); //agrega un cliente 
    //funciones del MAPA Coment
    Comentario* findComen(int ID);

    
    void imprimirVendedores();
    void imprimirClientes();
    std::map<std::string, Usuario *> getUsuarios(); // ESTO TE DEVUELVE UNA COPIA, SOLO SIRVE PARA VER SI HAY COSAS, NO PARA AGREGAR NI SACAR!!(soy el pelado jeje)
    void seleccionarCliente(Cliente cliente);
    std::set<std::string> listarNombreDeUsuarios();
    std::set<std::string> listarComDeUsuarios(std::string nombre);
    void eliminarComentario(int ID);
    std::set<std::string> listarNicknamesClientes();
    void listarVendedoresNoSubsXCliente(Cliente* cli);
    void agregarSuscripcion();
    std::set<TNotificacion> listarNotificaciones(std::string nickname);
    void listarVendSuscripto(Cliente* cli);
    void eliminarSuscripciones();
    void listarNicknamesVendedores();
    std::map<std::string, Cliente*> getColClientes();
    std::map<std::string, Vendedor*> getColVendedores();
    Cliente* buscarClientePorNombre(std::string cli);
    Vendedor* buscarPorNombre(std::string vend);

    virtual ~IContUsuario(){}; //destructor 
};

#endif