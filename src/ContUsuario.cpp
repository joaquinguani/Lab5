#include "ContUsuario.h"
#include "DataCliente.h"
#include "DataVendedor.h" //puse estos includes que faltaban

ContUsuario::ContUsuario(){
};

void ContUsuario::ingresarDatosCliente(DataCliente data){
        Usuario* usuario = new Cliente(data);
        colUsuarios[data.getNickname()] = usuario;
        colClientes[data.getNickname()] = usuario; //decia ColCliente en singular
};

void ContUsuario::ingresarDatosVendedor(DataVendedor data){
        Usuario* usuario = new Vendedor(data);
        colUsuarios[data.getNickname()] = usuario;
        colVendedores[data.getNickname()]=usuario;
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

Vendedor* ContUsuario::buscarPorNombre(std::string vend){ //aca decia Usuario*, puse Vendedor*
        return colVendedores[vend];
};

void ContUsuario::imprimirClientes(){
        std::map<std::string, Usuario *>::iterator it;
        for (it= colUsuarios.begin(); it != colUsuarios.end(); ++it){
                Usuario* usr = it->second;
                if (!(usr->esVendedor())){
                        usr->imprimirUsuario();
                }
        }
};*/
