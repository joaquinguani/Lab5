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
    ContUsuario();
    static ContUsuario * instanciaContUsu;

    std::map<int, Comentario *> colComentario;
    std::map<std::string, Usuario *> colUsuarios;
    std::map<std::string, Vendedor*> colVendedores; 
    std::map<std::string, Cliente*> colClientes;
    int cantComen;
    
public:
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
    Vendedor* findVend(std::string);
    bool esVaciaVendedor();
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
    std::set<std::string> listarVendSuscripto(std::string nickC);
    void eliminarSuscripciones();
    void listarNicknamesVendedores();
    std::map<std::string, Cliente*> getColClientes();
    std::map<std::string, Vendedor*> getColVendedores();
    Cliente* buscarClientePorNombre(std::string cli);
    Vendedor* buscarPorNombre(std::string vend);

    virtual ~ContUsuario(){}; //destructor 
    
};


#endif