#ifndef CONTUSUARIO
#define CONTUSUARIO
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "IContUsuario.h"
#include "IContUsuario.h"
#include <map>
#include "Comentario.h"
#include "Usuario.h"
#include "Cliente.h"
#include "Cliente.h"
#include "TNotificacion.h"
#include "Vendedor.h"
#include "DataUsuario.h"


class ContUsuario {
private:
    std::map<std::string, Comentario *> colComentario;
    std::map<std::string, Usuario *> colUsuarios;
    //std::map<std::string, Vendedor*> colVendedores; //hacemos esto o lo de dynamic cast?
    //std::map<std::string, Cliente*> colClientes;
    
public:
    //constructor
    ContUsuario();

    //otros metodos
    void ingresarDatosVendedor(DataVendedor data); //casos: a, 
    void ingresarDatosCliente(DataCliente data); //casos: a, 


    int sizeCol();
    bool estaUsuario(std::string); //casos: a, 

    void imprimirUsuarios(); //casos: a,
    
    void imprimirVendedores();
    void imprimirClientes();
    std::map<std::string, Usuario *> getUsuarios(); // a ver esto
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
    void listarNicknamesVendedores();

    Vendedor* buscarPorNombre(std::string vend);

    virtual ~ContUsuario(){}; //destructor 
    
};


#endif