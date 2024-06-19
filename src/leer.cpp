#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
#include <vector>
#include "leer.h"


char leerUnaTecla(std::vector<std::string> simulatedInputs, int inputIndex) {
    // Si todavía hay entradas simuladas disponibles
    if (inputIndex < simulatedInputs.size()) {
        std::string entrada = simulatedInputs[inputIndex++];
        return entrada[0]; // Devolvemos la primera letra de la entrada simulada
    } else {
        return _getch(); // Leer una tecla desde la entrada estándar
    }
}

int leerEntero(std::vector<std::string> simulatedInputs, int inputIndex) {
    if (inputIndex < simulatedInputs.size()) {
        std::string entrada = simulatedInputs[inputIndex++];
        return std::stoi(entrada); // Convertir la entrada simulada a entero
    } else {
        std::string entrada;
        int numero;

        while (true) {
            std::getline(std::cin, entrada);

            std::istringstream flujoEntrada(entrada);

            if (flujoEntrada >> numero) {
                char resto;
                if (!(flujoEntrada >> resto)) {
                    return numero; // Entrada válida
                }
            }
            std::cout << "Entrada no válida. Intente de nuevo." << std::endl;
        }
    }
}

std::string leerCadena(std::vector<std::string> simulatedInputs, int inputIndex) {
    if (inputIndex < simulatedInputs.size()) {
        return simulatedInputs[inputIndex++]; // Devolver la entrada simulada
    } else {
        std::string entrada;

        while (true) {
            std::getline(std::cin, entrada);

            if (!entrada.empty()) {
                return entrada; // Entrada válida
            }

            std::cout << "Entrada no válida. Intente de nuevo." << std::endl;
        }
    }
}
