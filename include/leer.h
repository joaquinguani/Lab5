#ifndef LEER_H
#define LEER_H

#include <string>
#include <vector> // Asegúrate de incluir la biblioteca <vector>

extern std::vector<std::string> simulatedInputs;
extern unsigned int inputIndex;  // Cambiado a unsigned int

char leerUnaTecla();
int leerEntero();
std::string leerCadena( );

#endif