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
        int Dia, Mes, Ano;
    public:
        TFecha(int, int, int);
        int getDia();
        int getMes();
        int getAno();
};

#endif