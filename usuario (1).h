#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include <sstream>

class Usuario{
    private:std::string nickname;
            std::string contrasena;
            TFecha fecha;
    public: Usuario(std::string,std::string,TFecha);
            virtual ~Usuario();
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