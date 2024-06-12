#include <cstdio>  // Para printf y scanf
#include <iostream> // Para std::cin y std::getline
#include <conio.h>  // Para _getch() en Windows
#include <map>
#include "ContUsuario.h"
#include "Usuario.h"
#include "Cliente.h"
#include "Vendedor.h"
#include "DataUsuario.h"
#include "DataCliente.h"
#include "DataVendedor.h"


int main()
{
//asigno cosas iniciales, creo controladores e interfaces, agrego colecciones (diccionarios e interfaces)

std::map<std::string,Usuario *> usuarios;

ContUsuario contUsu = ContUsuario(usuarios);
std::string nick;
std::string Contraseña;
bool PriemeraVez;
TFecha* fecha;


bool e = true;
while(e) {

    printf("      **MERCADO FING**\n");
    printf("            //MENU//\n\n");
    int TamañoColUsuarios = contUsu.sizeCol();
    printf("Cantidad usuarios: %d -----> C: %d,  V: %d (falta contar vendedor y cliete por separado)\n\n", TamañoColUsuarios, TamañoColUsuarios, TamañoColUsuarios);
    printf("precione:\n");
    printf("a: para dar de alta a un usuario\n");
    printf("b: Listado de usuarios\n");
    printf("c: Alta de producto\n");
    printf("d: Consultar producto\n");
    printf("e: Crear promoción\n");
    printf("f: Consultar promoción\n");
    printf("g: Realizar compra\n");
    printf("h: Dejar comentario\n");
    printf("i: Eliminar comentario\n");
    printf("j: Enviar producto\n");
    printf("k: Expediente de Usuario\n");
    printf("l: Suscribirse a notificaciones\n");
    printf("m: Consulta de notificaciones\n");
    printf("n: Eliminar suscripciones\n");
    printf("s: para ir al estado del mercado antes del anterior cambio\n");
    printf("x: para salir\n");

    char tecla;
    scanf(" %c", &tecla); 
    
    switch(tecla) {
        case 'a':
            printf("\nOpción 'a' seleccionada: Dar de alta a un usuario.\n");
            printf("\nPrecione:\na: para ingresar un cliente\ncualquier otra tecla: para ingresar un vendedor\n");
            char venOcli;
            scanf(" %c", &venOcli); 
            nick = "holaholhola";
            PriemeraVez = true;
            while ((usuarios.find(nick) != usuarios.end())|| (PriemeraVez)){
                if(PriemeraVez){printf("\nIngresar Nickname usuario");}
                else{printf("\nEse Nickname ya existe, ingrese otro");}
                std::cin.ignore();
                std::getline(std::cin, nick);
                PriemeraVez = false;
            }
            printf("\nIngresar Contraseña usuario\n");
            std::cin.ignore();
            std::getline(std::cin, Contraseña);
            printf("\nIngresar año de nacimiento de usuario\n");
            int año;
            scanf("%d", &año);
            printf("\nIngresar mes de nacimiento de usuario\n");
            int mes;
            scanf("%d", &mes);
            printf("\nIngresar dia de nacimiento de usuario\n");
            int dia;
            scanf("%d", &dia);
            fecha = new TFecha(dia, mes, año);
            if(venOcli == 'a'){
                printf("\nIngresar ciudad de cliente\n");
                std::string ciudad;
                std::cin.ignore();
                std::getline(std::cin, ciudad);
                printf("\nIngresar calle de cliente\n");
                std::string calle;
                std::cin.ignore();
                std::getline(std::cin, calle);
                printf("\nIngresar numero de puerta de cliente\n");
                int numero;
                scanf("%d",&numero);
                TDireccion* direccion = new TDireccion(calle, numero);
                DataCliente* data = new DataCliente(nick,Contraseña,*fecha,*direccion,ciudad);
                contUsu.ingresarDatosCliente(*data);
            }
            else{
                printf("\nIngresar RUT de vendedor\n");
                std::string RUT;
                std::cin.ignore();
                std::getline(std::cin, RUT);
                DataVendedor* data = new DataVendedor(nick,Contraseña,*fecha,RUT);
                contUsu.ingresarDatosVendedor(*data);
            }
            
            break;
        case 'b':
            printf("\nOpción 'b' seleccionada: Listado de usuarios.\n");
            // Aquí iría el código para listar usuarios
            break;
        case 'c':
            printf("\nOpción 'c' seleccionada: Alta de producto.\n");
            // Aquí iría el código para dar de alta un producto
            break;
        case 'd':
            printf("\nOpción 'd' seleccionada: Consultar producto.\n");
            // Aquí iría el código para consultar un producto
            break;
        case 'e':
            printf("\nOpción 'e' seleccionada: Crear promoción.\n");
            // Aquí iría el código para crear una promoción
            break;
        case 'f':
            printf("\nOpción 'f' seleccionada: Consultar promoción.\n");
            // Aquí iría el código para consultar una promoción
            break;
        case 'g':
            printf("\nOpción 'g' seleccionada: Realizar compra.\n");
            // Aquí iría el código para realizar una compra
            break;
        case 'h':
            printf("\nOpción 'h' seleccionada: Dejar comentario.\n");
            // Aquí iría el código para dejar un comentario
            break;
        case 'i':
            printf("\nOpción 'i' seleccionada: Eliminar comentario.\n");
            // Aquí iría el código para eliminar un comentario
            break;
        case 'j':
            printf("\nOpción 'j' seleccionada: Enviar producto.\n");
            // Aquí iría el código para enviar un producto
            break;
        case 'k':
            printf("\nOpción 'k' seleccionada: Expediente de Usuario.\n");
            // Aquí iría el código para gestionar el expediente de un usuario
            break;
        case 'l':
            printf("\nOpción 'l' seleccionada: Suscribirse a notificaciones.\n");
            // Aquí iría el código para suscribirse a notificaciones
            break;
        case 'm':
            printf("\nOpción 'm' seleccionada: Consulta de notificaciones.\n");
            // Aquí iría el código para consultar notificaciones
            break;
        case 'n':
            printf("\nOpción 'n' seleccionada: Eliminar suscripciones.\n");
            // Aquí iría el código para eliminar suscripciones
            break;
        case 's':
            printf("\nOpción 's' seleccionada: Volver al estado anterior del mercado.\n");
            // Aquí iría el código para volver al estado anterior del mercado
            break;
        case 'x':
            printf("\nOpción 'x' seleccionada: Salir del programa.\n");
            e=false;
            break;
        default:
            printf("\nTecla no válida. Por favor, seleccione una opción válida.\n");
            break;
    }

}


}

