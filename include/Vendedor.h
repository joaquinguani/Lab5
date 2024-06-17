#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>

#include "Usuario.h"

#include "ISuscripciones.h"

class Vendedor:public Usuario{
    private:std::string RUT;
            std::set<ISuscripciones*> suscriptores;
            std::set<Producto*> productos;
    public:Vendedor(std::string RUT,std::set<std::string> suscriptores):Usuario(nickname,contrasena,fecha);
           ~Vendedor();
           virtual bool esVendedor();
           virtual void imprimirUsuario();
           virtual void imprimirFecha();
           std::string getRUT();
           void setRUT(std::string);
           std::set<std::string> getsuscriptores();
           void setsuscriptores(std::set<std::string>);
           bool estaSuscrito(std::string);
           void agregar(ISuscripciones *);
           void eliminar(ISuscripciones *);
           void notificar(ISuscripciones *);
};     
