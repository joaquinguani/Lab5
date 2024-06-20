#ifndef USUARIO
#define USUARIO
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "TFecha.h"
#include "TComentario.h"
#include "TNotificacion.h"


class Usuario{
    private:
        std::string nickname;
        std::string contrasena;
        TFecha fecha;
    public: 
        Usuario(std::string,std::string,TFecha);

        std::string getNickname();   
        std::string getcontrasena();
        TFecha getfecha();

        void setnickname(std::string);
        void setcontrasena(std::string);
        void setfecha(TFecha);

        virtual~Usuario();
        
        virtual void imprimirUsuario();
        void imprimirFecha();
        virtual bool esVendedor();
        virtual std::set<TComentario> ListarComentarios();
        virtual void sacarComentario(int)= 0;
        virtual void notificar(TNotificacion)=0;

};
#endif
