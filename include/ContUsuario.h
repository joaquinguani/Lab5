#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "IContUsuario.h"
#include "DataUsuario.h"
#include "Cliente.h"
#include "TNotificacion.h"


class ContUsuario: public IContUsuario {
private:
    std::set<Comentario*> comentarios;
    std::map<std::string,Usuario *> usuarios;
    
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
    void listarNicknamesVendedores();

    virtual ~ContUsuario(){}; //destructor 
};
