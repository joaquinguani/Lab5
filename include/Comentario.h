#ifndef COMENTARIO
#define COMENTARIO
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include <map>
#include "Usuario.h"
#include "Producto.h"
#include "TFecha.h"

class Comentario {
private:
    int ID;
    std::string texto;
    TFecha fecha;
    bool tieneComPadre;
    Comentario* ComenPadre;
    Producto* ProdPadre;
    std::map<int,Comentario*> respuestas;
    Usuario* usuario;
public:
    // Constructor
    Comentario(std::string txt);
    void CrearHijo(std::string txt,Usuario* usu);
    // Getters
    int getID();
    std::string getTexto();
    TFecha getFecha();
    bool getTieneComPadre();
    int getCodigoProd();
    Comentario* getComPadre();
    Producto* getProducto();

    // Setters
    void setID(int id);
    void setTexto(const std::string& txt);
    void setFecha(const TFecha& fec);
    void setTienePadre(bool tPadre);
    void setIDPadre(int idPadre);
    void setCodigoProd(int codProd);
    void setUsuario(Usuario* usu);
    void setProdPadre(Producto* prod);

    // Métodos
    void EliminoComentario(int idComentario);
    void imprimirComentario();
    void imprimirComenYHijos();
    void eliminarRefCom(int)
    std::string GetTComentario();
    void EliminoComentarioYHijos();
    ~Comentario();
};

#endif
