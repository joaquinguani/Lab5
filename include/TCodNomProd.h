#ifndef TCODNOMPROD
#define TCODNOMPROD
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>

class TCodNomProd{
private:
    int codigo;
    std::string nombre;
public:
    //constructor
    TCodNomProd(int, std::string);
    //getters
    int getCodigo();
    std::string getNombre();
};

#endif