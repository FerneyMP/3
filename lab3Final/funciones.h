#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void leer_menu();


void crear_txt(string name);
void escribir(string texto, string name, bool modo);
string leer (string name, bool modo);
void escribirCajero(string texto, string nombre, bool modo);

#endif // FUNCIONES_H
