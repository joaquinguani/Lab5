/*#ifndef TCOMENTARIO
#define TCOMENTARIO
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "TFecha.h"

class TComentario {
    private:
        int id;
        std::string texto;
        TFecha* fecha;
    public:
        TComentario(int, std::string, TFecha*);
        std::string getTexto();
        TFecha getFecha();
        int getID();
};

#endif*/