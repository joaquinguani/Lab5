#ifndef DATAUSUARIO
#define DATAUSUARIO
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include "TFecha.h"

//#include <sstream>

class DataUsuario{
private:
    std::string nickname;
    std::string contraseña;
    TFecha fecha;
public:
    DataUsuario(std::string, std::string, TFecha);
    std::string getNickname();
    std::string getContraseña();
    TFecha getFecha();
};  

#endif