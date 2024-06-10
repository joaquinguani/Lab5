#ifndef DATAUSUARIO
#define DATAUSUARIO
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
//#include <sstream>

class DataUsuario{
private:
    std::string nickname, contrasenia;
    TFecha fecha;
public:
    DataUsuario(std::string, std::string, TFecha);
    std::string getNickname();
    std::string getContrasenia();
    TFecha getFecha();
};  

#endif