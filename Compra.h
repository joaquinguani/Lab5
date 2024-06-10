#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>


class Compra {
private:
    TFecha fecha;
    int MontoFinal;
    std::vector<std::tuple<Producto, int, int>> productos;

public:
    // Constructor
    Compra(TFecha f, int monto)


    // Getters
    TFecha getFecha()
    int getMontoFinal()

    // Setters
    void setFecha(const TFecha& f)
    void setMontoFinal(int monto)

    // Métodos
    void agregarProdACompra(Producto prod, int cod, int cant) 

    void sumarAlMonto(int pre)
};
