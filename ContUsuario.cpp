#include "ContUsuario.h"

ContUsuario::ContUsuario(std::map<std::string, Usuario *> colUsuarios): colUsuarios(colUsuarios){
}

void ContUsuario::ingresarDatosCliente(DataCliente data){
        Cliente* usuario = new Cliente(data);
        colUsuarios[data.getNickname()] = usuario;
}

void ContUsuario::ingresarDatosVendedor(DataVendedor data){
        Vendedor* usuario = new Vendedor(data);
        colUsuarios[data.getNickname()] = usuario;
}

int ContUsuario::sizeCol(){
    return colUsuarios.size();
}
