#include "ContUsuario.h"
#include "DataCliente.h"
#include "DataVendedor.h" //puse estos includes que faltaban

ContUsuario::ContUsuario(){
        cantComen = 0;
};

void ContUsuario::sumarComentario(){
        ++cantComen;
}

ContUsuario* ContUsuario::getInstanciaContUsu() {
    if (instanciaContUsu == nullptr) {
        instanciaContUsu = new ContUsuario();
    }
    return instanciaContUsu;
}

int ContUsuario::getCantComen(){
        return cantComen
}

void ContUsuario::ingresarDatosCliente(DataCliente data){ //casos: a,
        Usuario* usuario = new Cliente(data);
        colUsuarios[data.getNickname()] = usuario;
        colClientes[data.getNickname()] = usuario; //decia ColCliente en singular
};

void ContUsuario::ingresarDatosVendedor(DataVendedor data){ //casos: a,
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


void ContUsuario::imprimirUsuarios(){ //casos:a,
        std::map<std::string, Usuario *>::iterator it;
        for (it= colUsuarios.begin(); it != colUsuarios.end(); ++it){
                Usuario* usr = it->second;
                usr->imprimirUsuario();
        }
}

void ContUsuario::imprimirVendedores(){
        std::map<std::string, Usuario *>::iterator it;
        for (it= colUsuarios.begin(); it != colUsuarios.end(); ++it){
                Usuario* usr = it->second;
                if (usr->esVendedor()){
                        usr->imprimirUsuario();
                }
        }
};

Vendedor* ContUsuario::buscarVendPorNombre(std::string vend){ //aca decia Usuario*, puse Vendedor*
        return ColVendedores[vend];
};


void ContUsuario::imprimirClientes(){
        std::map<std::string, Usuario *>::iterator it;
        for (it= colUsuarios.begin(); it != colUsuarios.end(); ++it){
                Usuario* usr = it->second;
                if (!(usr->esVendedor())){
                        usr->imprimirUsuario();
                }
        }
};


std::map<std::string, Vendedor*> ContUsuario::getColVendedores(){
        return this->colVendedores;
};

std::map<std::string, Cliente*> ContUsuario::getColClientes(){
        return this->colClientes;
};
