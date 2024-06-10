#ifndef TDIRECCION
#define TDIRECCION
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
//#include <sstream>

class TDireccion{
private:
    std::string calle;
    int numero;
public:
    TDireccion(std::string, int);
    std::string getCalle();
    int getNumero();
};  


#endif