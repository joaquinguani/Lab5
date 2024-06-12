#ifndef DATAVENDEDOR
#define DATAVENDEDOR
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
//#include <sstream>
#include "DataUsuario.h"
#include "TDireccion.h"

class DataVendedor: public DataUsuario{
private:
    std::string RUT;
public:
    DataVendedor(std::string , std::string , TFecha , std::string );
    std::string getRut();
};  

#endif