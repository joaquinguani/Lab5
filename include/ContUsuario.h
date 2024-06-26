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


class ContUsuario : public IContUsuario {
private:
    ContUsuario() = default;
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
    void listarVendedoresNoSubsXCliente(Cliente* cli);
    void listarVendSuscripto(Cliente* cli);
    std::map<std::string, Cliente*> getColClientes();
    std::map<std::string, Vendedor*> getColVendedores();
    Cliente* buscarClientePorNombre(std::string cli);
    Vendedor* buscarVendPorNombre(std::string vend);
    Usuario* buscarPorNombre(std::string);
    virtual ~ContUsuario(){}; //destructor 
    
};


#endif