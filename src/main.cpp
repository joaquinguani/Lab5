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
#include "ContUsuario.h"
#include "leer.h"
#include "Compra.h"
#include "TCategoria.h"
#include "ContProducto.h"
#include "ContUsuario.h"
#include "TFecha.h"
#include "Producto.h"

int main(){
//asigno cosas iniciales, creo controladores e interfaces, agrego colecciones (diccionarios e interfaces)


std::map<std::string,Vendedor *> vendedores;
  //std::map<std::string,Cliente *> clientes;
std::map<std::string,Vendedor *>::iterator iter;

ContUsuario contUsu = ContUsuario();

ContProducto contProdu = ContProducto();
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
    printf("a: para acceder a los casos de uso\n");
    printf("b: para acceder a los casos de prueba predeterminados\n");
    printf("x: para salir\n");

    char tec = leerUnaTecla();
    switch(tec) {
    case 'a':{
    std::system("cls");
    printf(" --CASOS DE USO--\n\n");
    printf("precione:\n\n");
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
            contUsu.imprimirVendedores(); //tiene que imprimir solo los nicknames en realidad
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
                static int codigoProducto = 0;
                Producto* nuevoProd = new Producto(++codigoProducto, stockProd, precioProd, nomProd, descProd, catProd);
                iter->second->insertarProducto(nuevoProd);

                //faltaria agregarlo al mapa de productos
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
            iter = colProducto.find(nomProd);
            printf("Codigo: %d\n Cantidad en stock: %d\n Precio: %d\n Nombre: %s\n Descripcion: %s\n Categoria: %s\n", iter->first, iter->second->getStock(), iter->second->getPrecio(), iter->second->getNombre(), iter->second->getDescripcion(), iter->second->getCategoria());
            break;
        case 'e':
            printf("\nOpción 'e' seleccionada: Crear promoción.\n");
            std::string nom;
            std::cout << "Ingrese el nombre de la promoción: ";
            nom=leerCadena(); 
            std::string descrip;
            std::cout << "Ingrese la descripción de la promoción: ";
            descrip=leerCadena();
            int d,m,a;
            std::cout << "Ingrese la fecha de vencimiento (día mes anio): ";
            d=leerEntero();
            m=leerEntero();
            a=leerEntero();
            TFecha* fech=new TFecha(d,m,a);
            int descu;
            std::cout << "Ingrese el porcentaje de descuento que se va a aplicar en la promocion ";
            descu=leerEntero();
            contUsu.imprimirVendedores();
            printf("\nIngrese el nombre del vendedor al que quiere asignar la promocion.\n");
            std::string vend;
            vend=leerCadena();
            Vendedor* vnd=contUsu.buscarPorNombre(vend);
            vnd->imprimirProdsVendedorCodNom();
            Promocion* p=new Promocion(nom,descrip,fech,descu); //creamos la promo y ahora pedimos que liste por codigo los productos a agregar
            bool seguir=true;
            while(seguir){
                printf("\nIngrese el codigo de un producto que desea agregar a la promocion.\n");
                int c=leerEntero();
                Producto* prod=contProdu->buscarproducto(c);
                printf("\nIngrese la cantidad minima de este producto para aplicar la promocion.\n");
                int cantmin=leerEntero();
                p->agregarProdAPromo(prod);
                //asociar el producto a la promo
                prod->setPromo(p);
                p->agregarProdAPromoCantMin(prod,cantmin);
                printf("\n¿Desea seguir agregando productos? (s/n): .\n");
                char respuesta;
                respuesta=leerUnaTecla();
                seguir = (respuesta == 's' || respuesta == 'S');
                //falta lo de suscripciones lo demas esta creo
            };
            //damos de alta la promocion, para eso la almacenamos en el set de todas las promociones
            contProdu->colPromocion[nom]=p;
            break;
        case 'f':
            printf("\nOpción 'f' seleccionada: Consultar promoción.\n");
            contProdu.listarPromosVigentes();
            
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
                    printf("\nIngrese el codigo del producto a agregar\n");
                    int codP;
                    std::cin.ignore();
                    std::getline(std::cin, codP);
                    std::map<std::string,Producto *>::iterator iterProd;
                    iterProd = contProdu.colProductos.find(codP);
                    if (iter == contProdu.colProductos.end()) {
                    std::map<std::string,Producto *>::iterator iterProd;
                    iterProd = contProdu.colProductos.find(codP);
                    if (iter == contProdu.colProductos.end()) {
                        printf("\nError: No existe un producto con dicho codigo\n");
                    } else {
                        if (comprasPro.find(codP) != comprasPro.end()) //if (comprasPro.contains(codP)) { //ver xq esta mal el contains
                        if (comprasPro.find(codP) != comprasPro.end()) //if (comprasPro.contains(codP)) { //ver xq esta mal el contains
                            printf("\nEste producto ya fue ingresado\n");
                        } else {
                            printf("\nIngrese la cantidad que desea comprar\n");
                            int cantP;
                            std::cin.ignore();
                            std::getline(std::cin, cantP);
                            CompraProd* compraP = CompraProd(cantP, false, iterProd->second);
                            CompraProd* compraP = CompraProd(cantP, false, iterProd->second);
                            //con que se conecta compraprod????? VERIFICAR
                            //HAY QUE CONECTAR LOS PRODUCTOS CON LOS 
                            comprasPro.insert(codP);
                            float precio = iter->second->getPrecio();
                            precio = compra->aplicarDescuento(precio);
                            compra->sumarAlMonto(precio);
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
            auto iteru = contUsu.getUsuarios().find(nickUsuario);
            if (iteru == contUsu.getUsuarios().end()) {
                printf("\nError: No existe un usuario con dicho nickname\n");
            } else {
              printf("\nAhora ingrese el codigo identificador del producto que desea seleccionar\n");
              // se supone que la funcion esa con TCodNomProd (hay que hacer el .cpp) hace eso
              contProdu.listarProductos();
              std::string codigoprod;
              std::cin.ignore();
              std::getline(std::cin, codigoprod);
              auto iterP = contProdu.getProductos().find(codigoprod);
              if (iterP == contProdu.getProductos().end()) {
                    printf("\nError: No existe un producto con dicho codigo\n");
                } else {
                    printf("\n¿Desea hacer un comentario nuevo (N) o una respuesta (R)?\n");
                    char tipoComentario;
                    std::cin.ignore();
                    std::getline(std::cin, tipoComentario);
                    if (tipoComentario == 'N' || tipoComentario == 'n') {
                        printf("\nIngrese el texto de su comentario:\n");
                        std::string textoComentario;
                        std::cin.ignore();
                        std::getline(std::cin, textoComentario);
                     // Crear un nuevo comentario
                        static int idComentario = 1; // ID único para cada comentario, static se mantiene en la memoria asi se va sumando ese numero
                       //guani aca fijate como es//
                       //no se porque comentario tiene tanta cosa//
                        //esta mal esto: Comentario nuevoComentario(idComentario++, textoComentario, fechaSist);
                        iterProd->second->agregarComentario(nuevoComentario);
                        printf("\nComentario agregado exitosamente.\n");
                    } else if (tipoComentario == 'R' || tipoComentario == 'r') {
                        printf("\nComentarios del producto:\n");
                        iterProd->second->mostrarComDeProd(); //en el contprod iria esa funcion
                        printf("\nElija el numero del comentario al que desea responder:\n");
                        int numComentario;
                        std::cin.ignore();
                        std::getline(std::cin, numComentario);
                        if (numComentario > 0 && numComentario <= iterProd->second->comentarios.size()) {
                            printf("\nIngrese el texto de su respuesta:\n");
                            std::string textoRespuesta;
                            std::cin.ignore();
                            std::getline(std::cin, textoRespuesta);


            break;
        case 'i':
            printf("\nOpción 'i' seleccionada: Eliminar comentario.\n");
            // Aquí iría el código para eliminar un comentario
            break;
        case 'j':
            printf("\nOpción 'j' seleccionada: Enviar producto.\n");
            contUsu.imprimirVendedores(); //solo los nicknames
            printf("\nIngrese el nombre del vendedor que quiere seleccionar\n");
            std::string vend;
            std::cin.ignore();
            std::getline(std::cin, vend);   
            Vendedor* vnd=contUsu.buscarPorNombre(vend);
            //
            vnd->imprimirProdsConCompraPendDeEnvio();
            printf("\nIngrese el nombre del producto que quiere seleccionar\n");
            std::string prod;
            std::cin.ignore();
            std::getline(std::cin, prod);
            Producto* produ = contProdu.buscarProdPorNombre(prod);
            //colProdu.imprimircomprasConProductoPendiente
            ///busca en la coleccion de compra uno por uno si tiene el producto
            ////iterador, en una compra busca el producto en su set de productos
            ///si lo tiene imprime nickdelcliente y la fecha
            //seleccionar uno de los elementos
            //marcar como enviado el producto


            
            //seleccionar producto y que quede en variable
            //listar compras con ese producto con envio pendiente
            ///ir buscando en la coleccion de compra el producto
            ///imprimir la compra (el nick del cliente y la fecha de compra)
            //seleccionar una compra
            //guardarla en variable 
            //marcar como enviado en compra prod con 
            //prod--compra--compraprod.enviado
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
            break;}
        default:{
            //esto no esta bien, hay que hacer que se mantenga en el switch con otro bool
            printf("\nTecla no válida. Por favor, seleccione una opción válida.\n");
            break;}
    }
    break;}
    case 'b':{
        std::system("cls");
        printf(" --CASOS DE PRUEBA--\n\n");
        printf("precione:\n\n");
        printf("a: caso usuario\n");
        printf("x: para volver al menu\n");
        char casoPrueba = leerUnaTecla();
        switch(casoPrueba) {
            case 'a':{
            simulatedInputs = {
                // Usuario 1
                "a", 
                "a",                // Opción 'a' seleccionada: Dar de alta a un usuario.
                "v",                // Tecla para seleccionar 'v' (vendedor).
                "ana23",            // Nickname
                "qwer1234",         // Contraseña
                "1988",             // Año
                "05",               // Mes
                "15",               // Día
                "212345678001",     // RUT

                // Usuario 2
                "a", 
                "a",                // Opción 'a' seleccionada: Dar de alta a un usuario.
                "v",                // Tecla para seleccionar 'v' (vendedor).
                "carlos78",         // Nickname
                "asdfghj",          // Contraseña
                "1986",             // Año
                "06",               // Mes
                "18",               // Día
                "356789012345",     // RUT

                // Usuario 3
                "a", 
                "a",                // Opción 'a' seleccionada: Dar de alta a un usuario.
                "v",                // Tecla para seleccionar 'v' (vendedor).
                "diegom",           // Nickname
                "zxcvbn",           // Contraseña
                "1993",             // Año
                "07",               // Mes
                "28",               // Día
                "190123456789",     // RUT

                // Usuario 4
                "a", 
                "a",                // Opción 'a' seleccionada: Dar de alta a un usuario.
                "a",                // Tecla para seleccionar 'a' (cliente).
                "juan87",           // Nickname
                "1qaz2wsx",         // Contraseña
                "1992",             // Año
                "10",               // Mes
                "20",               // Día
                "Melo",             // Ciudad
                "Av. 18 de Julio",  // Calle
                "456",              // Número de puerta

                // Usuario 5
                "a", 
                "a",                // Opción 'a' seleccionada: Dar de alta a un usuario.
                "a",                // Tecla para seleccionar 'a' (cliente).
                "laura",            // Nickname
                "3edc4rfv",         // Contraseña
                "1979",             // Año
                "09",               // Mes
                "22",               // Día
                "Montevideo",       // Ciudad
                "Rondeau",          // Calle
                "1617",             // Número de puerta

                // Usuario 6
                "a", 
                "a",                // Opción 'a' seleccionada: Dar de alta a un usuario.
                "v",                // Tecla para seleccionar 'v' (vendedor).
                "maria01",          // Nickname
                "5tgb6yhn",         // Contraseña
                "1985",             // Año
                "03",               // Mes
                "25",               // Día
                "321098765432",     // RUT

                // Usuario 7
                "a", 
                "a",                // Opción 'a' seleccionada: Dar de alta a un usuario.
                "a",                // Tecla para seleccionar 'a' (cliente).
                "natalia",          // Nickname
                "poiuyt",           // Contraseña
                "1982",             // Año
                "04",               // Mes
                "14",               // Día
                "Salto",            // Ciudad
                "Paysandú",         // Calle
                "2021",             // Número de puerta

                // Usuario 8
                "a", 
                "a",                // Opción 'a' seleccionada: Dar de alta a un usuario.
                "a",                // Tecla para seleccionar 'a' (cliente).
                "pablo10",          // Nickname
                "lkjhgv",           // Contraseña
                "1995",             // Año
                "11",               // Mes
                "30",               // Día
                "Mercedes",         // Ciudad
                "Av. Rivera",       // Calle
                "1819",             // Número de puerta

                // Usuario 9
                "a", 
                "a",                // Opción 'a' seleccionada: Dar de alta a un usuario.
                "a",                // Tecla para seleccionar 'a' (cliente).
                "roberto",          // Nickname
                "mnbvcx",           // Contraseña
                "1990",             // Año
                "08",               // Mes
                "12",               // Día
                "Montevideo",       // Ciudad
                "Av. Brasil",       // Calle
                "1011",             // Número de puerta

                // Usuario 10
                "a", 
                "a",                // Opción 'a' seleccionada: Dar de alta a un usuario.
                "v",                // Tecla para seleccionar 'v' (vendedor).
                "sofia25",          // Nickname
                "1234asdf",         // Contraseña
                "1983",             // Año
                "12",               // Mes
                "07",               // Día
                "445678901234"      // RUT
            };
        break;}
        case 'x':{
            break;}
        default:{
            break;}
        }
    break;}
    case 'x':{
            printf("\nOpción 'x' seleccionada: Salir del programa.\n");
            e=false;
            break;}
    default:{
            break;}
    }
    }
}