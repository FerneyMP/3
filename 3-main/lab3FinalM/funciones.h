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

bool ValidarDigitos (string numero , bool met);
void validar(string &NUM, short int modo);

//Cajero
bool EncontrarSaldo(string sald_, unsigned long long int pos);
#endif // FUNCIONES_H
