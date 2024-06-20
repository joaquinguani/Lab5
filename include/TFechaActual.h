#ifndef FechaSist
#define FechaSist
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>

class TFechaActual {
    private:
        int Dia, Mes, Anio;
        static TFechaActual * instanciaFecha;
        TFechaActual(int dia, int mes, int anio); //constructor privado pq es singleton
        ~TFechaActual(); //destructor

    public:
        static TFechaActual* getInstanciaFecha(int dia = 24, int mes = 6, int anio = 2024);
        int getDia();
        int getMes();
        int getAnio();
        void modificarFecha(int dia, int mes, int anio);
        void imprimirFecha();
};

#endif