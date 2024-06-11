#ifndef DATACLIENTE
#define DATACLIENTE
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
//#include <sstream>
#include "DataUsuario.h"
#include "TDireccion.h"

class DataCliente: public DataUsuario{
private:
    TDireccion direccion;
    std::string ciudad;
public:
    DataCliente(std::string);
    std::string getRut();
};  

#endif

public 
jknkk
dffbfddfb
