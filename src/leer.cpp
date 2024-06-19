#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
#include <vector>
#include "leer.h"


// Función para leer una sola tecla sin presionar Enter en Unix/Linux
char leerUnaTecla() {
    return _getch();  // Leer una tecla
}



int leerEntero() {
    std::string entrada;
    int numero;

        while (true) {
            std::getline(std::cin, entrada);

            std::istringstream flujoEntrada(entrada);

        // Intentar extraer el número entero
        if (flujoEntrada >> numero) {
            // Asegurarse de que no haya caracteres adicionales después del número
            char resto;
            if (!(flujoEntrada >> resto)) {
                return numero;  // Entrada válida, retornar el número
            }
        }

        // Si la entrada es inválida, mostrar un mensaje de error
        std::cout << "Entrada no válida. Intente de nuevo." << std::endl;
    }
}

// Función para leer una cadena
std::string leerCadena() {
    std::string entrada;

        while (true) {
            std::getline(std::cin, entrada);

            if (!entrada.empty()) {
                return entrada; // Entrada válida
            }

            std::cout << "Entrada no válida. Intente de nuevo." << std::endl;
        }
    }

