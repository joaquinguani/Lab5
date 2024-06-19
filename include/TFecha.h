#ifndef TFECHA
#define TFECHA
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>


class TFecha {
    private:
        int Dia, Mes, Anio;
        static TFecha* instanciaFecha;
        TFecha(); //constructor privado pq es singleton
        ~TFecha(); //destructor

    public:
        static TFecha * getInstanciaFecha();
        int getDia();
        int getMes();
        int getAnio();
        void modificarFecha(int dia, int mes, int anio);
        void imprimirFecha();
        bool mayoroIgual(TFecha); //va en el otro Tfecha
};

#endif