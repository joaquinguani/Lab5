#ifndef CONTUSUARIO
#define CONTUSUARIO
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <map>
#include "Comentario.h"
#include "Usuario.h"
#include "Cliente.h"
#include "Vendedor.h"
#include "DataUsuario.h"




class ContUsuario {
private:
    std::map<std::string, Comentario *> colComentario;
    std::map<std::string, Usuario *> colUsuarios;
public:
    //constructor
    ContUsuario(std::map<std::string, Usuario *>);

    //otros metodos
    void ingresarDatosVendedor(DataVendedor data);
    void ingresarDatosCliente(DataCliente data);

    (std::map<std::string, Usuario *>)* listarUsuarios();

    int sizeCol();

    std::set<std::string> listarVendedores();
    void seleccionarCliente(Cliente cliente);
    std::set<std::string> listarNombreDeUsuarios();
    std::set<std::string> listarComDeUsuarios(std::string nombre);
    void eliminarComentario(int ID);
    std::set<std::string> listarNicknamesClientes();
    std::set<std::string> listarVendedoresNoSubsXCliente(std::string cli);
    void agregarSuscripcion();
    std::set<TNotificacion> listarNotificaciones(std::string nickname);
    std::set<std::string> listarVendSuscripto(std::string nickC);
    void eliminarSuscripciones();

    virtual ~ContUsuario(){}; //destructor 
};
#endif