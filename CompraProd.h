#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
//#include <sstream>

class CompraProd{
private:
    int cantidad;
    bool enviado;
public:
    //constructor
    CompraProd();

    //metodos de acceso
    int getCantidad();
    bool getEnviado();

    //destructor
    virtual ~CompraProd(){}; 
};