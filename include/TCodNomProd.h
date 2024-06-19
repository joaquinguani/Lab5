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
    std::string codigo;
    std::string nombre;
public:
    //constructor
    TCodNomProd(std::string, std::string);
    //getters
    std::string getCodigo();
    std::string getNombre();
};

#endif