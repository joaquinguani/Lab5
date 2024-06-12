#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <map>
#include "Usuario.h"

class Comentario {
private:
    int ID;
    std::string texto;
    TFecha fecha;
    bool tienePadre;
    int IDPadre;
    int CodigoProd;
    std::map<int,Comentario*> respuestas;
    Usuario *usuario;
public:
    // Constructor
    Comentario(int id, std::string txt, TFecha fec, bool tPadre, int idPadre, int codProd);

    // Getters
    int getID();
    std::string getTexto()
    TFecha getFecha()
    bool getTienePadre()
    int getIDPadre()
    int getCodigoProd()

    // Setters
    void setID(int id)
    void setTexto(const std::string& txt)
    void setFecha(const TFecha& fec)
    void setTienePadre(bool tPadre)
    void setIDPadre(int idPadre)
    void setCodigoProd(int codProd)

    // Métodos
    void EliminoComentario(int idComentario)

    std::string GetTComentario()
};
