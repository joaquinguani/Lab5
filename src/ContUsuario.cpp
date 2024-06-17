#include "ContUsuario.h"

ContUsuario::ContUsuario(std::map<std::string, Usuario *> colUsuarios): colUsuarios(colUsuarios){
};

void ContUsuario::ingresarDatosCliente(DataCliente data){
        Cliente* usuario = new Cliente(data);
        colUsuarios[data.getNickname()] = usuario;
};

void ContUsuario::ingresarDatosVendedor(DataVendedor data){
        Vendedor* usuario = new Vendedor(data);
        colUsuarios[data.getNickname()] = usuario;
};

int ContUsuario::sizeCol(){
    return colUsuarios.size();
};

(std::map<std::string, Usuario *>)* getColUsuarios(){
        return colUsuarios*
};


void ContUsuarios::imprimirUsuarios(){
        std::map<std::string, Usuario *>::iterator it;
        for (it= colUsuarios.begin(); it! = colUsuarios.end(); ++it){
                Usuario* usr = it->second;
                *usr.imprimirUsuario();
        }
};
