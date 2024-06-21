#ifndef USUARIO
#define USUARIO
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "TFecha.h"
#include "Comentario.h"
#include "TNotificacion.h"


class Usuario{
    private:
        std::string nickname;
        std::string contrasena;
        TFecha fecha;
        std::map<int,Comentario*> comentarios;

    public: 
        Usuario(std::string,std::string,TFecha);
        void agregarComen(Comentario *);
        virtual~Usuario();
            virtual bool esVendedor() const { return false; };
            virtual void imprimirUsuario();
            void imprimirFecha();
            std::string getNickname();
            virtual bool esVendedor();
            virtual std::set<TComentario> ListarComentarios();
            virtual void sacarComentario(int)= 0;
            virtual void notificar(TNotificacion)=0;
            std::string getnickname();
            void setnickname(std::string);
            std::string getcontrasena();
            void setcontrasena(std::string);
            TFecha getfecha();
            void setfecha(TFecha);
        void imprimirComentarios();
        void eliminarRefCom(int);

};
#endif
