/*#ifndef TPRODSENPROMO
#define TPRODSENPROMO
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
//#include <sstream>
#include "Producto.h"
#include "TVendedor.h"

class TProdsEnPromo{
private:
    std::set<Producto> productos;
    TVendedor infoVend;
public:
    //constructor
    TProdsEnPromo(std::set<Producto>, TVendedor);
    //getters
    std::set<Producto> getProductos();
    TVendedor getInfoVend();
};

#endif
*/

//lo usamos? creo que no, seria de consultar promocion