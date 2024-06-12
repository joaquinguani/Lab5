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
    private:std::string nickname;
            std::string contrasena;
            TFecha fecha;
    public: Usuario(std::string,std::string,TFecha);
            virtual ~Usuario();
            virtual void imprimirUsuario();
            virtual void imprimirFecha();
            virtual std::set<TComentario> ListarComentarios()=0;
            virtual void sacarComentario(int)= 0;
            virtual void notificar(TNotificacion)=0;
            std::string getnickname();
            void setnickname(std::string);
            std::string getcontrasena();
            void setcontrasena(std::string);
            TFecha getfecha();
            void setfecha(TFecha);
};