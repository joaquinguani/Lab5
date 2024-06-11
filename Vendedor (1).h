#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "usuario.h"

class Vendedor:public Usuario{
    private:std::string RUT;
            std::set<std::string> suscriptores;
            std::set<std::string>ISuscripciones* suscriptores;
    public:Vendedor(std::string RUT,std::set<std::string> suscriptores):Usuario(nickname,contrasena,fecha);
           ~Vendedor();
           std::string getRUT();
           void setRUT(std::string);
           std::set<std::string> getsuscriptores();
           void setsuscriptores(std::set<std::string>);
           bool estaSuscrito(std::string);
           void agregar(ISuscripciones*);
           void eliminar(ISuscripciones*);
           void notificar(ISuscripciones*);
};     
