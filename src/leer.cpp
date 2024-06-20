#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
#include <vector>
#include "leer.h"

std::vector<std::string> simulatedInputs;
unsigned int inputIndex = 0;  // Cambiado a unsigned int

char leerUnaTecla() {
    // Si todavía hay entradas simuladas disponibles
    if (inputIndex < simulatedInputs.size()) {
        std::string entrada = simulatedInputs[inputIndex++];
        return entrada[0]; // Devolvemos la primera letra de la entrada simulada
    } else {
        return _getch(); // Leer una tecla desde la entrada estándar
    }
}

int leerEntero() {
    if (inputIndex < simulatedInputs.size()) {
        std::string entrada = simulatedInputs[inputIndex++];
        
        // Intentar convertir la entrada a entero
        try {
            return std::stoi(entrada);
        } catch (const std::invalid_argument&) {
            std::cerr << "Error: Entrada no válida para entero: " << entrada << std::endl;
            throw;
        } catch (const std::out_of_range&) {
            std::cerr << "Error: Entrada fuera de rango para entero: " << entrada << std::endl;
            throw;
        }
    } else {
        std::string entrada;
        int numero;

        while (true) {
            std::getline(std::cin, entrada);

            std::istringstream flujoEntrada(entrada);

            if (flujoEntrada >> numero) {
                char resto;
                if (!(flujoEntrada >> resto)) {
                    return numero;
                }
            }
            std::cout << "Entrada no válida. Intente de nuevo." << std::endl;
        }
    }
}

std::string leerCadena() {
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
