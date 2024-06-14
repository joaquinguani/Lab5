
#ifndef CONTUSUARIO
#define CONTUSUARIO
#include <set>
#include <string>
#include <vector>
#include <memory>
#include "IContUsuario.h"
#include "DataUsuario.h"
#include "Cliente.h"
#include "TNotificacion.h"


class ContUsuario: public IContUsuario {
private:
    std::set<Comentario*> comentarios;
    std::set<Comentario*> usuarios;
    
public:
    //constructor
    ContUsuario();

    //otros metodos
    void ingresarDatosUsuario(DataUsuario data);
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