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
        ~TFecha(); //destructor

    public:
        TFecha(int,int,int);
        int getDia();
        int getMes();
        int getAnio();
        void modificarFecha(int dia, int mes, int anio);
        void imprimirFecha();
        bool mayoroIgual(TFecha); //va en el otro Tfecha
};

#endif