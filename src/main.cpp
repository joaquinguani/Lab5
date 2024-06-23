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
#include "ContProducto.h"
#include "ContUsuario.h"
#include "TFecha.h"
#include "Producto.h"
#include "TFechaActual.h"
#include "Fabrica.h"

int main(){
//asigno cosas iniciales, creo controladores e interfaces, agrego colecciones (diccionarios e interfaces)


std::map<std::string,Vendedor *> vendedores;
  //std::map<std::string,Cliente *> clientes;
std::map<std::string,Vendedor *>::iterator iter;

//con fabrica
Fabrica* fabrica = Fabrica::getInstancia();
IContUsuario* contUsu = fabrica->getIContUsuario();
IContProducto* contProdu = fabrica->getIContProducto();


//ContUsuario* contUsu = ContUsuario::getInstanciaContUsu();
//ContProducto* contProdu = ContProducto::getInstanciaContProd();
//TFechaActual* fechaSist= TFechaActual::getInstanciaFecha();

TFechaActual* fechaSist = TFechaActual::getInstanciaFecha(); //la instancia de fecha actual

std::string nick;
std::string Contrasena;
TFecha* fecha;
int codigoProducto = 0;
bool booleano = true;//booleano para hacer cualquiera
bool e = true;

while(e) {
    std::system("cls");
    printf("      **MERCADO FING**\n");
    printf("            //MENU//\n\n");
    int TamañoColUsuarios = contUsu->sizeCol();
    printf("Cantidad usuarios: %d -----> C: %d,  V: %d (falta contar vendedor y cliete por separado)\n\n", TamañoColUsuarios, TamañoColUsuarios, TamañoColUsuarios);
    printf("¨Presione:\n");
    printf("a: para acceder a los casos de uso\n");
    printf("b: para acceder a los casos de prueba predeterminados\n");
    printf("x: para salir\n");

    char tec = leerUnaTecla();
    switch(tec) {
    case 'a':{
    std::system("cls");
    printf(" --CASOS DE USO--\n\n");
    printf("Presione:\n\n");
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
    printf("x: para salir\n");

    char tecla = leerUnaTecla();
    
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
            if (!contUsu->estaUsuario(nick)){
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
                contUsu->ingresarDatosCliente(*data);
            } else{
                printf("\nIngresar RUT de vendedor\n");
                std::string RUT = leerCadena();
                std::system("cls");
                DataVendedor* data = new DataVendedor(nick,Contrasena,*fecha,RUT);
                contUsu->ingresarDatosVendedor(*data);
            }
            break;
        }
        case 'b':{
            std::system("cls");
            printf("\nListado de usuarios:\n");
            contUsu->imprimirUsuarios();
            printf("\nPresione cualquier tecla para ir al menu\n");
            leerUnaTecla();
            break;
        }
        case 'c':{
            printf("\nOpción 'c' seleccionada: Alta de producto.\n");
            contUsu->imprimirVendedores();//detalle
            printf("\nIngrese el nickname del vendedor que desea seleccionar.\n");
            std::string nickVend = leerCadena();
            std::map<std::string,Vendedor *>::iterator iter; 
            if (contUsu->findVend(nickVend) == NULL) {
                printf("\nError: No existe un vendedor con dicho nickname\n");
            } else {
                char catProd = 'z';
                printf("\nIngrese el nombre del producto:\n");
                std::string nomProd = leerCadena();
                printf("\nIngrese el precio del producto:\n");
                int precioProd = leerEntero();
                printf("\nIngrese la cantidad en stock del producto:\n");
                int stockProd = leerEntero();
                printf("\nIngrese la descripcion del producto:\n");
                std::string descProd = leerCadena();
                while (catProd != 'c' && catProd != 'b' && catProd != 'a'){
                    printf("\nPresione la tecla correspondiente a la categoria es ropa, electrodomesticos, otros:\n");
                    printf("\na: ropa\nb: electrodomestrico\nc: otros");
                    catProd = leerUnaTecla();
                }
                Producto* nuevoProd = new Producto(stockProd, precioProd, nomProd, descProd, catProd);
                Vendedor* vend=contUsu->buscarVendPorNombre(nickVend);
                vend->agregarProducto(nuevoProd);
                nuevoProd->asociarVendedor(vend);
                contProdu->insertarProducto(nuevoProd);
            }
            break;
        } 
            case 'd':{ 
            printf("\nOpción 'd' seleccionada: Consultar producto.\n");
            contProdu->listarProductos();
            printf("\nIngrese el codigo del producto a seleccionar:\n");
            Producto* prod = NULL;
            while (prod != NULL){
                int codProd = leerEntero();
                prod = contProdu->find(codProd);
            }
            prod->imprimirProducto();
            break;
        }
        case 'e':{
            printf("\nOpción 'e' seleccionada: Crear promoción.\n");
            std::string nom;
            std::cout << "Ingrese el nombre de la promoción: ";
            nom=leerCadena(); 
            std::string descrip;
            std::cout << "Ingrese la descripción de la promoción: ";
            descrip=leerCadena();
            printf("\nIngresar anio de nacimiento de usuario\n");
            int a = leerEntero();
            printf("\nIngresar mes de nacimiento de usuario\n");
            int m = leerEntero();
            printf("\nIngresar dia de nacimiento de usuario\n");
            int d = leerEntero();
            TFecha* fech=new TFecha(d,m,a);
            int descu;
            std::cout << "Ingrese el porcentaje de descuento que se va a aplicar en la promocion ";
            descu=leerEntero();
            contUsu->imprimirVendedores();
            printf("\nIngrese el nombre del vendedor al que quiere asignar la promocion.\n");
            std::string vend;
            vend=leerCadena();
            Vendedor* vnd=contUsu->buscarVendPorNombre(vend);
            vnd->imprimirProdsVendedorCodNom();
            Promocion* p=new Promocion(nom,descrip,fech,descu); //creamos la promo y ahora pedimos que liste por codigo los productos a agregar
            vnd->agregarPromocion(p);
            p->asociarVendedor(vnd);
            bool seguir=true;
            while(seguir){
                printf("\nIngrese el codigo de un producto que desea agregar a la promocion.\n");
                int c=leerEntero();
                Producto* prod=contProdu->buscarProducto(c);
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
                seguir = !(respuesta == 'n' || respuesta == 'N');
            };
            contProdu->agregarPromocion(p);
            TNotificacion* notificacion=new TNotificacion(vend,p->getNombre(),p->getProductos());
            vnd->notificarClientes(notificacion);
            break;
        }
        case 'f':{
           printf("\nOpción 'f' seleccionada: Consultar promoción.\n");
            contProdu->listarPromosVigentes();
            printf("\nSi desea seleccionar una promoción ingrese 's', de lo contrario ingrese 'n'");
            char tec=leerUnaTecla();
            if(tec == 's' || tec == 'S'){
                printf("\nIngrese el nombre la promocion\n");
                std::string nom = leerCadena();
                Promocion* promo = contProdu->buscarPromoPorNombre(nom);
                promo->devolverDatosProdsPromo();
            }
            break;
        }
        case 'g': {
            printf("\nOpción 'g' seleccionada: Realizar compra.\n");
            contUsu->imprimirClientes();//detalle
            printf("\nIngrese el nickname del cliente que desea seleccionar.\n");
            std::string nickCliente = leerCadena();
            auto iterC = contUsu->getColClientes().find(nickCliente);
            if (iterC == contUsu->getColClientes().end()) {
                printf("\nError: No existe un cliente con dicho nickname\n");
            } else {
                static int idCompra = 0;
                Compra* compra = new Compra(fechaSist, 0, ++idCompra);
                contProdu->listarProductosDisp(); 
                printf("\nIngrese 0 si desea agregar productos a la compra, de lo contrario ingrese otro numero\n");
                int agregar = leerEntero();
                std::map<int, CompraProd*> comprasPro; //se busca por el codigo del producto que tiene
                while (agregar == 0){
                    printf("\nIngrese el codigo del producto a agregar\n");
                    int codP = leerEntero();
                    auto iterProd = contProdu->getColProductos().find(codP);
                    if (iterProd == contProdu->getColProductos().end()) {
                        printf("\nError: No existe un producto con dicho codigo\n");
                    } else {
                        if (comprasPro.find(codP) != comprasPro.end()){ 
                            printf("\nEste producto ya fue ingresado\n");
                        } else {
                            printf("\nIngrese la cantidad que desea comprar\n");
                            int cantP = leerEntero();
                            if (cantP <= iterProd->second->getStock()) {
                                CompraProd* compraP = new CompraProd(cantP, false, iterProd->second);
                                comprasPro[codP]= compraP; 
                                iterProd->second->ingresarCompraProd(compraP); 
                                compra->asociarCompraProd(compraP, codP); 
                                compraP->setCompraAsociada(compra); 
                                int precio = iterProd->second->getPrecio();
                                precio = compra->aplicarDescuento(precio, cantP, codP, iterProd->second);
                                compra->sumarAlMonto(precio);
                                iterProd->second->setStock(iterProd->second->getStock()-cantP); //actualizo el stock del producto
                            } else {
                                printf("/nError: Cantidad ingresada menor a cantidad en stock/n");
                            }
                        }
                    }
                    printf("\nIngrese 0 si desea agregar mas productos a la compra, de lo contrario ingrese otro numero\n");
                    agregar = leerEntero();
                }
                compra->imprimirCompraCompleto();
                printf("/nPresiona 0 para confirmar la compra/n");
                int a = leerEntero();
                if (a == 0) {
                    Cliente* cli=contUsu->buscarClientePorNombre(nickCliente);
                    compra->asociarCliente(cli);
                    iterC->second->agregarCompra(compra); //asocio el cliente con la compra
                } 
            }
            break;
        }
        case 'h':{
            printf("\nOpción 'h' seleccionada: Dejar comentario.\n");
            printf("\nIngrese el nickname del usuario que desea seleccionar\n");
            contUsu->imprimirUsuarios();
            std::string nickUsuario = leerCadena();
            Usuario* usu = contUsu->find(nickUsuario);
            if (!contUsu->estaUsuario(nickUsuario)) {
                printf("\nError: No existe un usuario con dicho nickname\n");
            } else {
              printf("\nAhora ingrese el codigo identificador del producto que desea seleccionar\n");
              contProdu->listarProductos();//implementar
              int codigoProd = leerEntero();
              Producto* prod = contProdu->find(codigoProd);
              if (!contProdu->estaProd(codigoProd)) {
                    printf("\nError: No existe un producto con dicho codigo\n");
                } else {
                    printf("\n¿Desea hacer un comentario nuevo (N) o una respuesta (R)?\n");
                    char tipoComentario;
                    tipoComentario=leerUnaTecla();
                    if (tipoComentario == 'N' || tipoComentario == 'n') {
                        printf("\nIngrese el texto de su comentario:\n");
                        std::string textoComentario = leerCadena();
                        prod->crearComentario(textoComentario, usu);
                        printf("\nComentario agregado exitosamente.\n");
                    } else if (tipoComentario == 'R' || tipoComentario == 'r') {
                        printf("\nComentarios del producto:\n");
                        prod->imprimirComDeProd(); 
                        printf("\nElija el ID del comentario al que desea responder:\n");
                        int IDComentario = leerEntero();
                        if (prod->estaComen(IDComentario)) {
                            printf("\nIngrese el texto de su respuesta:\n");
                            std::string textoRespuesta = leerCadena();
                            Comentario* comenPadre = contUsu->findComen(IDComentario);
                            comenPadre->CrearHijo(textoRespuesta, usu); 
                        }
                    }
                }
            }
            break;}
        case 'i':{
            printf("\nOpción 'i' seleccionada: Eliminar comentario.\n");
            contUsu->imprimirUsuarios();
            printf("\nEscriba el nickName del usuario correspondiente al comentario a elminar\n");
            std::string nick = leerCadena();
            Usuario* usu = contUsu->find(nick);
            usu->imprimirComentarios();
            printf("\nEscribe el ID del comentario a elminar (se eliminaran todas sus respuestas)\n");
            int ID = leerEntero();
            Comentario* comen = contUsu->findComen(ID);
            bool tienePadre = comen->getTieneComPadre();
            if (tienePadre){
                Comentario* comPadre = comen->getComPadre();
                comPadre->eliminarRefCom(ID);
            }
            else {
                Producto* prod = comen->getProducto();
                prod->eliminarRefComen(ID);
            }
            comen->EliminoComentarioYHijos();
        }
            break;
        case 'j':
            printf("\nOpción 'j' seleccionada: Enviar producto.\n");
            contUsu->imprimirVendedores(); //solo los nicknames
            printf("\nIngrese el nombre del vendedor que quiere seleccionar\n");
            std::string vend;
            std::cin.ignore();
            std::getline(std::cin, vend);   
            Vendedor* vnd=contUsu->buscarVendPorNombre(vend);
            vnd->imprimirProdsConCompraPendDeEnvio();
            printf("\nIngrese el codigo del producto que quiere seleccionar\n");
            int prod = leerEntero();
            Producto* produ = contProdu->buscarProducto(prod); 
            contProdu->imprimirComprasConProdPendiente(produ);
            printf("\nIngrese el id de la compra que quiere seleccionar\n");
            int id=leerEntero();
            produ->findCompraProd(id)->setEnviado(true);
            break;
        case 'k': {
            printf("\nOpción 'k' seleccionada: Expediente de Usuario.\n");
            contUsu->imprimirUsuarios(); // Imprimir todos los usuarios
            printf("\nIngrese el nombre del usuario que quiere seleccionar\n");
            std::string nick;
            nick=leerCadena();
            Usuario* usr = contUsu->buscarPorNombre(nick);
            if (usr == nullptr) {
                printf("Error: No existe un usuario con ese nombre.\n");
                break;
            }
            printf("Información básica del usuario:\n");
            printf("Nickname: %s\n", usr->getNickname());
            usr->imprimirFecha(); // info basica: nickname y fecha. sin contraseña ciudad ni nada de eso
            if (usr->esVendedor()) {
                Vendedor* vendedor = dynamic_cast<Vendedor*>(usr);
                printf("El usuario es un vendedor.\n");
                printf("Productos en venta:\n");
                vendedor->listarProductosEnVenta();
                printf("Promociones vigentes:\n");
                vendedor->listarPromocionesVigentes();
            } else {
                Cliente* cliente = dynamic_cast<Cliente*>(usr);
                printf("El usuario es un cliente.\n");
                printf("Compras realizadas:\n");
                cliente->listarComprasRealizadas();
            }
            break;
        }
        case 'l':
            printf("\nOpción 'l' seleccionada: Suscribirse a notificaciones.\n");
            printf("\nIngrese el nombre del Cliente que quiere seleccionar\n");
            std::string cli=leerCadena();
            //buscar el cliente y obtenerlo para usarlo de parametro
            Cliente* cliente=contUsu->buscarClientePorNombre(cli);
            //el Sistema devuelve la lista de todos los vendedores a los que no está suscrito el cliente
            contUsu->listarVendedoresNoSubsXCliente(cliente);
            bool seguir=true;
            while(seguir){
                printf("\nIngrese el nickname del vendedor al que desea suscribirse.\n");
                std::string c=leerCadena();
                Vendedor* vnd=contUsu->buscarVendPorNombre(c);
                cliente->agregarSuscripcion(vnd);
                vnd->agregarSuscriptor(cliente);
                printf("\n¿Desea agregar otra suscripcion? (s/n): .\n");
                char respuesta;
                respuesta=leerUnaTecla();
                seguir = (respuesta == 's' || respuesta == 'S');
            };
            break;
        case 'm':{
            printf("\nOpción 'm' seleccionada: Consulta de notificaciones.\n");
            printf("\nIngrese el nombre del Cliente que quiere seleccionar\n");
            std::string cli=leerCadena();
            Cliente* cliente = dynamic_cast<Cliente*>(contUsu->buscarPorNombre(cli));
            if (cliente == nullptr) {
                printf("Error: No existe un cliente con ese nombre.\n");
                break;
            }
            // Consultar y listar notificaciones del cliente
            cliente->consultarNotificaciones();
            break;
        };
        case 'n':
            printf("\nOpción 'n' seleccionada: Eliminar suscripciones.\n");

            printf("\nIngrese el nombre del Cliente que quiere seleccionar\n");
            std::string cli=leerCadena();
            Cliente* cliente = dynamic_cast<Cliente*>(contUsu->buscarPorNombre(cli));
            contUsu->listarVendSuscripto(cliente);
            bool seguir=true;
            while(seguir){
                printf("\nIngrese el nickname del vendedor al que desea desuscribirse.\n");
                std::string c=leerCadena();
                Vendedor* vnd=contUsu->buscarVendPorNombre(c);
                cliente->eliminarSuscripcion(vnd);
                vnd->eliminarSuscriptor(cliente);
                printf("\n¿Desea eliminar otra suscripcion? (s/n): .\n");
                char respuesta;
                respuesta=leerUnaTecla();
                seguir = (respuesta == 's' || respuesta == 'S');
            };
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
        case 'x':{
            break;
        }
        default:{
            //esto no esta bien, hay que hacer que se mantenga en el switch con otro bool
            printf("\nTecla no válida. Por favor, seleccione una opción válida.\n");
            break;
        }
    }
    break;}
    case 'b':{
        std::system("cls");
        printf(" --CASOS DE PRUEBA--\n\n");
        printf("presione:\n\n");
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