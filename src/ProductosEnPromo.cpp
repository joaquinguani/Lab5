#include "Producto.h"
#include "Promocion.h"

ProductosEnPromo::ProductosEnPromo(Producto* producto,int cantMin){
    this->producto=producto;
    this->cantidadMin=cantMin;

};

int ProductosEnPromo::getCantidadMin() {
    return cantidadMin;
};
