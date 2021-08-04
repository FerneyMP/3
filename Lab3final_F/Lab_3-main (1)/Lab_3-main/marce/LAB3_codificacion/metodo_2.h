#ifndef METODO_2_H
#define METODO_2_H

#include "archivos.h"

bool codificacion(int semilla, string nombre, string nombre2); // funcion general para el metodo dos (ejecuta todo) (string)
string conversionTEXT_BIN(string texto); //texto a binario
string conversionINT_BIN(int letra); //entero a binario
string reglas(string binario, int semilla);
string m2(string pedazo);
string binario_a_texto(string binario);
char conv_letra(string pedazo);

#endif // METODO_2_H
