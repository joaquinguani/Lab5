#include "ContProducto.h"
#include "Promocion.h"
#include "TFechaActual.h"




ContProducto::ContProducto(){

};

std::set<Promocion*> ContProducto::listarPromosVigentes(){
    std::set<Promocion*> promos;
    TFechaActual* fecha;
    fecha = TFechaActual::getInstanciaFecha();
    //iterador que vaya por toda la coleccion de promociones
    std::map<std::string, Promocion *>::iterator it;
    for (it= colPromocion.begin(); it != colPromocion.end(); ++it){
        //va preguntando si la fechaVenc>TfechaActual, si es asi lo agrega a promos
        if (it->second->getFechaVenc().mayoroIgual(fecha)){
            promos.insert(it->second);
         }
               
    }
};


Promocion* ContProducto::buscarPromoPorNombre(std::string promo){ //aca decia Usuario*, puse Vendedor*
    return colPromocion[promo];
};


Producto* ContProducto::buscarProdPorNombre(std::string produ){
    return colProductos[produ];
}