#include <cstdio>  // Para printf y scanf
#include <iostream> // Para std::cin y std::getline
#include <conio.h>  // Para _getch() en Windows
#include <map>
#include <cstdlib>
#include <set>

#include "Cliente.h"
#include "Usuario.h"
#include "Vendedor.h"
#include "DataUsuario.h"
#include "DataCliente.h"
#include "DataVendedor.h"
#include "ContProducto.h"
#include "ContUsuario.h"
#include "leer.h"
#include "Compra.h"
#include "TCategoria.h"

#include "ContUsuario.h"
#include "TFecha.h"

int main(){
//asigno cosas iniciales, creo controladores e interfaces, agrego colecciones (diccionarios e interfaces)
//capaz crear como variables los controladores solo, y que las colecciones esten dentro de ellos ???

std::set<Producto *> productos;
std::map<std::string,Vendedor *> vendedores;
  //std::map<std::string,Cliente *> clientes;
std::map<std::string,Vendedor *>::iterator iter;

ContUsuario contUsu = ContUsuario();
ContProducto contProdu = ContProducto(/*productosda*/);
TFecha* fechaSist=getInstanciaFecha();
std::string nick;
std::string Contrasena;
TFecha* fecha;
//int //codigoProducto = 0;

bool e = true;

while(e) {
    std::system("cls");
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
    printf("o: Modificar fecha\n");
    printf("p: Obtener fecha del sistema");
    printf("s: para ir al estado del mercado antes del anterior cambio\n");
    printf("x: para salir\n");

    char tecla = leerUnaTecla();
    //scanf(" %c", &tecla); 
    
    switch(tecla) {
        case 'a':{
            std::system("cls");
            printf("\nOpción 'a' seleccionada: Dar de alta a un usuario.\n");
            printf("\nPresione:\na: para ingresar un cliente\ncualquier otra tecla: para ingresar un vendedor\n");
            char venOcli = leerUnaTecla();
            printf("\nIngresar Nickname usuario\n");
            nick = leerCadena();
            //std::cin.ignore();
            //std::getline(std::cin, nick);
            if (!contUsu.estaUsuario(nick)){
                printf("\nError! Ese nombre de usuario ya existe");
                break;
            }
            printf("\nIngresar Contrasena usuario\n");
            Contrasena = leerCadena();
            //std::cin.ignore();
            //std::getline(std::cin, Contrasena);
            printf("\nIngresar ano de nacimiento de usuario\n");
            int ano = leerEntero();
            
            printf("\nIngresar mes de nacimiento de usuario\n");
            int mes = leerEntero();
            printf("\nIngresar dia de nacimiento de usuario\n");
            int dia = leerEntero();

            fecha = new TFecha(dia, mes, ano);
            if(venOcli == 'a'){
                printf("\nIngresar ciudad de cliente\n");
                std::string ciudad = leerCadena();
                printf("\nIngresar calle de cliente\n");
                std::string calle  = leerCadena();
                printf("\nIngresar numero de puerta de cliente\n");
                int numero = leerEntero();
                TDireccion* direccion = new TDireccion(calle, numero);
                DataCliente* data = new DataCliente(nick,Contrasena,*fecha,*direccion,ciudad);
                contUsu.ingresarDatosCliente(*data);
            }
            else{
                printf("\nIngresar RUT de vendedor\n");
                std::string RUT = leerCadena();
                std::system("cls");
                DataVendedor* data = new DataVendedor(nick,Contrasena,*fecha,RUT);
                contUsu.ingresarDatosVendedor(*data);
            }
        
            break;
        }
        case 'b':{
            std::system("cls");
            printf("\nListado de usuarios:\n");
            contUsu.imprimirUsuarios();
            printf("\nPrecione cualquier tecla para ir al menu\n");
            leerUnaTecla();
            //std::getline(std::cin,Contrasena);
            break;
        }

        case 'c':
            printf("\nOpción 'c' seleccionada: Alta de producto.\n");
            contUsu.imprimirVendedores();
            printf("\nIngrese el nickname del vendedor que desea seleccionar.\n");
            std::string nickVend;
            std::cin.ignore();
            std::getline(std::cin, nickVend);
            std::map<std::string,Vendedor *>::iterator iter;
            iter = vendedores.find(nickVend);
            if (iter == vendedores.end()) {
                printf("\nError: No existe un vendedor con dicho nickname\n");
            } else {
                std::string nomProd;
                int precioProd;
                int stockProd;
                std::string descProd;
                TCategoria catProd; 
                printf("\nIngrese el nombre del producto:\n");
                std::cin.ignore();
                std::getline(std::cin, nomProd);
                printf("\nIngrese el precio del producto:\n");
                std::cin.ignore();
                std::getline(std::cin, precioProd);
                printf("\nIngrese la cantidad en stock del producto:\n");
                std::cin.ignore();
                std::getline(std::cin, precioProd);
                printf("\nIngrese la descripcion del producto:\n");
                std::cin.ignore();
                std::getline(std::cin, descProd);
                printf("\nIngrese si el producto es ropa, electrodomesticos, otros:\n");
                std::cin.ignore();
                std::getline(std::cin, catProd);
                codigoProducto ++;
                Producto* nuevoProd = new Producto(codigoProducto, stockProd, precioProd, nomProd, descProd, catProd);
                iter->second->insertarProducto(nuevoProd);
            }    
            break;
        case 'd':
            printf("\nOpción 'd' seleccionada: Consultar producto.\n");
            contProdu.listarProductos();
            printf("\nIngrese el nombre del producto a seleccionar:\n");
            std::string nomProd;
            std::cin.ignore();
            std::getline(std::cin, nomProd);
            std::map<std::string,Producto *>::iterator iter;
            iter = colProductos.find(nomProd);
            printf("Codigo: %d\n Cantidad en stock: %d\n Precio: %d\n Nombre: %s\n Descripcion: %s\n Categoria: %s\n", iter->first, iter->second->getStock(), iter->second->getPrecio(), iter->second->getNombre(), iter->second->getDescripcion(), iter->second->getCategoria());
            break;
        case 'e':
           printf("\nOpción 'e' seleccionada: Crear promoción.\n");
            contUsu.imprimirVendedores();
            printf("\nIngrese el nombre del vendedor al que quiere asignar la promocion\n");
            std::string vend;
            std::cin.ignore();
            std::getline(std::cin, vend);   
            Vendedor* vnd=contUsu.buscarPorNombre(vend);
            vnd->imprimirProdsVendedorCodNom(); //esta mal el parametro(en la implementacion le pasas algo)
            int d,m,a,descu;
            std::string nom,descrip;
            std::cout << "Ingrese el nombre de la promoción: ";
            nom=leerCadena();
            std::cout << "Ingrese la descripción de la promoción: ";
            descrip=leerCadena();
            std::cout << "Ingrese la fecha de vencimiento (día mes anio): ";
            d=leerEntero();
            m=leerEntero();
            a=leerEntero();
            TFecha* fech=new TFecha(d,m,a);
            std::cout << "Ingrese el porcentaje de descuento que se va a aplicar en la promocion ";
            descu=leerEntero();
            Promocion* p=new Promocion(nom,descrip, );
            break;
        case 'f':
            printf("\nOpción 'f' seleccionada: Consultar promoción.\n");
            contProdu.listarPromosVigentes();
            printf("\nSi desea seleccionar una promoción ingrese 's', de lo contrario ingrese 'n'");
            char tec=leerUnaTecla();
            case 's':
            printf("\nIngrese el nombre la promocion\n");
            std::string nom;
            std::cin.ignore();
            std::getline(std::cin, nom);   
            Promocion* promo = contProdu.buscarPromoPorNombre(nom);
            promo->devolverDatosProdsPromo();
            break;
            case 'n':
            break;
        case 'g':
            printf("\nOpción 'g' seleccionada: Realizar compra.\n");
            contUsu.imprimirClientes();
            printf("\nIngrese el nickname del cliente que desea seleccionar.\n");
            std::string nickCliente;
            std::cin.ignore();
            std::getline(std::cin, nickCliente);
            auto iter = contUsu.getUsuarios().find(nickCliente);
            if (iter == contUsu.getUsuarios().end()) {
                printf("\nError: No existe un usuario con dicho nickname\n");
            else {
                Cliente* cliente = dynamic_cast<Cliente*>(iter->second);
                if (!cliente) {
                    printf("\nError: El usuario seleccionado no es un cliente\n");
            } else {
                Compra compra = new Compra(fechaActual, 0);
                contProdu.imprimirProductos();
                int agregar;
                printf("\nIngrese 0 si desea agregar productos a la compra, de lo contrario ingrese otro numero\n");
                std::cin.ignore();
                std::getline(std::cin, agregar);
                std::set<int> comprasPro;
                while (agregar == 0){
                    printf("\nIngrese el codigo del producto a agregar\n");
                    int codP;
                    std::cin.ignore();
                    std::getline(std::cin, codP);
                    std::map<std::string,Producto *>::iterator iterProd;
                    iterProd = contProdu.colProductos.find(codP);
                    if (iter == contProdu.colProductos.end()) {
                        printf("\nError: No existe un producto con dicho codigo\n");
                    } else {
                        if (comprasPro.find(codP) != comprasPro.end()) //if (comprasPro.contains(codP)) { //ver xq esta mal el contains
                            printf("\nEste producto ya fue ingresado\n");
                        } else {
                            printf("\nIngrese la cantidad que desea comprar\n");
                            int cantP;
                            std::cin.ignore();
                            std::getline(std::cin, cantP);
                            CompraProd* compraP = CompraProd(cantP, false, iterProd->second);
                            //con que se conecta compraprod????? VERIFICAR
                            //HAY QUE CONECTAR LOS PRODUCTOS CON LOS 
                            comprasPro.insert(codP);
                            float precio = iter->second->getPrecio();
                            precio = compra->aplicarDescuento(precio);
                            compra->sumarAlMonto(precio);
                        }
                    }
                    printf("\nIngrese 0 si desea agregar mas productos a la compra, de lo contrario ingrese otro numero\n");
                    std::cin.ignore();
                    std::getline(std::cin, agregar);
                }
                //mostrar compra

            }
                
            break;
        case 'h':
            printf("\nOpción 'h' seleccionada: Dejar comentario.\n");
            printf("\nIngrese el nickname del usuario que desea seleccionar\n");
            contUsu.imprimirUsuarios();
            std::string nickUsuario;
            std::cin.ignore();
            std::getline(std::cin, nickUsuario);
            std::map<std::string,Usuario *>::iterator iteru = usuarios.find(nickUsuario);
            if (iteru == usuarios.end()) {
                printf("\nError: No existe un usuario con dicho nickname\n");
            } else {
              printf("\nAhora ingrese el codigo identificador del producto que desea seleccionar\n");
              // se supone que la funcion esa con TCodNomProd (hay que hacer el .cpp) hace eso
              contProdu.listarProductos();
              std::string codigoprod;
              std::cin.ignore();
              std::getline(std::cin, codigoprod);
              std::map<std::string,Producto *>::iterator iterP = productos.find(codigoprod); //hay que hacerlos map en vezde set
              //que diga si puso mal el codigo, else:
              // "desea comentario nuevo o respuesta?"
              // case N : ingrese el texto de su comentario: ____ y ahi lo creas
              // case R: falta un mostrarComDeProd en el contProductos, pero con eso los muestra, "elija uno", selecciona etc
              // y ahi si ingrese el texto del comentario
              

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
        case 'o':
            printf("\nOpción 'o' seleccionada: Modificar fecha.\n");
            printf("\nIngresar el anio nuevo\n");
            int anio;
            scanf("%d", &anio);
            printf("\nIngresar el mes nuevo\n");
            int mes;
            scanf("%d", &mes);
            printf("\nIngresar el dia nuevo\n");
            int dia;
            scanf("%d", &dia);
            fecha->modificarFecha(dia, mes, anio);
            break;
       case 'p':
            printf("\nOpcion 'p' seleccionada:Obtener fecha del sistema");
            printf("\nLa fecha actual del sistema es");
            fechaSist->imprimirFecha();
            break;
        case 's':
        
            printf("\nOpción 's' seleccionada: Volver al estado anterior del mercado.\n");
            // Aquí iría el código para volver al estado anterior del mercado
            break;
        case 'x':{
            printf("\nOpción 'x' seleccionada: Salir del programa.\n");
            e=false;
            break;}
        default:{
            printf("\nTecla no válida. Por favor, seleccione una opción válida.\n");
            break;}
    }

};
};
};

