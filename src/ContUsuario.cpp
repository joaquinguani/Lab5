#include "ContUsuario.h"

ContUsuario::ContUsuario(){
};

void ContUsuario::ingresarDatosCliente(DataCliente data){
        Usuario* usuario = new Cliente(data);
        colUsuarios[data.getNickname()] = usuario;
};

void ContUsuario::ingresarDatosVendedor(DataVendedor data){
        Usuario* usuario = new Vendedor(data);
        colUsuarios[data.getNickname()] = usuario;
};

int ContUsuario::sizeCol(){
    return colUsuarios.size();
};

bool ContUsuario::estaUsuario(std::string nick){
        return colUsuarios[nick] == NULL;
        
}


void ContUsuario::imprimirUsuarios(){
        std::map<std::string, Usuario *>::iterator it;
        for (it= colUsuarios.begin(); it != colUsuarios.end(); ++it){
                Usuario* usr = it->second;
                usr->imprimirUsuario();
        }
};
/*
void ContUsuario::imprimirVendedores(){
        std::map<std::string, Usuario *>::iterator it;
        for (it= colUsuarios.begin(); it != colUsuarios.end(); ++it){
                Usuario* usr = it->second;
                if (usr->esVendedor()){
                        usr->imprimirUsuario();
                }
        }
};


*/