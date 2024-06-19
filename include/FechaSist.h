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
        static TFecha* instanciaFecha;
        ThhFecha(); //constructor privado pq es singleton
        ~TFecha(); //destructor

    public:
        static TFecha * getInstanciaFecha();
        int getDia();
        int getMes();
        int getAnio();
        void modificarFecha(int dia, int mes, int anio);
        void imprimirFecha();
};

#endif