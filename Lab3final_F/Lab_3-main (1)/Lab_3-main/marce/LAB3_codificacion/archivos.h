#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <iostream>
#include <fstream> //libreria de strings
#include <string>

using namespace std;

void crear_txt(string name);
void escribir(string texto, string name, bool modo);
string leer (string name, bool modo);

//string m2 (string pedazo);

#endif // ARCHIVOS_H



