#include "ContProducto.h"
#include "Promocion.h"



ContProducto::ContProducto(){

};


std::map<int, Producto*> ContProducto::getProductos() {
    return colProducto;}

std::set<Promocion*> ContProducto::listarPromosVigentes(){
    std::set<Promocion*> promos;
    //iterador que vaya por toda la coleccion de promociones
    std::map<std::string, Promocion *>::iterator it;
    for (it= colPromocion.begin(); it != colPromocion.end(); ++it){
        if (it->second->getFechaVenc().mayoroIgual(fecha)){
            promos.insert(it->second);
         }
               
        }
    //va preguntando si la fechaVenc<TfechaActual, si es asi lo agrega a promos

}