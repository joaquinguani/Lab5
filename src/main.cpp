#include <cstdio>  // Para printf y scanf
#include <iostream> // Para std::cin y std::getline
#include <conio.h>  // Para _getch() en Windows
#include <map>
#include "Cliente.h"
#include "Usuario.h"
#include "Vendedor.h"
#include "DataUsuario.h"
#include "DataCliente.h"
#include "DataVendedor.h"
#include "ContUsuario.h"
#include "ContProductos.h"


int main()
{
//asigno cosas iniciales, creo controladores e interfaces, agrego colecciones (diccionarios e interfaces)

std::map<std::string,Usuario *> usuarios;
std::set<Producto*> productos;

ContUsuario contUsu = ContUsuario();
ContProducto contProdu = ContProducto();
std::string nick;
std::string Contrasena;
bool PriemeraVez;

TFecha* fecha;
int codigoProducto;
codigoProducto = 0;

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
            printf("\nPresione:\na: para ingresar un cliente\ncualquier otra tecla: para ingresar un vendedor\n");
            char venOcli;
            scanf(" %c", &venOcli); 
            nick = "holaholhola";
            printf("\nIngresar Nickname usuario");
            std::cin.ignore();
            std::getline(std::cin, nick);
            if (usuarios.find(nick) != usuarios.end()){
                printf("\nError! Ese nombre de usuario ya existe");
                break;
            }
            printf("\nIngresar Contrasena usuario\n");
            std::cin.ignore();
            std::getline(std::cin, Contrasena);
            printf("\nIngresar ano de nacimiento de usuario\n");
            int ano;
            scanf("%d", &ano);
            printf("\nIngresar mes de nacimiento de usuario\n");
            int mes;
            scanf("%d", &mes);
            printf("\nIngresar dia de nacimiento de usuario\n");
            int dia;
            scanf("%d", &dia);
            fecha = new TFecha(dia, mes, ano);
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
                DataCliente* data = new DataCliente(nick,Contrasena,*fecha,*direccion,ciudad);
                contUsu.ingresarDatosCliente(*data);
            }
            else{
                printf("\nIngresar RUT de vendedor\n");
                std::string RUT;
                std::cin.ignore();
                std::getline(std::cin, RUT);
                DataVendedor* data = new DataVendedor(nick,Contrasena,*fecha,RUT);
                contUsu.ingresarDatosVendedor(*data);
            }
            
            break;
        case 'b':
            printf("\nOpción 'b' seleccionada: Listado de usuarios.\n");
            colUsuarios.imprimirUsuarios();
            break;
        case 'c':
            printf("\nOpción 'c' seleccionada: Alta de producto.\n");
            contUsu.listarNicknamesVendedores();
            printf("\nIngrese el nickname del vendedor que desea seleccionar.\n");
            std::string nickVend;
            scanf("%s", nickVend);
            std::string nomProd;
            int precioProd;
            int stockProd;
            std::string descProd;
            std::string catProd; //como hacemos lo de enumerado
            printf("\nIngrese el nombre del producto:\n");
            scanf("%s", nomProd);
            printf("\nIngrese el precio del producto:\n");
            scanf("%d", precioProd);
            printf("\nIngrese la cantidad en stock del producto:\n");
            scanf("%d", precioProd);
            printf("\nIngrese la descripcion del producto:\n");
            scanf("%s", descProd);
            printf("\nIngrese si el producto es ropa, electrodomesticos, otros:\n");
            scanf("%s", catProd); //PREGUNTARRRRRRRR
            codigoProducto ++;
            Producto* nuevoProd = new Producto(codigoProducto, stockProd, precioProd, nomProd, descProd, catProd);
            /*auto it = usuarios.find(nickVend);
            if (it != usuarios.end()) {
            Vendedor* vendedor = dynamic_cast<Vendedor*>(it->second);
            vendedor->productos.insert(nuevoProd);}*/
            //QUEREMOS VER COMO AGARRAR EL VENDEDOR Y AGREGAR EL PRODUCTO A LA LISTA DE PRODUCTOS DEL MISMO AYUDAAAAA
            break;
        case 'd':
            printf("\nOpción 'd' seleccionada: Consultar producto.\n");
            contProdu.listarProductos();
            printf("\nIngrese el nombre del producto a seleccionar:\n");
            scanf("%s", nomProd);
            //Producto produ = productos.find(nomProd);
            printf("Codigo: %d\n Cantidad en stock: %d\n Precio: %d\n Nombre: %s\n Descripcion: %s\n Categoria: %s\n", produ.getCodigo(), produ.getStock(), produ.getPrecio(), produ.getNombre(), produ.getDescripcion(), produ.getCategoria());
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


