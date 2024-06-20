#include "Producto.h"
#include "Promocion.h"

ProductosEnPromo::ProductosEnPromo(int cantidadMin, Producto* prod){
    this->cantidadMin=cantidadMin;
    this->producto=prod;
};
